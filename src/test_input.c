#include "base/base_inc.h"
#include "base/base_inc.c"


Result_u8 testResult() {
    return OK(u8, 2); 
}
int main() {
    Result_u8 res = testResult();
    if (res.is_error) {
        printf("error");
    }
    exit(0);
}

