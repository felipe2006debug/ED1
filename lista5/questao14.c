/*
 Nome: Felipe Novaes Silva
 Matrícula: 54881
 Lista: 5
 Exercício: 14
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct {
    No *topo;
} Pilha;

void push(Pilha *p, int v) {
    No *novo = malloc(sizeof(No));
    novo->valor = v;
    novo->prox = p->topo;
    p->topo = novo;
}

int pop(Pilha *p) {
    if (p->topo == NULL) return -1;
    No *temp = p->topo;
    int v = temp->valor;
    p->topo = p->topo->prox;
    free(temp);
    return v;
}

void converter(int n, int base) {
    Pilha p = {NULL};
    char simbolos[] = "0123456789ABCDEF";

    if (n == 0) {
        printf("Resultado: 0\n");
        return;
    }

    while (n > 0) {
        push(&p, n % base);
        n = n / base;
    }

    printf("Resultado: ");
    while (p.topo != NULL) {
        printf("%c", simbolos[pop(&p)]);
    }
    printf("\n");
}

int main() {
    int num, opcao;

    printf("Digite um numero decimal: ");
    scanf("%d", &num);

    printf("\nEscolha a base de conversao:\n");
    printf("1. Binario (Base 2)\n");
    printf("2. Octal (Base 8)\n");
    printf("3. Hexadecimal (Base 16)\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1: converter(num, 2); break;
        case 2: converter(num, 8); break;
        case 3: converter(num, 16); break;
        default: printf("Opcao invalida.\n");
    }

    return 0;
}
