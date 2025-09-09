void EDT_editorProcessKey(Char8 c) {
    if (c.str[0] != '\0') {
        Char8Print(&c);
        fflush(stdout);
    }
    if (TERM_IsCtrlCombination(c, 'q')) {
        write(STDOUT_FILENO, "\x1b[2J", 4);
        write(STDOUT_FILENO, "\x1b[H", 3);
        exit(0);
    }

}
Char8 EDT_editorReadKey() {
    Arena *kilo_arena = ArenaAlloc();
    for (;;) {
        EDT_editorRefreshScreen();

        u8 *buf = ArenaPush(kilo_arena, 4);  
        i64 n;

        n = read(STDIN_FILENO, buf, 4);

        if (n == 0) {
           continue;
        }
        if (n == -1) {
            write(STDOUT_FILENO, "\x1b[2J", 4);
            write(STDOUT_FILENO, "\x1b[H", 3);
            OS_PanicFromLit("read");
        }

        Char8 c = Char8FromBytes(buf);
        EDT_editorProcessKey(c);

        ArenaPop(kilo_arena, 5);
    }
}
