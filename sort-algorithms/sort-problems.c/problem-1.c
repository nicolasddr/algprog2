#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa {
    int Matricula;
    char Nome[30];
    float Nota;
}pessoa;


void ordena(pessoa *array, int n){

    int menor, aux;

    for(int i = 0; i < n; i++){
        menor = i;
        for(int j = i+1; j < n; j--){
            if(array[j].Nota < array[i].Nota){
                menor = j;
            }
        }
        if(menor != i){
            aux = array[i].Nota;
            array[i].Nota = array[menor].Nota;
            array[menor].Nota = aux;
        }
    }

}