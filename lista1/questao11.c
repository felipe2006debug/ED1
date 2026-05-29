/*
Nome: Felipe Novaes Silva
Matricula: 54881
Lista: 1
Exercicio: 11
*/

#include <stdio.h>
int main(){
    int v[5];
    int *p = v;

    for(int i = 0; i < 5; i++){
        printf("\nDigite um numero na posicao [%d]: ", i);
        scanf("%d", (p + i));
    }

    for(int i = 0; i < 5; i++){
        *(p + i) = *(p + i) * 2;
        printf("\nValor dobrado de [%d]: %d", i, *(p + i));
    }
}
