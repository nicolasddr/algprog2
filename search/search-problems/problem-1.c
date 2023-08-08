/*
Escreva uma fun¸c˜ao recursiva de busca. A sua fun¸c˜ao deve retornar a
posi¸c˜ao de um n´umero buscado em um vetor. Caso o n´umero buscado
n˜ao esteja no vetor, retorne -1.
*/

#include <stdio.h>
#include <stdlib.h>

int busca(int *vetor, int valor, int ini, int fim){

    if(ini > fim){
        return -1;
    }

    if(vetor[ini] != valor){
        return busca(vetor, valor, ini+1, fim);
    } else {
        return ini;
    }
   
}



int main(){

    return 0;
}