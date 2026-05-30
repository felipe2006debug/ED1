/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 3
Exercício: 17
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

No* inverte(No* inicio){
	No* anterior = NULL;
	No* atual = inicio;
	No* proximo;
	
	while(atual != NULL){
		proximo = atual->prox;
		atual->prox = anterior;
		anterior = atual;
		atual = proximo;
	}	
	return anterior;
}

int main(){
	No* lista = NULL;
	
	lista = inicio(lista, 30);
	lista = inicio(lista, 20);
	lista = inicio(lista, 10);
	
	No* resultado = inverte(lista);
	No* aux = resultado;
	
	while(aux != NULL){
		printf("%d -> ", aux->dado);
		aux = aux->prox;
	}
	printf("NULL\n");
}
