#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 4
Exercício: 11
*/

/*11. Em um banco, há apenas um caixa e todos devem ser atendidos por ordem de 
chegada. No entanto, pessoas idosas têm prioridade e passam para o início da fila. 
Considerando que em vários dias o número de idosos é muito grande, foi estipulada a 
seguinte regra: 
	1. uma pessoa é atendida na ordem de chegada
	2. no máximo 2 idosos podem passar na frente de uma pessoa que não é idosa.
	
Escreva um programa que leia uma sequência de linhas, onde cada linha contém a
informação da ordem de chegada e categoria do cliente e imprima a ordem de atendimento 
(considere que todos chegaram antes de começar o atendimento). Exemplo de entrada: 

	1 geral
	2 geral
	3 idoso
	4 idoso
	5 idoso
	6 geral
	7 idoso
	
Exemplo de saída: 3 4 1 2 5 7 6*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int idExiste(int id, int fila_idoso[], int qtd_idoso, int fila_geral[], int qtd_geral) {
    for (int i = 0; i < qtd_idoso; i++) {
        if (fila_idoso[i] == id) return 1;
    }
    for (int i = 0; i < qtd_geral; i++) {
        if (fila_geral[i] == id) return 1;
    }
    return 0;
}

void cadastrarClientes(int fila_idoso[], int *qtd_idoso, int fila_geral[], int *qtd_geral) {
    int total;
    
    do {
        printf("Quantas pessoas estao na fila (1 a %d)? ", MAX);
        if (scanf("%d", &total) != 1 || total <= 0 || total > MAX) {
            printf("[ERRO] Digite um numero valido entre 1 e %d.\n", MAX);
            limparBuffer();
            total = -1;
        }
    } while (total <= 0);

    for (int k = 0; k < total; k++) {
        int id;
        char categoria[20];

        printf("\n--- Cadastro da %da pessoa ---\n", k + 1);
        
        while (1) {
            printf("Digite o ID (numero): ");
            if (scanf("%d", &id) == 1) {
                if (idExiste(id, fila_idoso, *qtd_idoso, fila_geral, *qtd_geral)) {
                    printf("[ERRO] Este ID %d ja foi cadastrado! Tente outro.\n", id);
                } else {
                    break;
                }
            } else {
                printf("[ERRO] ID invalido! Digite apenas numeros.\n");
                limparBuffer();
            }
        }

        while (1) {
            printf("Digite a categoria (idoso ou geral): ");
            scanf("%s", categoria);
            if (strcmp(categoria, "idoso") == 0 || strcmp(categoria, "geral") == 0) break;
            printf("[ERRO] Categoria invalida! Use 'idoso' ou 'geral'.\n");
        }

        if (strcmp(categoria, "idoso") == 0) {
            fila_idoso[(*qtd_idoso)++] = id;
        } else {
            fila_geral[(*qtd_geral)++] = id;
        }
    }
}

void imprimirAtendimento(int fila_idoso[], int qtd_idoso, int fila_geral[], int qtd_geral) {
    int i = 0, j = 0;

    printf("\n================================\n");
    printf("ORDEM FINAL DE ATENDIMENTO:\n");

    while (i < qtd_idoso || j < qtd_geral) {
        int cont = 0;
        while (cont < 2 && i < qtd_idoso) {
            printf("%d ", fila_idoso[i++]);
            cont++;
        }
        if (j < qtd_geral) {
            printf("%d ", fila_geral[j++]);
        }
    }
    printf("\n================================\n");
}

int main() {
    int fila_idoso[MAX], fila_geral[MAX];
    int qtd_idoso = 0, qtd_geral = 0;

    printf("=== SISTEMA BANCARIO ===\n");

    cadastrarClientes(fila_idoso, &qtd_idoso, fila_geral, &qtd_geral);
    imprimirAtendimento(fila_idoso, qtd_idoso, fila_geral, qtd_geral);

    return 0;
}
