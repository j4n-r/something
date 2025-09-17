#ifndef TERM_COMMANDS_H
#define TERM_COMMANDS_H

global String8 TERM_CLEAR_SCREEN = STR8_GLOBAL_LIT("\x1b[2J");
global String8 TERM_CLEAR_LINE_FROM_CURSOR = STR8_GLOBAL_LIT("\x1b[K");
global String8 TERM_MOVE_CURSOR_TOP_LEFT = STR8_GLOBAL_LIT("\x1b[H");
global String8 TERM_HIDE_CURSOR = STR8_GLOBAL_LIT("\x1b[?25l");
global String8 TERM_SHOW_CURSOR = STR8_GLOBAL_LIT("\x1b[?25h");

void TERM_getCursorPosition(u32 *row, u32 *col);
void TERM_getWindowSize(u32 *rows, u32 *cols);


#endif //TERM_COMMANDS_H
