#include "arena.h"


void arena_init(Arena* a, size_t size){
    a->buffer = malloc(size);
    if(!a->buffer) exit(1);

    a->offset = 0;
    a->length = size;
}
void arena_reset(Arena* a){
    a->offset = 0;
}
void* arena_malloc(Arena* a,size_t size){
    //
    assert(size <= a->length - a->offset); //verifica a condicao
    void* ptr = &a->buffer[a->offset]; //ponteiro que aponta para o topo
    a->offset += size; //deslocando
    return ptr;
}
//void arena_reset(Arena* a);
//void* arena_malloc(Arena* a,size_t size);