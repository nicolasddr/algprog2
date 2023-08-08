#include <stdio.h>
#include <stdlib.h>


typedef struct NO {
    int valor;
    struct NO *proximo;
}NO;


typedef struct FILA {
    NO *inicio;
    NO *fim;
    int n;
}FILA;


FILA* inicializa() {
    FILA *p = (FILA*) malloc(sizeof(FILA));
    p->inicio = NULL;
    p->fim = NULL;
    p->n = 0;
    return p;
}

void insere(FILA *fila, int valor) {

    NO *p = (NO*) malloc(sizeof(NO));
    p->valor = valor;
    p->proximo = NULL;

    if(fila->inicio == NULL) {
        fila->inicio = p;
    }

    if (fila->fim != NULL) {
        fila->fim->proximo = p;
    }

    fila->fim = p;

    fila->n++;
}

int retira(FILA *fila) {
    
    NO *p = fila->inicio;
    int valor;

    if (p = NULL) {
        printf("Fila Vazia\n");
        return -1;
    }

    fila->inicio = fila->inicio->proximo;
    valor = p->valor;
    free(p);

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    fila->n--;
    return valor;
}

void imprime(FILA *fila) {

    NO *p = fila->inicio;

    if (p == NULL) {
        printf("Fila Vazia\n");
        return;
    } 

    while (p != NULL) {
        printf("%d\n", p->valor);
        p = p->proximo;
    }

}

int main() {
    
    return 0;
}
