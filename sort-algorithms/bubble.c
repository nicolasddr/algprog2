#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *vetor, int n){

    int aux;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (vetor[j] > vetor[j+1]) {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor [j+1] = aux;
            }
        }
    }

    for (int k = 0; k < n; k++){
        printf("%d\n", vetor[k]);
    }
}


int main(){

    int n;
    int *vet;
    int vetor[] = {5, 7, 9, 14, 32, 6, 4, 8};
    vet = vetor;

    n = sizeof(vetor)/sizeof(vetor[0]);

    bubbleSort(vet, n);

    return 0;
}