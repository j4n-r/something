#ifndef EDITS
#define EDITS

#define CTRL_KEY(k) ((k) & 0x1f)

typedef struct  {
    u32 screen_rows;
    u32 screen_cols;
    struct termios orig_termios;
} EDT_Config;


extern EDT_Config e_conf;
extern String8 term_buf;

void edits_start();

#endif // EDITS
