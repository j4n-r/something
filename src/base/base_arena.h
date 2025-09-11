#ifndef BASE_ARENA
#define BASE_ARENA

#define ARENA_SIZE Megabytes(1)
#define ARENA_HEADER_SIZE ((u64)sizeof(Arena))

typedef struct {
  u64       base_pos;
  u64       pos;
  u64       size;
} Arena;



// create or destroy a 'stack' - an "arena"
Arena* ArenaAlloc(void);
void ArenaRelease(Arena *arena);

// push some bytes onto the 'stack' - the way to allocate
void* ArenaPush(Arena* arena, u64 size);
void* ArenaPushZero(Arena* arena, u64 size);

// some macro helpers that I've found nice:
#define PushArrayNoZero(arena, type, count)                                          \
    (type*) ArenaPush((arena), sizeof(type) * (count))
#define PushArrayZero(arena, type, count)                                      \
  (type*) ArenaPushZero((arena), sizeof(type) * (count))
#define PushStruct(arena, type) PushArray((arena), (type), 1)
#define PushStructZero(arena, type) PushArrayZero((arena), (type), 1)

// pop some bytes off the 'stack' - the way to free
void ArenaPop(Arena *arena, u64 size);

// get the # of bytes currently allocated.
u64 ArenaGetPos(Arena *arena);

/* // also some useful popping helpers: */
/* void ArenaSetPosBack(Arena *arena, u64 pos); */
/* void ArenaClear(Arena *arena); */

#endif // BASE_ARENA
