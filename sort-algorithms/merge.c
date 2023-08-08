#include <stdio.h>
#include <stdlib.h>


void merge(int *vetor, int inicio, int meio, int fim) {

    int *temp, p1, p2, tamanho, i, j, k;
    tamanho = fim-inicio+1;
    p1 = inicio;
    p2 = meio+1;
    temp = (int *) malloc(tamanho*sizeof(int));

    for (i = 0; i < tamanho; i++) {
        if (p1 <= meio && p2 <= fim) {
            if (vetor[p1] < vetor[p2]) {
                temp[i] = vetor[p1];
                p1++;
            } else {
                temp[i] = vetor[p2];
                p2++;
            }
        } else {
            if(p1 <= meio) {
                temp[i] = vetor[p1];
                p1++;
            } else {
                temp[i] = vetor[p2];
                p2++;
            }
        }
    }
    for (j=0, k=inicio; j < tamanho; j++, k++) {
        vetor[k]=temp[j];
    }

    free(temp);

}

void mergeSort(int *vetor, int inicio, int fim) {

    int meio;

    if (inicio < fim) {
        meio = (inicio+fim)/2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, inicio, meio, fim);
    }


}

int main() {

    int n, inicio, fim, vetor[] = {5, 7, 9, 14, 32, 6, 4, 8};
    int* vet;

    n = sizeof(vetor)/sizeof(vetor[0]);

    vet = vetor;

    inicio = 0;
    fim = n-1;

    mergeSort(vet, inicio, fim);

    printf("Vetor ordenado:\n");
    for (int p = 0; p < n; p++) {
        printf("%d\n", vetor[p]);
    }

    return 0;
}