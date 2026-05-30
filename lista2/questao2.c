/*
Nome: Amanda Resende
Matrícula: 123456
Lista: 2
Exercício: 2
*/

#include<stdio.h>
#include<stdlib.h>
int main(){
    int val, contpar = 0, contimpar = 0;
    int *ptr;

    printf("\nTamanho do vetor: ");
    scanf("%d", &val);

    ptr = malloc(val * sizeof(int));
    if(ptr == NULL){
        printf("\nERRO");
        return 1;
    }

    for(int i = 0; i < val; i++){
        printf("\nNumero na posicao [%d]: ", i);
        scanf("%d", ptr + i);

        if(*(ptr + i) % 2 == 0)
            contpar++;
        else
            contimpar++;
    }

    printf("\nPares: %d", contpar);
    printf("\nImpares: %d", contimpar);

    free(ptr);
}
