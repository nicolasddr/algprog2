#include <stdio.h>
#include <stdlib.h>

void selectionSort(int* vetor, int n) {

    int menor, aux;

    for (int i = 0; i < n; i++) {
        menor = i;
        for (int j = i+1; j < n; j++) {
            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }
        if (menor != i) {
            aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }

    for (int p = 0; p < n; p++){
            printf("%d\n", vetor[p]);
        }

}

int main() {

    int n;
    int *vet;
    int vetor[] = {5, 7, 9, 14, 32, 6, 4, 8};

    vet = vetor;

    n = sizeof(vetor)/sizeof(vetor[0]);

    selectionSort(vet, n);

    return 0;


}