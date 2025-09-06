#ifndef BASE_STRING
#define BASE_STRING

// UTF-8 String
typedef struct {
    u8 *str;
    u64 size; // number of chars, not number of bytes
} String8;

typedef struct {
    u8 *str;
    u64 bytes;      // number of utf-8 bytes
} Char8;

// null terminated String8
typedef struct {
    u8 *str;
    u64 size;
} CString8;




String8 Str8New(u8 *str, u64 size);
String8 Str8FromLiteral(Arena *arena, char *str);
String8 Str8Concat(Arena *arena, String8 str, String8 str_to_concat); 
String8 Str8GetCharByIndex(String8 str, u64 idx);
String8 Str8Slice(String8 str, u64 start_idx, u64 end_idx);

Char8 Char8FromBytes(u8 *bytes);

CString8 Str8ToCString(String8 str); 

void PrintChar8

#endif // BASE_STRING
