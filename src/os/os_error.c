#ifndef OS_ERRO
#define OS_ERRO
#include "error.h"

void OS_panicFromLit(const char *msg, const char *file, int line) {
    int err = errno; 
    fprintf(stderr, "PANIC: %s at %s:%d (errno=%d: %s)\n",
            msg, file, line, err, strerror(err));
    exit(0);
}

#endif // OS_ERRO
