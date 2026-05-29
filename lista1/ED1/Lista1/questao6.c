/*
Nome: Felipe Novaes Silva
Matricula: 54881
Lista: 1
Exercicio: 6
*/

#include <stdio.h>
int main(){

    int a, b;
    int soma, sub, mult;
    float div;
    int *pa = &a;
    int *pb = &b;

    printf("\nDigite um valor para a: ");
    scanf("%d", pa);

    printf("\nDigite um valor para b: ");
    scanf("%d", pb);

    pa = &a;
    pb = &b;

    soma = *pa + *pb;
    printf("\nSoma: %d", soma);

    sub = *pa - *pb;
    printf("\nSubtracao: %d", sub);

    mult = (*pa) * (*pb);
    printf("\nMultiplicacao: %d", mult);

    div = (float)*pa / *pb;
    printf("\nDivisao: %.2f", div);
}
