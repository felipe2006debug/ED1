/*
 Nome: Felipe Novaes Silva
 Matrícula: 54881
 Lista: 5
 Exercício: 13
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

void I(Pilha *p, int valor) {
    if (p->topo < MAX - 1) {
        p->itens[++(p->topo)] = valor;
        printf("I(%d) -> Pilha: ", valor);
    } else {
        printf("Erro: Pilha cheia!\n");
    }
}

void R(Pilha *p) {
    if (p->topo >= 0) {
        int removido = p->itens[p->topo--];
        printf("R     -> Pilha: ");
    } else {
        printf("Erro: Pilha vazia!\n");
    }
}

void imprimir(Pilha *p) {
    if (p->topo == -1) {
        printf("[ ]\n");
        return;
    }
    printf("[");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d%s", p->itens[i], (i == p->topo) ? "" : ", ");
    }
    printf("] <- Topo\n");
}

int main() {
    Pilha p;
    inicializar(&p);

    printf("Estado Inicial: ");
    imprimir(&p);

    // Sequencia solicitada: I(10), I(20), R, I(30), I(45), I(21), R, R
    I(&p, 10); imprimir(&p);
    I(&p, 20); imprimir(&p);
    R(&p);     imprimir(&p);
    I(&p, 30); imprimir(&p);
    I(&p, 45); imprimir(&p);
    I(&p, 21); imprimir(&p);
    R(&p);     imprimir(&p);
    R(&p);     imprimir(&p);

    printf("\nConfiguracao Final: ");
    imprimir(&p);

    return 0;
}
