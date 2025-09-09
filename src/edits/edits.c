void start_edits(void) {
    TERM_enableRawMode();
    TERM_getWindowSize(&e_conf.screen_rows, &e_conf.screen_cols);
     
    EDT_editorReadKey();
}
