/*
 Nome: Felipe Novaes Silva
 Matrícula: 54881
 Lista: 5
 Exercício: 11
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int topo;
    int capacidade;
} Pilha;

void inicializar(Pilha *p, int n) {
    p->dados = (int *)malloc(n * sizeof(int));
    p->topo = -1;
    p->capacidade = n;
}

void push(Pilha *p, int valor) {
    if (p->topo < p->capacidade - 1) {
        p->dados[++(p->topo)] = valor;
    }
}

int peek(Pilha *p) {
    return p->dados[p->topo];
}

int peek_segundo(Pilha *p) {
    return p->dados[p->topo - 1];
}

int main() {
    int n;
    Pilha p;

    if (printf("\nDigite um numer: ") && scanf("%d", &n) != 1 || n <= 0) return 0;

    inicializar(&p, n);

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            push(&p, 0);
        } else if (i == 1) {
            push(&p, 1);
        } else {
            push(&p, peek(&p) + peek_segundo(&p));
        }
    }

    for (int i = 0; i <= p.topo; i++) {
        printf("%d ", p.dados[i]);
    }

    free(p.dados);
    printf("\n");

    return 0;
}
