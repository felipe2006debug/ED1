/*
Nome: Felipe Novaes Silva
Matricula: 54881
Lista: 1
Exercicio: 15
*/

#include <stdio.h>
int main(){
    int v[10];
    int maior, menor;
    int *p = v;
    int *pmax = &maior;
    int *pmin = &menor;

    for(int i = 0; i < 10; i++){
        printf("\nDigite um valor na posicao [%d]: ", i);
        scanf("%d", p + i);
    }

    *pmin = *p;
    *pmax = *p;

    for(int i = 0; i < 10; i++){
        if(*(p + i) > *pmax)
            *pmax = *(p + i);
        if(*(p + i) < *pmin)
            *pmin = *(p + i);
    }

    printf("\nMaior: %d",*pmax);
    printf("\nMenor: %d", *pmin);
}
