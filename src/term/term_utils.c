void TERM_disableRawMode(struct termios *orig_termios) {
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, orig_termios) == -1)
        OS_PANIC("tcsetattr");
    }

void TERM_enableRawMode(struct termios *orig_termios) {

    if (tcgetattr(STDIN_FILENO, orig_termios) == -1) {
        OS_PANIC("tcsetattr");
    }

    orig_termios->c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    orig_termios->c_oflag &= ~(OPOST);
    orig_termios->c_cflag |= (CS8);
    orig_termios->c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
    orig_termios->c_cc[VMIN] = 0;
    orig_termios->c_cc[VTIME] = 1;
    
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, orig_termios) == -1) {
        OS_PANIC("tcsetattr");
    }
}


bool TERM_IsCtrlCombination(Char8 key, u8 letter) {
    return key.str[0] == (letter & 0x1F);
}
