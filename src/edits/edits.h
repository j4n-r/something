#ifndef EDITS
#define EDITS

#define CTRL_KEY(k) ((k) & 0x1f)

typedef struct  {
    u32 screen_rows;
    u32 screen_cols;
    struct termios orig_termios;
} EditsConfig;

EditsConfig e_conf = {0};

void edits_start();

#endif // EDITS
