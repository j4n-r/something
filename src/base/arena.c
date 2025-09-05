#include "arena.h"
// create or destroy a 'stack' - an "arena"
Arena* ArenaAlloc(void) {
    Arena* arena = (Arena*) calloc(ARENA_SIZE,1);
    arena->pos= 0;
    arena->size= ARENA_SIZE;
    return arena;
}

void ArenaRelease(Arena *arena) {
    free(arena);
}

// push some bytes onto the 'stack' - the way to allocate
void* ArenaPush(Arena *arena, u64 size) {
    if (arena->pos + size > ARENA_SIZE) {
        exit(1);
    }
    arena->pos += size;
    return (u8*)arena + arena->pos + size;
}
void* ArenaPushZero(Arena *arena, u64 size) {
    if (arena->pos + size > ARENA_SIZE) {
        exit(1);
    }

    void* start_addr = (u8*)arena +  arena->pos;
    memset(start_addr,0,size);
    arena->pos += size;
    return start_addr;

}
// pop some bytes off the 'stack' - the way to free
void ArenaPop(Arena *arena, u64 size) {
    if (arena->pos < size) {
        exit(1);
    }
    arena->pos -= size;
}

// get the # of bytes currently allocated.
u64 ArenaGetPos(Arena *arena) {
    return arena->pos;
}

/* // also some useful popping helpers: */
/* void ArenaSetPosBack(Arena *arena, u64 pos); */
/* void ArenaClear(Arena *arena); */
