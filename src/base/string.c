#include "string.h"

String8 Str8(u8 *str, u64 size) {
    String8 string = {0};
    string.str = str;
    string.size = size;
    return string;
  
}

String8 Str8Concat(Arena *arena, String8 str, String8 str_to_concat) {
    u64 size = str.size + str_to_concat.size;
    String8 result = {0};
    result.str = ArenaPush(arena, size + 1);
    memcpy(result.str,str.str, str.size);
    memcpy(result.str + str.size , str_to_concat.str, str.size);

    return result;
}

String8 Str8FromLiteral(Arena *arena, char *str) {
    String8 result = {0};
    result.size = strlen(str)-1;
    result.str = ArenaPush(arena, strlen(str));
    memcpy(result.str, str, strlen(str));
    return result;
    
}
