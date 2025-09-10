

void IO_writeToFile(String8 path, String8 content) {
    mode_t mode = S_IRUSR | S_IWUSR;
    u32 flags = O_CREAT | O_WRONLY | O_APPEND;
    i32 fd = open((char*) path.str, flags, mode);
    if (fd == -1) {
        OS_PANIC("Error during opening of error log file");
    }
    
    i64 bytes = write(fd, content.str, content.size);
    if (bytes == -1) {
        OS_PANIC("Error during opening of error log file");
    }
    close(fd);
}
