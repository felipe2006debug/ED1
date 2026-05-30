/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 2
Exercício: 3
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int aloca(int num);

int main(){
    int val;
    printf("\nTamanho string: ");
    scanf("%d", &val);
    getchar();

    aloca(val);
}

int aloca(int val){
    char *string = malloc(val * sizeof(char));
    char vogal[] = "aeiouAEIOU";

    if(string == NULL){
        printf("\nERRO");
        return 1;
    }

    printf("\nDigite uma string: ");
    setbuf(stdin, 0);
    fgets(string, val, stdin);

    printf("\nString digitada: %s", string);

    char *semVogal = malloc(val * sizeof(char));
    if(semVogal == NULL){
        printf("\nERRO");
        return 1;
    }

    int k = 0;

    for(int i = 0; i < strlen(string); i++){
        int ehVogal = 0;
        for(int j = 0; j < strlen(vogal); j++){
            if(string[i] == vogal[j]){
                ehVogal = 1;
                break;
            }
        }
        if(!ehVogal){
            semVogal[k] = string[i];
            k++;
        }
    }
    semVogal[k] = '\0';
    printf("\nString sem vogais: %s", semVogal);

    free(string);
    free(semVogal);
}
