/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 2
Exercício: 5
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
    int *l = malloc(6 * sizeof(int));
    int *b = malloc(6 * sizeof(int));
    int *a;
    int cont = 0;

    for(int i = 0; i < 6; i++){
        printf("\nDigite os 6 primeiros numeros da loteria: ");
        scanf("%d", l + i);
    }

    for(int i = 0; i < 6; i++){
        printf("\nAgora digite os 6 numero do seu bilhete: ");
        scanf("%d", b + i);
    }

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(*(l + i) == *(b + j))
                cont++;
        }
    }

    a = malloc(cont * sizeof(int));
    int k = 0;

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(*(l + i) == *(b + j)){
                *(a + k) = *(l + i);
                k++;
            }
        }
    }

    for(int i = 0; i < 6; i++)
        printf("\nNumeros sorteados: %d", *(l + i));
    for(int i = 0; i < cont; i++)
        printf("\nNumros acertados: %d", *(a + i));

    free(l);
    free(b);
    free(a);
    
}

