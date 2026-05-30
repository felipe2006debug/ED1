/*
 Nome: Felipe Novaes Silva
 Matrícula: 54881
 Lista: 5
 Exercício: 5
 */

#include <stdio.h>

#define MAX 100

int verificarPalindromo(char palavra[]) {
    char pilha[MAX];
    int topo = -1;
    int i = 0;
    int tam = 0;

    while (palavra[tam] != '\0') {
        tam++;
    }

    for (i = 0; i < tam; i++) {
        topo = topo + 1;
        pilha[topo] = palavra[i];
    }
    for (i = 0; i < tam; i++) {
        char letraDaFrente = palavra[i];
        char letraDeTras = pilha[topo];
        topo = topo - 1;

        if (letraDaFrente != letraDeTras) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char entrada[MAX];

    printf("Digite a palavra: ");
    scanf("%s", entrada);

    if (verificarPalindromo(entrada)) {
        printf("Eh um palindromo.\n");
    } else {
        printf("Nao eh um palindromo.\n");
    }

    return 0;
}
