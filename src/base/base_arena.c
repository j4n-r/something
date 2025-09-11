#include "base_arena.h"

Arena *ArenaAlloc(void) {
    Arena *arena = (Arena *)calloc(ARENA_HEADER_SIZE + ARENA_SIZE, 1);
    arena->pos = ARENA_HEADER_SIZE;
    arena->size = ARENA_SIZE;
    return arena;
}

void ArenaRelease(Arena *arena) { free (arena); }

void ArenaClear(Arena *arena) {
    arena->pos = ARENA_HEADER_SIZE;
    void *start_addr = (u8*) arena + arena->pos;
    memset(start_addr, 0, arena->size);
}

void *ArenaPushNoZero(Arena *arena, u64 size) {
    if (arena->pos + size > ARENA_SIZE) {
        printf("Arena size too small.\narena_pos: %ld\nsize_to_alloc: %ld\nARENA_SIZE: %d", arena->pos, size,ARENA_SIZE);
        exit(1);
    }
    void *start_addr = (u8 *)arena + arena->pos;
    arena->pos += size;
    return start_addr;
}
void *ArenaPush(Arena *arena, u64 size) {
    if (arena->pos + size > ARENA_SIZE) {
        printf("Arena size too small.\narena_pos: %ld\nsize_to_alloc: %ld", arena->pos, size);
        exit(1);
    }

    void *start_addr = (u8 *)arena + arena->pos;
    memset(start_addr, 0, size);
    arena->pos += size;
    return start_addr;
}

void ArenaPop(Arena *arena, u64 size) {
    if (arena->pos < size) {
        exit(1);
    }
    arena->pos -= size;
}

// get the # of bytes currently allocated.
u64 ArenaGetPos(Arena *arena) { return arena->pos; }


/* // also some useful popping helpers: */
/* void ArenaSetPosBack(Arena *arena, u64 pos); */
/* void ArenaClear(Arena *arena); */
