#include "../base/base_inc.h"
#include "../base/base_inc.c"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
struct termios orig_termios;

void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}
void enableRawMode() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disableRawMode);
    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}
int main(void) {
    enableRawMode();

    Arena *kilo_arena = ArenaAlloc();
    u8 *buf = ArenaPush(kilo_arena, 5);
    buf[4] = '\0';

    while (read(STDIN_FILENO, buf, 4) > 0) {
        if (iscntrl(buf[0])) {

        }
        if (buf[0] == 'q') {
            break;
        }
        else {
            printf("%s",buf);
        }
            printf("\n");
    }

    perror("read");
    return 0;
}
