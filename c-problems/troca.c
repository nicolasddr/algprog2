#include <stdio.h>

void troca(int* a, int* b, int* c) {
    int temp = *b;
    *b = *a;
    *a = *c;
    *c = temp;
}

int main() {
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    troca(&a, &b, &c); 

    printf("%d %d %d\n", a, b, c);

    return 0;
}