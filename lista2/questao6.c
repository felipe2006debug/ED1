/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 2
Exercício: 6
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int *vetor;
    int cont = 0;

    vetor = (int*) calloc(1500, sizeof(int));

    if(vetor == NULL){
        printf("Erro de alocacao\n");
        return 1;
    }

    for(int i = 0; i < 1500; i++){
        if(vetor[i] == 0){
            cont = cont + 1;
        }
    }

    printf("Quantidade de zeros: %d\n\n", cont);

    for(int i = 0; i < 1500; i++){
        vetor[i] = i;
    }

    printf("10 primeiros:\n");
    for(int i = 0; i < 10; i++){
        printf("%d ", vetor[i]);
    }

    printf("\n\n");

    printf("10 ultimos:\n");
    for(int i = 1500 - 10; i < 1500; i++){
        printf("%d ", vetor[i]);
    }

    printf("\n\n");

    printf("Todos os 1500 numeros:\n");
    for(int i = 0; i < 1500; i++){
        printf("%d ", vetor[i]);
    }

    free(vetor);

    return 0;
}
