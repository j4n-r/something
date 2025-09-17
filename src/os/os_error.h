#ifndef OS_ERROR_H
#define OS_ERROR_H

#include <errno.h>

#define OS_PANIC(msg)  OS_panicFromLit(msg, __FILE__, __LINE__)
void OS_panicFromLit(const char *msg, const char *file, int line);

#endif // OS_ERROR_H
