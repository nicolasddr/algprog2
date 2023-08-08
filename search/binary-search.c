#include <stdio.h>
#include <stdlib.h>



int buscaBinaria(int *vetor, int valor, int esq, int dir) {

    if(esq > dir){
        return -1;
    }

    int meio = (esq+dir)/2;

    if(valor < vetor[meio]) {
       return buscaBinaria(vetor, valor, esq, meio-1);
    } else if(valor > vetor[meio]) {
        return buscaBinaria(vetor, valor, meio+1, dir);
    } else if(valor == vetor[meio]) {
        return meio;
    }

}


int main() {

    int vetor[10] = {0, 4, 7, 8, 10, 25, 26, 30, 40, 50};

    int n = 10;

    int valor = 10;

    int ind = buscaBinaria(vetor, valor, 0, n-1);

    printf("%d", ind);

    return 0;
}