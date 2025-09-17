#ifndef EDITS_H
#define EDITS_H

#define CTRL_KEY(k) ((k) & 0x1f)

typedef struct  {
    u32 cx;
    u32 cy;
    u32 screen_rows;
    u32 screen_cols;
    struct termios orig_termios;
    String8 logfile_path;
} EDT_Config;


global EDT_Config e_conf;
global String8 term_buf;

void edits_start();

#endif // EDITS_H
