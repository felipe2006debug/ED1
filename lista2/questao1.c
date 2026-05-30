/*
Nome: Amanda Resende
Matrícula: 123456
Lista: 2
Exercício: 1
*/

#include<stdio.h>
#include<stdlib.h>
int main(){
    int *p;
    p = malloc(5 * sizeof(int));
    if(p == NULL){
        printf("\nERRO");
        return 1;
    }

    for(int i = 0; i < 5; i++){
        printf("\nDigite um numero na posicao [%d]: ", i);
        scanf("%d", (p + i));
    }

    for(int i = 0; i < 5; i++){
        printf("\nNumero [%d]", *(p + i));
    }

    free(p);
}
