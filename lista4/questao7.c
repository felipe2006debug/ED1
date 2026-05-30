/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 4
Exercício: 7
*/

/*7. Escreva uma função que, dado duas filas dinâmicas, concatene as duas filas. 
Retorne a fila concatenada em F1. F2 deve ficar fazia. */

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no* prox;
} no;

typedef struct {
    no* inicio;
    no* fim;
} fila;

void inicia(fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void insere(fila *f, int valor) {
    no *novo = (no*) malloc(sizeof(no));
    if (novo == NULL) return;
    
    novo->dado = valor;
    novo->prox = NULL;
    
    if (f->inicio == NULL)
        f->inicio = novo;
    else
        f->fim->prox = novo;
    f->fim = novo;
}

void concatena(fila *f1, fila *f2) {
    if (f2->inicio == NULL) {
        return;
    }

    if (f1->inicio == NULL) {
        f1->inicio = f2->inicio;
        f1->fim = f2->fim;
    } else {
        f1->fim->prox = f2->inicio;
        f1->fim = f2->fim;
    }

    f2->inicio = NULL;
    f2->fim = NULL;
}

void imprime(fila *f) {
    no *aux = f->inicio;
    if (aux == NULL) {
        printf("Fila vazia.\n");
        return;
    }
    while (aux != NULL) {
        printf("[%d] ", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

void libera(fila *f) {
    no *aux = f->inicio;
    while (aux != NULL) {
        no *temp = aux;
        aux = aux->prox;
        free(temp);
    }
    f->inicio = NULL;
    f->fim = NULL;
}

int main() {
    fila f1, f2;
    inicia(&f1);
    inicia(&f2);
    
    insere(&f1, 10);
    insere(&f1, 20);
    insere(&f1, 30);
    
    insere(&f2, 60);
    insere(&f2, 70);
    insere(&f2, 80);
    
    printf("Fila F1 original:\n");
    imprime(&f1);
    
    printf("Fila F2 original:\n");
    imprime(&f2);
    
    concatena(&f1, &f2);
    
    printf("\nFila F1 apos concatenacao:\n");
    imprime(&f1);
    
    printf("Fila F2 apos concatenacao:\n");
    imprime(&f2);
    
    libera(&f1);
    libera(&f2);

    return 0;
}
