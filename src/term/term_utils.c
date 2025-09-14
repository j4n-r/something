void TERM_disableRawMode(struct termios *orig_termios) {
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, orig_termios) == -1)
        OS_PANIC("tcsetattr");
    }

/*
 * Enable "raw mode" on the terminal by disabling or adjusting certain termios flags.
 *
 * Input flags (c_iflag):
 *   - BRKINT : disable break condition from sending SIGINT
 *   - ICRNL  : disable CR -> NL translation (Enter sends '\r' instead of '\n')
 *   - INPCK  : disable input parity checking (legacy, rarely needed)
 *   - ISTRIP : disable stripping of 8th bit (preserve full 8-bit input)
 *   - IXON   : disable software flow control (Ctrl-S/Ctrl-Q)
 *
 * Output flags (c_oflag):
 *   - OPOST  : disable post-processing of output (e.g., '\n' -> '\r\n')
 *
 * Control flags (c_cflag):
 *   - CS8    : set character size to 8 bits per byte
 *
 * Local flags (c_lflag):
 *   - ECHO   : disable echoing of typed characters
 *   - ICANON : disable canonical (line-buffered) mode
 *   - IEXTEN : disable implementation-defined input processing (e.g., Ctrl-V)
 *   - ISIG   : disable signal generation (e.g., Ctrl-C, Ctrl-Z)
 *
 * Control characters (c_cc):
 *   - VMIN   : minimum number of bytes before read() returns (0 = return immediately)
 *   - VTIME  : timeout (in tenths of a second) for read() when VMIN = 0
 *
 * Result:
 *   Input is made available byte-by-byte, without line buffering,
 *   echoing, or signal handling. This is the classic "raw mode"
 *   used by full-screen terminal programs (e.g., text editors).
 */

void TERM_enableRawMode(struct termios *orig_termios) {

    if (tcgetattr(STDIN_FILENO, orig_termios) == -1) {
        OS_PANIC("tcsetattr");
    }

    orig_termios->c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    orig_termios->c_oflag &= ~(OPOST);
    orig_termios->c_cflag |= (CS8);
    orig_termios->c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
    orig_termios->c_cc[VMIN] = 0;
    orig_termios->c_cc[VTIME] = 5;
    
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, orig_termios) == -1) {
        OS_PANIC("tcsetattr");
    }
}



bool TERM_IsCtrlCombination(Char8 key, u8 letter) {
    return key.chr[0] == (letter & 0x1F);
}
