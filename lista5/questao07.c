/*
 Nome: Felipe Novaes Silva
 Matrícula: 54881
 Lista: 5
 Exercício: 7
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

void ordenarPilha(Pilha *original) {
    Pilha auxiliar;
    auxiliar.topo = -1;

    while (original->topo != -1) {
        int temp = pop(original);

        while (auxiliar.topo != -1 && auxiliar.itens[auxiliar.topo] > temp) {
            push(original, pop(&auxiliar));
        }

        push(&auxiliar, temp);
    }

    while (auxiliar.topo != -1) {
        push(original, pop(&auxiliar));
    }
}

int main() {
    Pilha p;
    p.topo = -1;

    push(&p, 34);
    push(&p, 3);
    push(&p, 31);
    push(&p, 98);
    push(&p, 92);
    push(&p, 23);

    ordenarPilha(&p);

    printf("Pilha ordenada (topo para base): ");
    while (p.topo != -1) {
        printf("%d ", pop(&p));
    }

    return 0;
}
