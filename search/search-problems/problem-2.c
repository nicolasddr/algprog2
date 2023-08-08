/*
Dado um inteiro x e um vetor ordenado v de N inteiros distintos,
projete um algoritmo com o melhor tempo poss´ıvel no pior caso para
encontrar, se existirem, os ´ındices i e j tal que (v[i] + v[j]) == x.
Apresente o tempo de execu¸c˜ao do seu algoritmo para a opera¸c˜ao mais
importante.
*/

#include <stdio.h>
#include <stdlib.h>



int encontraSoma(int *vetor, int valor, int n){

    int i, j;

    for(i=0; i < n; i++){      
        // j = buscaBinaria();
        // return printf("%d + %d = %d", vetor[i], vetor[j], valor);
        for(j=0; j < n; j++){
            if((vetor[i] + vetor[j]) == valor){
                return printf("%d + %d = %d", vetor[i], vetor[j], valor);
            }
        }

    }

    return -1;

}


int main(){

    int vetor[10] = {0, 4, 7, 8, 10, 25, 26, 30, 40, 50};

    encontraSoma(vetor, 35, 10);


    return 0;
}