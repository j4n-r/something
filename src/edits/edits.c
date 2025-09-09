void start_edits(void) {
    Arena *perm_edits_arena = ArenaAlloc();
    EditsConfig *e_conf = (EditsConfig*) ArenaPush(perm_edits_arena, sizeof(EditsConfig));

    TERM_enableRawMode(&e_conf->orig_termios);
    TERM_getWindowSize(&e_conf->screen_rows, &e_conf->screen_cols);

    EDT_editorReadKey(e_conf);
}
