
Char8 EDT_readKey(EDT_Config *e_conf) {
    for (;;) {
        u8 buf[4] = {0};
        i64 n;

        n = read(STDIN_FILENO, buf, 4);

        if (n == 0) {
           continue;
        }
        if (n == -1) {
            write(STDOUT_FILENO, "\x1b[2J", 4);
            write(STDOUT_FILENO, "\x1b[H", 3);
            OS_PANIC("read");
        }
        Char8 c = Char8FromBytes(buf);;
        return c;

    }
}

void EDT_processKey(Char8 c) {
    if (c.chr[0] != '\0') {
        Char8Print(&c);
        fflush(stdout);
    }
    if (TERM_IsCtrlCombination(c, 'q')) {
        write(STDOUT_FILENO, "\x1b[2J", 4);
        write(STDOUT_FILENO, "\x1b[H", 3);
        exit(0);
    }

}
