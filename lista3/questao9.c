/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 3
Exercício: 9
*/

#define MAX 100
typedef struct{
	int dados[MAX];
	int tamanho;
}Lista;

int troca(Lista *l, int i, int j){
	if(i < 0 || j < 0 || i >= l->tamanho || j >= l->tamanho)
		return 0; //erro
	
	int temp = l->dados[i];
	l->dados[i] = l->dados[j];
	l->dados[j] = temp;
	
	return 1; //certo
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	Lista l1, resultado;
	l1.tamanho = 4;
	l1.dados[0] = 1;
	l1.dados[1] = 2;
	l1.dados[2] = 3;
	l1.dados[3] = 4;
	
	if(troca(&l1, 0, 3)){
		for(int i = 0; i < l1.tamanho; i++)
			printf("\nResultado: %d", l1.dados[i]);
	}
	else
		printf("\nErro. ");
}
