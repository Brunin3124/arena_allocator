#ifndef ARENA_H
#define ARENA_H

#include <stdint.h>
#include <stdlib.h>


typedef struct{
    unsigned char* buffer;
    size_t length;
    size_t offset;
} Arena;


#endif
