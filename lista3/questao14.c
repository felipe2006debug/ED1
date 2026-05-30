/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 3
Exercício: 14
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct No{
	int dado;
	struct No* prox;
}No;

No* criaLista(int vetor[], int tamanho){
	No *inicio = NULL;
	No *ultimo = NULL;
	
	for(int i = 0; i < tamanho; i++){
		No *novo = (No*) malloc(sizeof(No));
		
		novo->dado = vetor[i];
		novo->prox = NULL;
		
		if(inicio == NULL){
			inicio = novo;
			ultimo = novo;
		}
		else{
			ultimo->prox = novo;
			ultimo = novo;
		}
	}
	return inicio;
}

void imprime(No *lista){
	No *aux = lista;
	
	while(aux != NULL){
		printf("\n%d -> ", aux->dado);
		aux = aux->prox;
	}
	printf("\nNULL");
}

int main(){
	int vetor[] = {1, 2, 3, 4, 5};
	int tamanho = 5;
	
	No *lista = criaLista(vetor, tamanho);
	imprime(lista);
}
