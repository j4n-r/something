
void EDT_debugEConfToLogFile(EDT_Config *e_conf) {
    char buf[100] = {0};
    i32 bytes = sprintf(buf, "Screen rows: %u\nScreen cols: %u\nlogfile_path: %.*s",
            e_conf->screen_rows, e_conf->screen_cols ,
            (int)e_conf->logfile_path.size, e_conf->logfile_path.str);
    if (bytes < 0) {
        OS_PANIC("debug logging to buf failed");
    }
    String8 str = Str8New((u8*)buf, strlen(buf));
    IO_writeToFile(e_conf->logfile_path,str);
}
