#ifndef IO_FILES_H
#define IO_FILES_H

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void IO_writeToFile(String8 path, String8 content);

#endif // IO_FILES_H
