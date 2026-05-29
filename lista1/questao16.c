/*
Nome: Felipe Novaes Silva
Matricula: 54881
Lista: 1
Exercicio: 16
*/

#include <stdio.h>
int main(){
    int val;
    int A;
    int *B, **C, ***D;

    printf("\nDigite um valor: ");
    scanf("%d", &A);

    B = &A;
    C = &B;
    D = &C;

    printf("\nDobro: %d", *B * 2);
    printf("\nTriplo: %d", **C * 3);
    printf("\nQuadruplo: %d", ***D * 4);
}
