/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 4
Exercício: 10
*/

/*10. Faça uma função para retornar o número de elementos da fila que possuem 
valor par.*/

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

int contaPares(fila *f) {
    int cont = 0;
    no *aux = f->inicio;
    while (aux != NULL) {
        if (aux->dado % 2 == 0) {
            cont++;
        }
        aux = aux->prox;
    }
    return cont;
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
    fila f;
    inicia(&f);

    insere(&f, 10);
    insere(&f, 15);
    insere(&f, 22);
    insere(&f, 33);
    insere(&f, 40);

    int pares = contaPares(&f);
    printf("Pares: %d\n", pares);

    libera(&f);
}
