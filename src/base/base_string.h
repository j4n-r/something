#ifndef BASE_STRING
#define BASE_STRING

// UTF-8 string slice, treat them as immutable
typedef struct {
    u8 *str;
    u64 size;   // number of bytes
} String8;

typedef String8 CString8; // null terminated

typedef struct {
    u8 chr[4];
    u8 size;
} Char8;

String8 Str8New(u8 *str, u64 size);
String8 Str8FromLiteral(Arena *arena, char *str);
String8 Str8Concat(Arena *arena, String8 str, String8 str_to_concat); 
String8 Str8GetCharByIndex(String8 str, u64 idx);
String8 Str8Slice(String8 str, u64 start_idx, u64 end_idx);
String8 Str8Append(Arena *arena, String8 str, String8 str_to_append);

Char8 Char8FromBytes(u8 *bytes);

CString8 Str8ToCString(String8 str); 

void PrintChar8(Char8 *chr);

#endif // BASE_STRING
