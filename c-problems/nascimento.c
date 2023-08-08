#include <stdio.h>
#include <stdlib.h>

int main() {

    int nasc, idade, atual;

    scanf("%d", &idade);
    scanf("%d", &atual);

    nasc = atual - idade;

    printf("%d\n", nasc);

    return 0;
}