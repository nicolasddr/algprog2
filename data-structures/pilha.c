#include <stdio.h>
#include <stdlib.h>


typedef struct NO{
    int valor;
    struct NO *proximo;    
}NO;

typedef struct PILHA{
    NO *topo;
}PILHA;

void inicializa(PILHA *pilha) {
    pilha->topo = NULL;
}

void insere(PILHA *pilha, int valor) {
    NO *p = (NO*) malloc(sizeof(NO));
    p->valor = valor;
    p->proximo = pilha->topo;
    pilha->topo = p;
}

int retira(PILHA *pilha) {
    NO *p = pilha->topo;
    int valor;

    if(p == NULL){
        printf("Pilha Vazia\n");
        return;
    }

    pilha->topo = p->proximo;
    p->proximo = NULL;
    valor = p->valor;
    free(p);

    return valor;
}

void imprime(PILHA *pilha){
    NO *p = pilha->topo;
    if(p == NULL){
        printf("Pilha Vazia\n");
        return;
    }

    while(p != NULL){
        printf("%d\n", p->valor);
        p = p->proximo;
    }
}


int main() {

    return 0;
}