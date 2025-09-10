
void EDT_drawRows(EDT_Config *e_conf) {
  for (u32 y = 0; y < e_conf->screen_rows; y++) {
    write(STDOUT_FILENO, "~\r\n", 3);
  }
}


void EDT_refreshScreen(EDT_Config *e_conf) {
    TERM_clearScreen();
    TERM_moveCursorTopLeft();

    EDT_drawRows(e_conf);

    TERM_moveCursorTopLeft();
}
