#ifndef BASE_ARENA
#define BASE_ARENA

#define ARENA_SIZE Megabytes(1)
#define ARENA_HEADER_SIZE ((u64)sizeof(Arena))

typedef struct {
  u64       base_pos;
  u64       pos;
  u64       size;
} Arena;



Arena* ArenaAlloc(void);
void ArenaRelease(Arena *arena);

void* ArenaPush(Arena* arena, u64 size);
void* ArenaPushNoZero(Arena* arena, u64 size);

void ArenaPop(Arena *arena, u64 size);

void ArenaClear(Arena *arena);

#endif // BASE_ARENA
