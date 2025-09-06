#include "error.h"

void OS_PanicFromLit(char *str) {
    perror(str);
    exit(1);
}
