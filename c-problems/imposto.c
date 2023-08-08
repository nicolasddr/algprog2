#include <stdio.h>
#include <stdlib.h>

int main() {

    float inicial, final, imposto;
    char tipo;

    scanf("%f\n", &inicial);
    scanf("%c", &tipo);

    if (tipo == 'A') {
        imposto = 0.07;
    } else if (tipo == 'B') {
        imposto = 0.12;
    } else if (tipo == 'C') {
        imposto = 0.15;
    } else if (tipo == 'D') {
        imposto = 0.08;
    } else {
        printf("Produto nao encontrado.");
    }

    final = inicial * (1+imposto);

    printf("%.2f\n", final);

    return 0;
}