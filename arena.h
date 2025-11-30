#ifndef ARENA_H
#define ARENA_H

#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
//struct
typedef struct{
    unsigned char* buffer;
    size_t length;
    size_t offset;
} Arena;

//functions
bool arena_init(Arena* a, size_t size);
void arena_reset(Arena* a);
void* arena_malloc(Arena* a,size_t size);


#define arena_push(a,type) \
    (type*)arena_malloc(a,sizeof(type))
#define arena_push_array(a,type,count) \
    (type*)arena_malloc(a,sizeof(type)*count)

#endif
