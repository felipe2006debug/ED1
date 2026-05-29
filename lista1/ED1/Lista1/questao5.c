/*
Nome: Felipe Novaes Silva
Matricula: 54881
Lista: 1
Exercicio: 5
*/

#include <stdio.h>
int main(){
    int A;
    int B;

    printf("\nValor de A: ");
    scanf("%d", &A);

    printf("\nValor de B: ");
    scanf("%d", &B);

    int *p1 = &A;
    int *p2 = &B;

    *p1 = (*p1) * 2;
    *p2 = (*p2) * 2;
    int soma = *p1 + *p2;

    printf("\nO dobro de A: %d", A);
    printf("\nO dobro de B: %d", B);
    printf("\nA soma do dobro: %d", soma);
}
