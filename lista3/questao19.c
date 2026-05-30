/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 3
Exercício: 19
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct No{
	int dado;
	struct No* prox;	
}No;

No* inicio(No* lista, int valor){
	No* novo = (No*) malloc(sizeof(No));
	
	novo->dado = valor;
	novo->prox = lista;
	
	return novo;
}

int tamanho(No* lista){
	if(lista == NULL) return 0;
	
	return 1 + tamanho(lista->prox);
}

void imprime(No* lista){
	No* aux = lista;
	
	while(aux != NULL){
		printf("%d -> ", aux->dado);
		aux = aux->prox;
	}
	printf("NULL\n");
}

int main(){
	No* lista = NULL;
	
	lista = inicio(lista, 10);
	lista = inicio(lista, 20);
	lista = inicio(lista, 30);
	lista = inicio(lista, 40);
	lista = inicio(lista, 50);
	
	imprime(lista);
	
	int tam = tamanho(lista);
	printf("\nTamanho: %d", tam);
}
