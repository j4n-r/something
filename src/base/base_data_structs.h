#ifndef DATA_STRUCTS
#define DATA_STRUCTS

typedef struct {    
    u64 start;
    u64 end;        
    u64 size; // in bytes
} Queue_T;

// TODO implent all of these 
void* QueueNew(Arena *arena, u32 size);
void* QueuePush(u32 size);
void* QueuePop(u32 size);
void* QueuePeek(u32 size, u8 advance);



#endif // DATA_STRUCTS

