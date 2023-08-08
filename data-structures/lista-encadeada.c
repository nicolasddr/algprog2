#include <stdio.h>
#include <stdlib.h>


typedef struct NO{
    int valor;
    struct NO *proximo;
}NO;

typedef struct LISTA{
    NO *inicio;
    int n;
}LISTA;

void inserirInicio(LISTA *lista, int valor){
    NO *no = (NO*) malloc(sizeof(NO));
    no->valor = valor;
    no->proximo = lista->inicio;
    lista->inicio = no;
    lista->n++;
}

void inserirFinal(LISTA *lista, int valor){
    NO *no, *novo = (NO*) malloc(sizeof(NO));
    no->valor = valor;
    no->proximo = NULL;
    
    if(lista->inicio == NULL){
        lista->inicio = no;
    } else {
        no = lista->inicio;
        while(no->proximo != NULL){
            no = no->proximo;
        }
        no->proximo = novo;
    }
    
    lista->n++;

}

void retira(LISTA *lista, int valor){
    NO *p = lista->inicio;
    NO *ant = NULL;

    while(p != NULL){
        if(p->valor == valor){
            break;
        }

        ant = p;
        p = p->proximo;
    }

    if(p == NULL){
        return;
    }
    
    if(ant == NULL){
        lista->inicio = p->proximo;
    } else {
        ant->proximo = p->proximo;
        free(p);
    }

}

void imprimir(LISTA *lista){
    NO *inicio = lista->inicio;

    while(inicio != NULL){
        printf("%d\n", inicio->valor);
        inicio = inicio->proximo; 
    }
}

void insereMeio(LISTA *lista, int valor, int ant){
    NO *no = (NO*) malloc(sizeof(NO));
    no->valor = valor;
    no->proximo = NULL;

    NO *p = lista->inicio;

    while (p != NULL) {
        if (p->valor == ant) {
            no->proximo = p->proximo;
            p->proximo = no;
            return;
        }

        p = p->proximo;
    }

    if(no == NULL){
        return;
    }

    if(p == NULL){
        lista->inicio = no;
    }

}

LISTA *inicializa(){
    LISTA *lista = (LISTA*) malloc(sizeof(LISTA));
    lista->inicio = NULL;
    lista->n = 0;
    return lista;
}



int main() {


    return 0;
}