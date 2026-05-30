/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 3
Exercício: 8
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100

typedef struct{
	int dados[MAX];
	int tamanho;
}Lista;

int busca(Lista *l1, int *pos, int *val){
	if(l1->tamanho <= 0)
		return 0;
	
	*val = l1->dados[0];
	*pos = 0;
	
	for(int i = 1; i < l1->tamanho; i++){
		if(l1->dados[i] > *val){
			*val = l1->dados[i];
			*pos = i;
		}
	}
	return 1;
}

int main(){
	Lista minhaLista;
	minhaLista.tamanho = 4;
	minhaLista.dados[0] = 1;
	minhaLista.dados[1] = 2;
	minhaLista.dados[2] = 3;
	minhaLista.dados[3] = 4;
	
	int posicao, valor;
	
	if(busca(&minhaLista, &posicao, &valor)){
		printf("\nMaior valor: %d", valor);
		printf("\nPosicao: %d", posicao);
	}
	else
		printf("\nErro. ");
}
