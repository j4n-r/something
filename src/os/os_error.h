#ifndef OS_ERROR
#define OS_ERROR

#include <errno.h>
#define OS_PANIC(msg)  OS_panicFromLit(msg, __FILE__, __LINE__)
void OS_panicFromLit(const char *msg, const char *file, int line);

#endif // OS_ERROR
