#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct time {
    char nome[100];
    int pontos;
    int vitorias;
    int empates;
    int derrotas;
    int gols_marcados;
    int gols_sofridos;
};

int main() {
    int n, m;
    struct time *times;
    
    printf("Digite a quantidade de times: ");
    scanf("%d", &n);
    
    times = (struct time*) malloc(n * sizeof(struct time));
    if (times == NULL) {
        printf("Erro: nao foi possivel alocar memoria.\n");
        return 1;
    }
    
    // ler nome de cada time
    for (int i = 0; i < n; i++) {
        printf("Digite o nome do time %d: ", i+1);
        scanf("%s", times[i].nome);
        times[i].pontos = 0;
        times[i].vitorias = 0;
        times[i].empates = 0;
        times[i].derrotas = 0;
        times[i].gols_marcados = 0;
        times[i].gols_sofridos = 0;
    }
    
    printf("\nDigite a quantidade de jogos: ");
    scanf("%d", &m);
    
    // ler resultados dos jogos
    for (int i = 0; i < m; i++) {
        char nome1[100], nome2[100];
        int gols1, gols2;
        
        printf("\nDigite o nome do time 1: ");
        scanf("%s", nome1);
        printf("Digite o nome do time 2: ");
        scanf("%s", nome2);
        printf("Digite o numero de gols do time 1: ");
        scanf("%d", &gols1);
        printf("Digite o numero de gols do time 2: ");
        scanf("%d", &gols2);
        
        // encontrar times correspondentes aos nomes digitados
        int index1 = -1, index2 = -1;
        for (int j = 0; j < n; j++) {
            if (strcmp(nome1, times[j].nome) == 0) {
                index1 = j;
            }
            if (strcmp(nome2, times[j].nome) == 0) {
                index2 = j;
            }
        }
        
        // atualizar resultados dos times
        if (gols1 > gols2) {
            times[index1].pontos += 3;
            times[index1].vitorias++;
            times[index2].derrotas++;
        } else if (gols2 > gols1) {
            times[index2].pontos += 3;
            times[index2].vitorias++;
            times[index1].derrotas++;
        } else {
            times[index1].pontos++;
            times[index1].empates++;
            times[index2].pontos++;
            times[index2].empates++;
        }
        times[index1].gols_marcados += gols1;
        times[index1].gols_sofridos += gols2;
        times[index2].gols_marcados += gols2;
        times[index2].gols_sofridos += gols1;
    }
    
    // imprimir tabela
    printf("\nTabela:\n");
    printf("Time\t");
}