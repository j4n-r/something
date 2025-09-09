void TERM_getCursorPosition(u32 *row, u32 *col) {

    if (write(STDOUT_FILENO, "\x1b[6n", 4) == -1) {
        OS_PanicFromLit("Getting cursor position failed");
  }
    char buf[32] = {0};
    int n = read(STDIN_FILENO, buf, sizeof(buf) - 1);
    buf[n] = '\0';

    if (sscanf(buf, "\x1b[%u;%uR", row,col) == 2) {
        printf("Cursor is at row=%u, col=%u\n", *row, *col);
    } else {
        OS_PanicFromLit("Failes to parse cursor position response");
    }
}


void TERM_getWindowSize(u32 *rows, u32 *cols) {
  struct winsize ws;
  if (1 || ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0) {
      if (write(STDOUT_FILENO, "\x1b[999C\x1b[999B", 12) != 12){
          OS_PanicFromLit("ioctl");
      }
      TERM_getCursorPosition(rows, cols);
  } else {
    *cols = ws.ws_col;
    *rows = ws.ws_row;
  }
}

void TERM_clearScreen() {
    if (write(STDOUT_FILENO, "\x1b[2J", 4) == -1) {
        OS_PanicFromLit("clearing Screen failed");
    }
}

void TERM_moveCursorTopLeft() {
    if ( write(STDOUT_FILENO, "\x1b[H", 3) == -1) {
        OS_PanicFromLit("moving cursor top left failed");
    }
}
