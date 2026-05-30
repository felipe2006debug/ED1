/*
 Nome: Felipe Novaes Silva
 Matrícula: 54881
 Lista: 5
 Exercício: 4
 */

#include <stdio.h>
#include <string.h>

#define MAX 100

void inverterTexto() {
    char texto[] = "ESTE EXERCICIO E MUITO FACIL.";
    char pilha[MAX];
    int topo = -1;

    for (int i = 0; i < strlen(texto); i++) {
        if (texto[i] != ' ' && texto[i] != '.') {
            pilha[++topo] = texto[i];
        } else {
            while (topo >= 0) {
                printf("%c", pilha[topo--]);
            }
            printf("%c", texto[i]);
        }
    }
}

int main() {
    inverterTexto();
    return 0;
}
