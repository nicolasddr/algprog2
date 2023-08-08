
#include <stdio.h>
#include <string.h>

struct tipo_atleta {
    char nome[50];
    char esporte[50];
    int idade;
    float altura;
    };
    

int main() {

    typedef struct tipo_atleta tipo_atleta;

    tipo_atleta atletas[3];
    
    int mais_alto, mais_velho;
    int maior_idade;
    float maior_altura;

    for (int i = 0; i < 3; i++) {

        fgets(atletas[i].nome, 50, stdin); 
        fgets(atletas[i].esporte, 50, stdin);
        scanf("%d", &atletas[i].idade);
        scanf("%f", &atletas[i].altura);
        getchar();
    }

    for (int j = 0; j < 3; j++) {
        if (j == 0) {
            maior_altura = atletas[j].altura;
            mais_alto = j;

            maior_idade = atletas[j].idade;
            mais_velho = j;
        } else {
            if (maior_altura < atletas[j].altura) {
                maior_altura = atletas[j].altura;
                mais_alto = j;
            }

            if (maior_idade < atletas[j].idade) {
                maior_idade = atletas[j].idade;
                mais_velho = j;
            }
        }
    }

    printf("%s", atletas[mais_alto].nome);
    printf("%s", atletas[mais_velho].nome);

    return 0;
}
