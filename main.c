#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "arena.h"
int main(){
    Arena arena;
    if(arena_init(&arena,(1024*1024*10)) == false){
        fprintf(stderr,"Erro fatal: sem espaço suficiente");
        return 1;
    } //iniciando a arena
    
    printf("%zu\n", arena.offset); //verificando valor de offset
    void* ponteiro = arena_malloc(&arena,10*sizeof(int)); //alocando memoria
    printf("%zu\n", arena.offset); //verificamos o novo valor de offset
    printf("%p\n", ponteiro); //vericamos se o ponteiro recebeu o endereço de memoria
    arena_reset(&arena); //resetando nossa arena
    printf("%zu\n", arena.offset); //valor de offset aqui deve ser 0, pois foi resetado
    void* ptr_int =  arena_malloc(&arena,sizeof(int));
    
    return 0;
}