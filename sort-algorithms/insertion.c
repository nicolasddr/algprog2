#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *vetor, int n) {

    int k, j;


    for (int i = 1; i < n; i++) {
        k = vetor[i];
        for (j = i; (j > 0) && (vetor[j-1] > k); j--) {
            vetor[j] = vetor[j-1];
        }
        vetor[j] = k;
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

    insertionSort(vet, n);

    return 0;
}