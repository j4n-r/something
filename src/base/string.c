#include "string.h"

String8 Str8(u8 *str, u64 size) {
    String8 string = {0};
    string.str = str;
    string.size = size;
    return string;
}

Char8 Char8FromBytes(u8 *bytes) {
    Char8 chr = {0};
    chr.str = bytes;
    if ((bytes[0] & 0x80) == 0x00) {
        chr.size = 1; 
    } else if ((bytes[0] & 0xE0) == 0xC0 &&
               (bytes[1] & 0xC0) == 0x80)
    {
        chr.size = 2;
    } else if ((bytes[0] & 0xF0) == 0xE0 &&
               (bytes[1] & 0xC0) == 0x80 &&
               (bytes[2] & 0xC0) == 0x80)
    {
        chr.size = 3;
    } else if ((bytes[0] & 0xF8) == 0xF0 &&
               (bytes[1] & 0xC0) == 0x80 &&
               (bytes[2] & 0xC0) == 0x80 &&
               (bytes[3] & 0xC0) == 0x80)
    { 
        chr.size = 4;
    } else {
        printf("Not a valid UTF-8 Char");
        exit(1);
    }
    return chr;
}

void Char8Print(Char8 *chr) {
    printf("%.*s", (int)chr->size, chr->str);
}

/* String8 Char8SliceFromLiteral(char *str) { */
/*     Char8 result = {0}; */
/*     result.size = strlen(str)-1;  */
/*     result.str = str; */
/*     return result;  */
/* }  */

String8 Str8FromLiteral(Arena *arena, char *str) {
    String8 result = {0};
    result.size = strlen(str)-1;
    result.str = ArenaPush(arena, strlen(str));
    memcpy(result.str, str, strlen(str));
    return result;
    
}


String8 Str8Concat(Arena *arena, String8 str, String8 str_to_concat) {
    u64 size = str.size + str_to_concat.size;
    String8 result = {0};
    result.str = ArenaPush(arena, size + 1);
    memcpy(result.str,str.str, str.size);
    memcpy(result.str + str.size , str_to_concat.str, str.size);

    return result;
}
