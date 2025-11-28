#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>



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

int main(){
    Arena* arena;
    arena_init(arena,(1024*1024*10)); //iniciando a arena
    
    printf("%ld\n", arena->offset); //verificando valor de offset
    void* ponteiro = arena_malloc(arena,10*(sizeof(int))); //alocando memoria
    printf("%ld\n", arena->offset); //verificamos o novo valor de offset
    printf("%p\n", ponteiro); //vericamos se o ponteiro recebeu o endereço de memoria
    arena_reset(arena); //resetando nossa arena
    printf("%ld\n", arena->offset); //valor de offset aqui deve ser 0, pois foi resetado
    return 0;
}