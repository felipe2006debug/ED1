/*
 Nome: Felipe Novaes Silva
 Matrícula: 54881
 Lista: 5
 Exercício: 10
 */

#include <stdio.h>

#define MAX 100

typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

typedef struct {
    int itens[MAX];
    int frente;
    int tras;
} Fila;

void push(Pilha *p, int valor) {
    p->itens[++(p->topo)] = valor;
}

int pop(Pilha *p) {
    return p->itens[(p->topo)--];
}

void enqueue(Fila *f, int valor) {
    f->itens[f->tras++] = valor;
}

int dequeue(Fila *f) {
    return f->itens[f->frente++];
}

void inverterFila(Fila *f, Pilha *p) {
    while (f->frente < f->tras) {
        push(p, dequeue(f));
    }

    while (p->topo != -1) {
        enqueue(f, pop(p));
    }
}

int main() {
    Fila f;
    Pilha p;
    
    f.frente = 0;
    f.tras = 0;
    p.topo = -1;

    enqueue(&f, 10);
    enqueue(&f, 20);
    enqueue(&f, 30);

    inverterFila(&f, &p);

    printf("Fila invertida: ");
    while (f.frente < f.tras) {
        printf("%d ", dequeue(&f));
    }

    return 0;
}
