#include "base/base_inc.h"
#include "base/base_inc.c"
#include "os/os_inc.h"
#include "os/os_inc.c"
#include "io/io_inc.h"
#include "io/io_inc.c"
#include "term/term_inc.h"
#include "term/term_inc.c"
#include "edits/edits_inc.h"
#include "edits/edits_inc.c"

int main() {
    /* struct termios raw = {0}; */
    /* TERM_enableRawMode(&raw); */
    /* u32 row = 0; */
    /* u32 col = 0; */
    /* TERM_getCursorPosition(&row, &col); */
    /* printf("rows: %u\ncols: %u",row,col); */

    Arena *test_arena = ArenaAlloc();
    String8 str1 = (String8) STR8_LIT( "String1");
    String8 str2 = (String8) STR8_LIT( "String2");
    String8 str3 = Str8Append(test_arena, str1, str2);
    printf("%.*s", str3.size, str3.str);

    ArenaClear(test_arena);

    String8 str4 = Str8Append(test_arena, str1, str2);
    printf("%.*s", str4.size, str4.str);

    

}
