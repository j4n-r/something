static EDT_Config e_conf;
static String8    term_buf;

void start_edits(void) {
    Arena *perm_edits_arena = ArenaAlloc();
    e_conf = (EDT_Config) {0};

    e_conf.logfile_path = STR8_LIT("edits_log.txt");
    String8 term_buf = {0};
    term_buf.str = (u8*) ArenaPush(perm_edits_arena,10000);

    TERM_enableRawMode(&e_conf.orig_termios);
    TERM_getWindowSize(&e_conf.screen_rows, &e_conf.screen_cols);

    Arena *frame_arena = ArenaAlloc();

    EDT_debugEConfToLogFile(&e_conf);
    for (;;) {
        EDT_refreshScreen(frame_arena, &e_conf, term_buf);
        Char8 c = EDT_readKey(&e_conf);
        EDT_processKey(c);
    }
}

