#include <stdio.h>
#include <stdlib.h>

int main() {

    int num, invertido, a, b, c;

    scanf("%d", &num);

    a = num/100;
    num -= a*100;
    
    b = num/10;
    num -= b*10;

    c = num;

    invertido = (c*100) + (b*10) + a;

    printf("%d\n", invertido);

    return 0;
}