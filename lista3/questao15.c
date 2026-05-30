/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 3
Exercício: 15
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct No{
	int dado;
	struct No* prox;	
}No;

No* inicio(No* inicio, int valor){
	No* novo = (No*) malloc(sizeof(No));
	
	novo->dado = valor;
	novo->prox = inicio;
	
	return novo;
}

void copia(No* inicio, int vetor[], int* tamanho){
	No* aux = inicio;
	int i = 0;
	
	while(aux != NULL){
		vetor[i] = aux->dado;
		i++;
		aux = aux->prox;
	}
	*tamanho = i;
}

int main(){
	No* lista = NULL;
	
	lista = inicio(lista, 10);
	lista = inicio(lista, 20);
	lista = inicio(lista, 30);
	
	int vetor[100];
	int tamanho;
	
	copia(lista, vetor, &tamanho);
	for(int i = 0; i < tamanho; i++)
		printf("%d ", vetor[i]);
}
