/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 3
Exercício: 12
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100
typedef struct{
	int dados[MAX];
	int tamanho;
}Lista;

int verifica(Lista l1){
	if(l1.tamanho <= 1)
		return 1;
	
	for(int i = 0; i < l1.tamanho - 1; i++){
		if(l1.dados[i] > l1.dados[i + 1])
			return 0;
		}
		return 1;
	}

int main(){
	Lista l1;
	l1.tamanho = 5;
	
	l1.dados[0] = 1;
	l1.dados[1] = 2;
	l1.dados[2] = 3;
	l1.dados[3] = 4;
	l1.dados[4] = 5;
	
	if(verifica(l1))
		printf("\nLista ordenada. ");
	else
		printf("\nLista nao ordenada. ");
}
