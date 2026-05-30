/*
 Nome: Felipe Novaes Silva
 Matrícula: 54881
 Lista: 5
 Exercício: 9
 */

#include <stdio.h>

#define MAX 100

typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

void push(Pilha *p, int valor) {
    p->itens[++(p->topo)] = valor;
}

int pop(Pilha *p) {
    return p->itens[(p->topo)--];
}

void copiarPilha(Pilha *p1, Pilha *p2) {
    Pilha pAux;
    pAux.topo = -1;
    p2->topo = -1;

    while (p1->topo != -1) {
        push(&pAux, pop(p1));
    }

    while (pAux.topo != -1) {
        int valor = pop(&pAux);
        push(p1, valor); 
        push(p2, valor);
    }
}

int main() {
    Pilha P1, P2;
    P1.topo = -1;
    P2.topo = -1;

    push(&P1, 10);
    push(&P1, 20);
    push(&P1, 30);

    printf("P1 antes da copia (topo): %d\n", P1.itens[P1.topo]);

    copiarPilha(&P1, &P2);

    printf("\n--- Pilhas Finais ---\n");
    printf("P1 (topo): %d\n", P1.itens[P1.topo]);
    printf("P2 (topo): %d\n", P2.itens[P2.topo]);

    printf("\nConteudo de P2 (do topo para a base):\n");
    while (P2.topo != -1) {
        printf("| %d |\n", pop(&P2));
    }
    printf(" -----\n");

    return 0;
}
