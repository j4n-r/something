#ifndef TERM_COMMANDS
#define TERM_COMMANDS

global String8 TERM_CLEAR_SCREEN = STR8_GLOBAL_LIT("\x1b[2J");
global String8 TERM_MOVE_CURSOR_TOP_LEFT = STR8_GLOBAL_LIT("\x1b[H");

void TERM_getCursorPosition(u32 *row, u32 *col);
void TERM_getWindowSize(u32 *rows, u32 *cols);


#endif //TERM_COMMANDS
