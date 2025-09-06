#include "../base/base_inc.h"
#include "../base/base_inc.c"
#include "../os/error.h"
#include "../os/error.c"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
struct termios orig_termios;

void disableRawMode() {
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1)
        OS_PanicFromLit("tcsetattr");
    }
void enableRawMode() {
    if (tcgetattr(STDIN_FILENO, &orig_termios) == -1) {
        OS_PanicFromLit("tcsetattr");
    }
    atexit(disableRawMode);

    struct termios raw = orig_termios;
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag |= (CS8);
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;
    
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) {
        OS_PanicFromLit("tcsetattr");
    }
}
int main(void) {
    enableRawMode();

    Arena *kilo_arena = ArenaAlloc();
    for (;;) {
        u8 *buf = ArenaPush(kilo_arena, 4);  
        i64 n;

        n = read(STDIN_FILENO, buf, 4);
        if (n == 0) {
            continue;
        }
        if (n == -1) {
            OS_PanicFromLit("read");
        }

        Char8 c = Char8FromBytes(buf); 

        if (c.str[0] != '\0') {
            Char8Print(&c);
            fflush(stdout);
        }
        if (c.str[0] == 'q') {
            exit(0);            // atexit restores termios
        }

        ArenaPop(kilo_arena, 5);
    }

    return 0;
}
