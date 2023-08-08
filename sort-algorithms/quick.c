#include <stdio.h>
#include <stdlib.h>

int particiona(int *vetor, int inicio, int fim) {
    
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = fim;
    pivo = vetor[inicio];

    while(esq < dir) {
        while(esq <= fim && vetor[esq] <= pivo) {
            esq++;
        }

        while(dir >= inicio && vetor[dir] > pivo) {
            dir--;
        }

        if(esq < dir) {
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;
        }
    }
    vetor[inicio] = vetor[dir];
    vetor[dir] = pivo;
    return dir;
}

void quickSort(int *vetor, int inicio, int fim) {

    int pivo;
    if(fim > inicio) {
        pivo = particiona(vetor, inicio, fim);
        quickSort(vetor, inicio, pivo-1);
        quickSort(vetor, pivo+1, fim);
    }

}


int main() {

    int n, inicio, fim, vetor[] = {5, 7, 9, 14, 32, 6, 4, 8};
    int* vet;

    n = sizeof(vetor)/sizeof(vetor[0]);

    vet = vetor;

    inicio = 0;
    fim = n-1;

    quickSort(vet, inicio, fim);

    printf("Vetor ordenado:\n");
    for (int p = 0; p < n; p++) {
        printf("%d\n", vetor[p]);
    }

    return 0;
}