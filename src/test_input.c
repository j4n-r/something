#include "base/base_inc.h"
#include "base/base_inc.c"
#include "os/os_inc.h"
#include "os/os_inc.c"
#include "io/io_inc.h"
#include "io/io_inc.c"
#include "term/term_inc.h"
#include "term/term_inc.c"


int main() {
    Arena *test_arena = ArenaAlloc();
    Result_KeyEvent key = TERM_parseTerminalInput(test_arena);
    exit(0);
}

