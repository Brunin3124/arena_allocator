#ifndef ARENA_H
#define ARENA_H

#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
//struct
typedef struct{
    unsigned char* buffer;
    size_t length;
    size_t offset;
} Arena;

//functions
void arena_init(Arena* a, size_t size);
void arena_reset(Arena* a);
void* arena_malloc(Arena* a,size_t size);
#endif
