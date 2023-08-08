#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, num, qtd=1, maior;

    printf("Digite a quantidade de números: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        if (i == 0) {
            scanf("%d", &maior);
        } else {
            scanf("%d", &num);
        }

        if (num > maior) {
            maior = num;
            qtd = 1;
        } else if (num == maior) {
            qtd++;
        }

    }

    printf("%d %d\n", maior, qtd);

    return 0;
}