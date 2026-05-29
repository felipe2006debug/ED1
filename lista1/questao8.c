/*
Nome: Felipe Novaes Silva
Matricula: 54881
Lista: 1
Exercicio: 8
*/

#include <stdio.h>
int main(){
    int v[6];
    int *p = v;

    for(int i = 0; i < 6; i++){
        printf("\nDigite um numero para [%d]: ", i);
        scanf("%d", (p + i));
    }

    for(int i = 0; i < 6; i++){
        printf("\nValores: [%d]", *(p + i));
    }

    for(int i = 0; i < 6; i++){
        printf("\nEndereco de [%d]: %p. ", i, (void*)(p + i));
    }
}
