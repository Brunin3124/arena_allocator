#include "arena.h"


bool arena_init(Arena* a, size_t size){
    a->buffer = malloc(size);
    if(!a->buffer) return false;

    a->offset = 0;
    a->length = size;
    return true;
}
void arena_reset(Arena* a){
    a->offset = 0;
}


void* arena_malloc(Arena* a,size_t size){
    //
    //assert(size <= a->length - a->offset);
    if(!(size <= a->length - a->offset)){ //se espaço for insuficiente
        printf("Sem espaço suficiente");
        return NULL;
    }
    else{
        unsigned char* ptr = &a->buffer[a->offset]; //ponteiro que aponta para o topo
        a->offset += size; //deslocando
        return ptr;
    }
    
}
