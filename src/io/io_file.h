#ifndef IO_FILES
#define IO_FILES

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void IO_writeToFile(String8 path, String8 content);

#endif // IO_FILES
