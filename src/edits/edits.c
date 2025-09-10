
void start_edits(void) {
    Arena *perm_edits_arena = ArenaAlloc();
    EDT_Config *e_conf = (EDT_Config*) ArenaPush(perm_edits_arena, sizeof(EDT_Config));
    String8 term_buf = {0};
    term_buf.str = (u8*) ArenaPush(perm_edits_arena,10000);

    TERM_enableRawMode(&e_conf->orig_termios);
    TERM_getWindowSize(&e_conf->screen_rows, &e_conf->screen_cols);

    for (;;) {
        EDT_refreshScreen(e_conf);
        Char8 c = EDT_readKey(e_conf);
        EDT_processKey(c);
    }
}

