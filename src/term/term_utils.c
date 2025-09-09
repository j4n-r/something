#include "term_utils.h"

void TERM_disableRawMode() {
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1)
        OS_PanicFromLit("tcsetattr");
    }

void TERM_enableRawMode() {

    if (tcgetattr(STDIN_FILENO, &orig_termios) == -1) {
        OS_PanicFromLit("tcsetattr");
    }
    atexit(TERM_disableRawMode);

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


bool TERM_IsCtrlCombination(Char8 key, u8 letter) {
    return key.str[0] == (letter & 0x1F);
}
