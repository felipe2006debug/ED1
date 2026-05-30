/*
 Nome: Felipe Novaes Silva
 Matrícula: 54881
 Lista: 5
 Exercício: 6
 */

#include <stdio.h>

#define MAX 100

int verificarParenteses(char expressao[]) {
    char pilha[MAX];
    int topo = -1;
    int i = 0;

    while (expressao[i] != '\0') {
        if (expressao[i] == '(') {
            topo = topo + 1;
            pilha[topo] = '(';
        } 
        else if (expressao[i] == ')') {
            if (topo == -1) {
                return 0;
            }
            topo = topo - 1;
        }
        i++;
    }

    if (topo == -1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char exp[MAX];

    printf("Digite a expressao: ");
    scanf("%s", exp);

    if (verificarParenteses(exp)) {
        printf("Resultado: Correto\n");
    } else {
        printf("Resultado: Incorreto\n");
    }

    return 0;
}
