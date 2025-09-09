void EDT_cleanupPanicFromLit(termios *orig_termios, char *str) {
    TERM_disableRawMode(orig_termios);
    OS_PANIC("EDT_cleanupPanicFromLit");
}
