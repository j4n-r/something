#include "base/base_inc.h"
#include "base/base_inc.c"


typedef struct {
    u32 x;
    u32 y;
} Point;

int main() {
    Arena* perm_arena = ArenaAlloc();
    Point* p = (Point*) ArenaPush(perm_arena, sizeof(Point));
    p->x = 5;
    p->y = 4;


    printf("x: %d, y: %d", p->x, p->y);
}
