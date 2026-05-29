/*
Nome: Felipe Novaes Silva
Matricula: 54881
Lista: 1
Exercicio: 4
*/

#include <stdio.h>
int main(){
    int num1, num2;
    int *p1, *p2;

    printf("\nDigite um valor para num1: ");
    scanf("%d", &num1);

    printf("\nDigite um valor para num2: ");
    scanf("%d", &num2);

    p1 = &num1;
    p2 = &num2;

    if(p1 > p2){
        printf("\nO endereco de num1: %p eh o maior. ", (void*)p1);
        printf("\nConteudo de num1: %d", *p1);
    }

    else{
        printf("\nO endereco de num2: %p eh o maior. ", (void*)p2);
        printf("\nConteudo de num2: %d", *p2);
    }
}
