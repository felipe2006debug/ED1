/*
Nome: Felipe Novaes Silva
Matricula: 54881
Lista: 1
Exercicio: 14
*/

#include <stdio.h>
int main(){
    int num;
    int v[10];
    int *p = v;
    printf("\nDigite um numero: ");
    scanf("%d", &num);

    for(int i = 0; i < 10; i++){
        *(p + i) = num;

        printf("\nPosicao [%d] preenhida: %d", i, *(p + i));
    }
}
