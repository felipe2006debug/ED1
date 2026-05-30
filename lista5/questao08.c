/*
 Nome: Felipe Novaes Silva
 Matrícula: 54881
 Lista: 5
 Exercício: 8
 */

#include <stdio.h>

#define MAX 100

typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

int saoIguais(Pilha p1, Pilha p2) {
    if (p1.topo != p2.topo) {
        return 0;
    }

    for (int i = p1.topo; i >= 0; i--) {
        if (p1.itens[i] != p2.itens[i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    Pilha P1, P2;
    
    P1.topo = -1;
    P1.itens[++P1.topo] = 10;
    P1.itens[++P1.topo] = 20;

    P2.topo = -1;
    P2.itens[++P2.topo] = 10;
    P2.itens[++P2.topo] = 20;
    P2.itens[++P2.topo] = 30;

    if (saoIguais(P1, P2)) {
        printf("As pilhas sao iguais\n");
    } else {
        printf("As pilhas sao diferentes\n");
    }

    return 0;
}
