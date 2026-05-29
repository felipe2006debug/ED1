/*
Nome: Felipe Novaes Silva
Matricula: 54881
Lista: 1
Exercicio: 13
*/

#include <stdio.h>
#include <string.h>
int main(){
    char palavra1[20];
    char palavra2[20];
    char *palavra3;
    char *palavra4;

    printf("\nDigite uma palavra: ");
    setbuf(stdin, 0);
    fgets(palavra1, 20, stdin);
    palavra1[strcspn(palavra1, "\n")] = '\0';

    printf("\nDigite outra palavra: ");
    setbuf(stdin, 0);
    fgets(palavra2, 20, stdin);
    palavra2[strcspn(palavra2, "\n")] = '\0';

    palavra3 = palavra1;
    palavra4 = palavra2;

    for(int i = 0; *(palavra3 + i) != '\0'; i++){
        for(int j = 0; *(palavra4 + j) != '\0'; j++){
            if(*(palavra3 + i) == *(palavra4 + j)){
                printf("\nA letra '%c' se repete", *(palavra3 + i));
                break;
            }
        }
    }
}
