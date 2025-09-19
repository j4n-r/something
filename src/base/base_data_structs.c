

Queue* QueueNew(Arena *arena, u32 size) {
    Queue *q = (Queue *) ArenaPush(arena, sizeof(Arena) + size);
    q->start = 
}
x
void* QueuePush(Queue q, u32 size) {
}  

void* QueuePop(Queue q, u32 size) {
}

void* QueuePeek(Queue q, u32 size, u8 advance) {
}
