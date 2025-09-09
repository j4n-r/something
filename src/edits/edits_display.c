
void EDT_editorDrawRows() {
  u32 y;
  for (y = 0; y < e_conf.screen_rows; y++) {
    write(STDOUT_FILENO, "~\r\n", 3);
  }
}


void EDT_editorRefreshScreen() {
    TERM_clearScreen();
    TERM_moveCursorTopLeft();

    EDT_editorDrawRows();

    TERM_moveCursorTopLeft();
}
