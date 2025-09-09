
void EDT_editorDrawRows(EditsConfig *e_conf) {
  for (u32 y = 0; y < e_conf->screen_rows; y++) {
    write(STDOUT_FILENO, "~\r\n", 3);
  }
}


void EDT_editorRefreshScreen(EditsConfig *e_conf) {
    TERM_clearScreen();
    TERM_moveCursorTopLeft();

    EDT_editorDrawRows(e_conf);

    TERM_moveCursorTopLeft();
}
