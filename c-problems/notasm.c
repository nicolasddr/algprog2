#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    float *notas, soma = 0.0, media;
    
    scanf("%d", &n);
    
    notas = (float*) malloc(n * sizeof(float));
    
    
    for (int i = 0; i < n; i++) {
        scanf("%f", &notas[i]);
        soma += notas[i];
    }
    
    media = soma / n;
    printf("%.2f\n", media);
    
    free(notas);
    return 0;
}