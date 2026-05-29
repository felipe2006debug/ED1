/*
Nome: Felipe Novaes Silva
Matricula: 54881
Lista: 1
Exercicio: 12
*/

#include <stdio.h>
int main(){
    int v[5];
    int  *p = v;

    for(int i = 0; i < 5; i++){
        printf("\nDigite um numero na posicao [%d]: ", i);
        scanf("%d", (p + i));
    }

    for(int i = 0; i < 5; i++){
        if((*(p + i) % 2) == 0)
            printf("\nNumero %d no endereco: %p eh par", *(p + i), (void*)(p + i));
    }
}
