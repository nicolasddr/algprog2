/*
Dada uma lista encadeada com inteiros, escreva uma fun¸c˜ao que verifica
se a lista est´a ordenada ou n˜ao.


#include <stdio.h>
#include <stdlib.h>



int ordenadaVerifica(Lista *lista){

    No *p = lista->inicio;
    int ant, i=0, cresc=1, decresc=1;

    while(p != NULL){
        if(p->valor > ant && i > 0 && cresc == 1){
            cresc = 1;
        } else if(p->valor < ant && i > 0 && decresc == 1){
            decresc = 1;
        }

        ant = p->valor;
        p = p->proximo;
        i++;
    }

    return 1;

}
*/