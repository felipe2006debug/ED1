/*
 Nome: Felipe Novaes Silva
 Matrícula: 54881
 Lista: 5
 Exercício: 12
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct { No *frente, *fim; } Fila;
typedef struct { No *topo; } Pilha;

void enfileirar(Fila *f, int v, char *nomeFila) {
    No *novo = malloc(sizeof(No));
    novo->valor = v; novo->prox = NULL;
    if (f->fim == NULL) f->frente = novo;
    else f->fim->prox = novo;
    f->fim = novo;
    printf("-> %d inserido na %s\n", v, nomeFila);
}

int desenfileirar(Fila *f, char *nomeFila) {
    if (f->frente == NULL) return 0;
    No *temp = f->frente;
    int v = temp->valor;
    f->frente = f->frente->prox;
    if (f->frente == NULL) f->fim = NULL;
    free(temp);
    printf("<- %d removido da %s\n", v, nomeFila);
    return v;
}

void push(Pilha *p, int v) {
    No *novo = malloc(sizeof(No));
    novo->valor = v; novo->prox = p->topo;
    p->topo = novo;
    printf("   [Pilha] Valor %d empilhado (positivo)\n", v);
}

void pop(Pilha *p) {
    if (p->topo == NULL) {
        printf("   [Pilha] Tentativa de desempilhar, mas a pilha esta vazia\n");
        return;
    }
    No *temp = p->topo;
    int v = temp->valor;
    p->topo = p->topo->prox;
    free(temp);
    printf("   [Pilha] Valor %d removido (encontrado valor <= 0)\n", v);
}

int main() {
    Fila fPar = {NULL, NULL}, fImpar = {NULL, NULL};
    Pilha pilha = {NULL};
    int num;

    printf("--- ENTRADA DE DADOS ---\n");
    printf("Digite os valores (0 para encerrar):\n");
    while (scanf("%d", &num) && num != 0) {
        if (num % 2 == 0) enfileirar(&fPar, num, "FILA PAR");
        else enfileirar(&fImpar, num, "FILA IMPAR");
    }

    printf("\n--- PROCESSAMENTO ALTERNADO ---\n");
    while (fPar.frente != NULL || fImpar.frente != NULL) {
        if (fImpar.frente != NULL) {
            int v = desenfileirar(&fImpar, "FILA IMPAR");
            if (v > 0) push(&pilha, v); else pop(&pilha);
        }
        if (fPar.frente != NULL) {
            int v = desenfileirar(&fPar, "FILA PAR");
            if (v > 0) push(&pilha, v); else pop(&pilha);
        }
    }

    printf("\n--- CONTEUDO FINAL DA PILHA (Topo para Base) ---\n");
    if (pilha.topo == NULL) {
        printf("A pilha terminou vazia.\n");
    } else {
        while (pilha.topo != NULL) {
            No *temp = pilha.topo;
            int v = temp->valor;
            printf("| %d |\n", v);
            pilha.topo = pilha.topo->prox;
            free(temp);
        }
        printf("-----\n");
    }

    return 0;
}
