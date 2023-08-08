//Alunos: Júlio César Campos Dalpiaz, Nicolas David Dourado, Samyr, Vinicius

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <math.h>
#define tam1 30000
#define tam2 40000
#define tam3 50000
#define tam4 60000
#define tam5 70000

// FUNCAO QUE CRIA VETORES ///////////////////////////
void Vetores(int *vetor, int tam, int a){
    int i, j = tam-1;

    // VETORES ALEATORIOS ///////////////////////////////
    if (a == 1){
        for (i=0; i<tam; i++){
            vetor[i] = rand()%tam;
        }
    }
    // VETORES EM ORDEM CRESCENTE ///////////////////////
    else if (a == 2){
        for (i=0; i<tam; i++){
            vetor[i] = i;
        }
    }
    // VETORES EM ORDEM DECRESCENTE /////////////////////
    else if (a == 3){
        for (i=0; i<tam; i++){
            vetor[i] = j;
            j--;
        }
    }
    // VETORES ORDENADOS PELA METADE////////////////////
    else if (a == 4){
        for (i=0; i<tam; i++){
            if (i<tam/2){
                vetor[i] = i;
            }else{
                vetor[i] = rand()%tam;
            }
        }
    }
    // VETORES QUASE ORDENADOS/////////////////////////
    else if (a == 5){
        for(i=0; i<tam; i++){
            if (i == tam/2 || i == tam/3 || i == tam/4 || i == tam/5 || i == tam/6){
                vetor[i] = rand()%tam;
            }
            else{
                vetor[i] = i;
            }
        }
    }
}
/////////////////////////////////////////////////////////////////////////

// ALGORITMO SELECTION SORT ///////////////////////////////////////
void Selection_Sort(int *vetor, int tam){
    int i, ind_menor, temp, j;

    for (i=0; i<tam; i++){
        ind_menor=i;
        for(j=i+1; j<tam; j++){
            if(vetor[j] < vetor[ind_menor])
            ind_menor = j;
        }
        temp = vetor[i];
        vetor[i] = vetor [ind_menor];
        vetor[ind_menor] = temp;
    }
}
//////////////////////////////////////////////////////////////

// ALGORITMO INSERTION SORT /////////////////////////////////////
void Insertion(int *vetor, int tam) {
    int aux = vetor[tam];
    int j;

    for (j=tam-1; j>=0; j--){
        if (vetor[j] < aux)
            break;
        vetor[j+1] = vetor[j];
    }
    vetor[j+1] = aux;
}

void Insertion_Sort(int *vetor, int tam) {
    int i;
    for (i=1; i<tam; i++){
        Insertion(vetor, i);
    }
}
//////////////////////////////////////////////////////////////

// ALGORITMO BUBBLE SORT ////////////////////////////////////////
void Bubble_Sort(int* vetor, int tam){
    int i, j, temp;
    for (i=0; i<tam-1; i++){
        for(j=0; j<tam-i-1; j++){
            if(vetor[j] > vetor[j+1]){
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
}
//////////////////////////////////////////////////////////////

// ALGORITMO QUICK SORT ////////////////////////////////////////
int Particao(int *vetor, int inicio, int fim) {
    int pivo = vetor[fim];
    int i = (inicio-1), j, temp;

    for (j=inicio; j<=fim-1; j++) {
        if (vetor[j] <= pivo) {
            i++;
            temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }
    temp = vetor[i+1];
    vetor[i+1] = vetor[fim];
    vetor[fim] = temp;
    return (i+1);
}

void Quick_Sort(int vetor[], int inicio, int fim) {
    if (inicio < fim){
        int pivo = Particao(vetor, inicio, fim);
        Quick_Sort(vetor, inicio, pivo-1);
        Quick_Sort(vetor, pivo+1, fim);
    }
}
//////////////////////////////////////////////////////////////

// ALGORITMO MERGE SORT ////////////////////////////////////////
void Merge(int* A, int p, int q, int r) {
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;
    int* L, *R;
    L = (int*)malloc((n1 + 1) * sizeof(int));
    R = (int*)malloc((n2 + 1) * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = A[p + i];

    for (j = 0; j < n2; j++)
        R[j] = A[q + j + 1];

    L[n1] = R[n2] = INT_MAX;
    i = j = 0;

    for (k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }

    free(L);
    free(R);
}

void Merge_Sort(int* A, int p, int r){
    if(p >= r) return;
    int q = (p + r) / 2;
    Merge_Sort(A, p, q);
    Merge_Sort(A, q + 1, r);
    Merge(A, p, q, r);
}
//////////////////////////////////////////////////////////////

// FUN敲O QUE CALCULA O TEMPO DE CADA ALGORITMO UTILIZANDO VETORES ALEAT覴IOS /////////////
void tempo(int *vetor, int tam, int b){
    int i;

    printf("Vetores de tamanho %d:\n", tam);
    printf("\n");

    // Selection Sort /////////////////////////////////////////////////////////
    float valores[10];
    float soma_media = 0, media;
    float soma_desvio = 0, desvio_padrao;
    clock_t start, end;
    double cpu_time_used;

    for(i=0; i<10; i++){
        start = clock();
        Selection_Sort(vetor, tam);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        valores[i] = cpu_time_used;
        soma_media += valores[i];
    }
    media = soma_media/10;

    for(i=0; i<10; i++){
        soma_desvio += pow(valores[i] - media, 2);
    }
    desvio_padrao = sqrt(soma_desvio/10);

    printf("Media do algoritmo Selection Sort: %.6f segundos\n", media);
    printf("Desvio padrao do algoritmo Selection Sort: %.6f segundos\n", desvio_padrao);

    // Insertion_Sort /////////////////////////////////////////////////////////
    Vetores(vetor, tam, b);

    soma_media = 0;
    soma_desvio = 0;

    for(i=0; i<10; i++){
        start = clock();
        Insertion_Sort(vetor, tam);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        valores[i] = cpu_time_used;
        soma_media += valores[i];
    }
     media = soma_media/10;

    for(i=0; i<10; i++){
        soma_desvio += pow(valores[i] - media, 2);
    }
    desvio_padrao = sqrt(soma_desvio/10);

    printf("\n");
    printf("Media do algoritmo Insertion Sort: %.6f segundos\n", media);
    printf("Desvio padrao do algoritmo Insertion Sort: %.6f segundos\n", desvio_padrao);

    // Bubble Sort /////////////////////////////////////////////////////////
    Vetores(vetor, tam, b);

    soma_media = 0;
    soma_desvio = 0;

    for(i=0; i<10; i++){
        start = clock();
        Bubble_Sort(vetor, tam);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        valores[i] = cpu_time_used;
        soma_media += valores[i];
    }
     media = soma_media/10;

    for(i=0; i<10; i++){
        soma_desvio += pow(valores[i] - media, 2);
    }
    desvio_padrao = sqrt(soma_desvio/10);

    printf("\n");
    printf("Media do algoritmo Bubble Sort: %.6f segundos\n", media);
    printf("Desvio padrao do algoritmo Bubble Sort: %.6f segundos\n", desvio_padrao);

    // QUICK SORT ////////////////////////////////////////////////////////
    Vetores(vetor, tam, b);

    soma_media = 0;
    soma_desvio = 0;

    for(i=0; i<10; i++){
        start = clock();
        Quick_Sort(vetor, 0, tam-1);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        valores[i] = cpu_time_used;
        soma_media += valores[i];
    }
     media = soma_media/10;

    for(i=0; i<10; i++){
        soma_desvio += pow(valores[i] - media, 2);
    }
    desvio_padrao = sqrt(soma_desvio/10);

    printf("\n");
    printf("Media do algoritmo Quick Sort: %.6f segundos\n", media);
    printf("Desvio padrao do algoritmo Quick Sort: %.6f segundos\n", desvio_padrao);


    // MERGE SORT ////////////////////////////////////////////////////////
    Vetores(vetor, tam, b);

    soma_media = 0;
    soma_desvio = 0;

    for(i=0; i<10; i++){
        start = clock();
        Merge_Sort(vetor, 0, tam-1);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        valores[i] = cpu_time_used;
        soma_media += valores[i];
    }
     media = soma_media/10;

    for(i=0; i<10; i++){
        soma_desvio += pow(valores[i] - media, 2);
    }
    desvio_padrao = sqrt(soma_desvio/10);

    printf("\n");
    printf("Media do algoritmo Merge Sort: %.6f segundos\n", media);
    printf("Desvio padrao do algoritmo Merge Sort: %.6f segundos\n", desvio_padrao);
    printf("\n");

}

///////////////////////////////////////////////////////////////////////////

// FUN敲O QUE CRIA OS VETORES///////////////////////////////////
int main(){
    int *vetor1, *vetor2, *vetor3, *vetor4, *vetor5;
    vetor1 = (int *) malloc(tam1*sizeof(int));
    vetor2 = (int *) malloc(tam2*sizeof(int));
    vetor3 = (int *) malloc(tam3*sizeof(int));
    vetor4 = (int *) malloc(tam4*sizeof(int));
    vetor5 = (int *) malloc(tam5*sizeof(int));

    printf("-------------------------------Vetores Aleatorios-------------------------------\n");
    Vetores(vetor1, tam1, 1);
    tempo(vetor1, tam1, 1);

    Vetores(vetor2, tam2, 1);
    tempo(vetor2, tam2, 1);

    Vetores(vetor3, tam3, 1);
    tempo(vetor3, tam3, 1);

    Vetores(vetor4, tam4, 1);
    tempo(vetor4, tam4, 1);

    Vetores(vetor5, tam5, 1);
    tempo(vetor5, tam5, 1);

    printf("-------------------------------Vetores Crescentes-------------------------------\n");
    Vetores(vetor1, tam1, 2);
    tempo(vetor1, tam1, 2);

    Vetores(vetor2, tam2, 2);
    tempo(vetor2, tam2, 2);

    Vetores(vetor3, tam3, 2);
    tempo(vetor3, tam3, 2);

    Vetores(vetor4, tam4, 2);
    tempo(vetor4, tam4, 2);

    Vetores(vetor5, tam5, 2);
    tempo(vetor5, tam5, 2);

    printf("-------------------------------Vetores Decrescentes-------------------------------\n");
    Vetores(vetor1, tam1, 3);
    tempo(vetor1, tam1, 3);

    Vetores(vetor2, tam2, 3);
    tempo(vetor2, tam2, 3);

    Vetores(vetor3, tam3, 3);
    tempo(vetor3, tam3, 3);

    Vetores(vetor4, tam4, 3);
    tempo(vetor4, tam4, 3);

    Vetores(vetor5, tam5, 3);
    tempo(vetor5, tam5, 3);

    printf("-------------------------------Vetores Ordenados Pela Metade-------------------------------\n");
    Vetores(vetor1, tam1, 4);
    tempo(vetor1, tam1, 4);

    Vetores(vetor2, tam2, 4);
    tempo(vetor2, tam2, 4);

    Vetores(vetor3, tam3, 4);
    tempo(vetor3, tam3, 4);

    Vetores(vetor4, tam4, 4);
    tempo(vetor4, tam4, 4);

    Vetores(vetor5, tam5, 4);
    tempo(vetor5, tam5, 4);

    printf("-------------------------------Vetores Quase Ordenados-------------------------------\n");
    Vetores(vetor1, tam1, 5);
    tempo(vetor1, tam1, 5);

    Vetores(vetor2, tam2, 5);
    tempo(vetor2, tam2, 5);

    Vetores(vetor3, tam3, 5);
    tempo(vetor3, tam3, 5);

    Vetores(vetor4, tam4, 5);
    tempo(vetor4, tam4, 5);

    Vetores(vetor5, tam5, 5);
    tempo(vetor5, tam5, 5);

    ///////////////////////////////////////////////////////////

    free(vetor1);
    free(vetor2);
    free(vetor3);
    free(vetor4);
    free(vetor5);

    return 0;
}
