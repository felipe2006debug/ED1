/*
Nome: Felipe Novaes Silva
Matricula: 54881
Lista: 1
Exercicio: 7
*/

#include <stdio.h>
int main(){
    int a, b, c;
    int *pa = &a, *pb = &b, *pc = &c;

    printf("\nValor de A: ");
    scanf("%d", pa);

    printf("\nValor de B: ");
    scanf("%d", pb);

    printf("\nValor de C: ");
    scanf("%d", pc);

    if(*pa > *pb){
        int temp = *pa;
        *pa = *pb;
        *pb = temp;
    }
    if(*pa > *pc){
        int temp = *pa;
        *pa = *pc;
        *pc = temp;
    }
    if(*pb > *pc){
        int temp = *pb;
        *pb = *pc;
        *pc = temp;
    }

    printf("\nOrdem: %d, %d, %d", *pa, *pb, *pc);
    printf("\nEndereco: %p, %p, %p", (void*)pa, (void*)pb, (void*)pc);
}
