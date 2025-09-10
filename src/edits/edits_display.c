
void EDT_drawRows(Arena *arena, EDT_Config *e_conf, String8 term_buf) {
  for (u32 y = 0; y < e_conf->screen_rows; y++) {
      Str8Append(arena, term_buf, STR8_LIT("~"));
    if (y < e_conf->screen_rows - 1) {
        Str8Append(arena, term_buf, STR8_LIT("\r\n"));
    }
  }
}


void EDT_refreshScreen(Arena *arena, EDT_Config *e_conf, String8 term_buf) {
    Str8Append(arena, term_buf, TERM_CLEAR_SCREEN);
    Str8Append(arena, term_buf, TERM_MOVE_CURSOR_TOP_LEFT);

    EDT_drawRows(arena,e_conf, term_buf);

    Str8Append(arena, term_buf, TERM_MOVE_CURSOR_TOP_LEFT);
    write(STDOUT_FILENO, term_buf.str, term_buf.size);

}
