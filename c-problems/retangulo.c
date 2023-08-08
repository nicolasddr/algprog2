#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Ponto;

typedef struct {
    Ponto sup_esq;
    Ponto inf_dir;
} Retangulo;

int main() {

   Retangulo ret;

   int area, diagonal, altura, base;

    scanf("%f %f %f %f", &ret.sup_esq.x, &ret.sup_esq.y, &ret.inf_dir.x, &ret.inf_dir.y);

    altura = fabs(ret.inf_dir.y - ret.sup_esq.y);
    base = fabs(ret.inf_dir.x - ret.sup_esq.x);

    area = base * altura;
    diagonal = sqrt(pow(base, 2) + pow(altura, 2));

    printf("%d %d\n", area, diagonal);

    return 0;
}