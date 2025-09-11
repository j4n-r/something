static EDT_Config e_conf   = {0}; // they should be zeroed out anyways
static String8    term_buf = {0};

void start_edits(void) {
    Arena *perm_edits_arena = ArenaAlloc();

    e_conf.logfile_path = STR8_LIT("edits_log.txt");
    String8 term_buf = {0};
    term_buf.str = (u8*) ArenaPush(perm_edits_arena,10000);

    TERM_enableRawMode(&e_conf.orig_termios);
    TERM_getWindowSize(&e_conf.screen_rows, &e_conf.screen_cols);

    Arena *frame_arena = ArenaAlloc();

    EDT_debugEConfToLogFile(&e_conf);
    for (;;) {
        EDT_refreshScreen(frame_arena, &term_buf);
        EDT_KeyResult result = EDT_readKey(&e_conf);
        EDT_processKey(result);
        ArenaClear(frame_arena);
    }
}

