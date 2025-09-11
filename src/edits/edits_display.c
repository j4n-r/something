
void EDT_drawRows(Arena *arena, String8 *term_buf) {
    for (u32 y = 0; y < e_conf.screen_rows; y++) {
        Str8Append(arena, term_buf, STR8_LIT("~"));
        Str8Append(arena, term_buf, TERM_CLEAR_LINE_FROM_CURSOR);

        if (y < e_conf.screen_rows - 1) {
            Str8Append(arena, term_buf, STR8_LIT("\r\n"));
        }
    }
}


void EDT_refreshScreen(Arena *arena, String8 *term_buf) {
    Str8Append(arena, term_buf, TERM_HIDE_CURSOR);
    Str8Append(arena, term_buf, TERM_MOVE_CURSOR_TOP_LEFT);

    EDT_drawRows(arena, term_buf);

    char buf[32];
    snprintf(buf, sizeof(buf), "\x1b[%d;%dH", e_conf.cy + 1, e_conf.cx + 1);
    Str8Append(arena, term_buf, Str8FromLiteral(buf));

    Str8Append(arena, term_buf, TERM_MOVE_CURSOR_TOP_LEFT);
    Str8Append(arena, term_buf, TERM_SHOW_CURSOR);


    IO_writeToFile(e_conf.logfile_path, *term_buf);

    
    write(STDOUT_FILENO, term_buf->str, term_buf->size);
}
