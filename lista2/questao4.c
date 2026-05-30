/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 2
Exercício: 4
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
    int num, onum, cont = 0;
    printf("\nDigite um numero: ");
    scanf("%d", &num);

    int *ptr = malloc(num * sizeof(int));

    for(int i = 0; i < num; i++){
        printf("\nNumero [%d]: ", i);
        scanf("%d", ptr + i);
    }

    printf("\nDigite outro numero: ");
    scanf("%d", &onum);

    for(int i = 0; i < num; i++){
        if(*(ptr + i) % onum == 0)
            cont++;
    }

    printf("\nNumero multiplos: %d", cont);
}
