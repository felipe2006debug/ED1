/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 3
Exercício: 16
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct No{
	int dado;
	struct No* prox;
}No;

No* final(No* inicio, int valor){
	No* novo = (No*) malloc(sizeof(No));
	
	novo->dado = valor;
	novo->prox = NULL;
	
	if(inicio == NULL)
		return novo;
		
	No* aux = inicio;
	while(aux->prox != NULL)
		aux = aux->prox;
	
	aux->prox = novo;
	return inicio;
}

No* concatena(No* l1, No* l2){
	No* nova = NULL;
	No* aux;
	
	aux = l1;
	while(aux != NULL){
		nova = final(nova, aux->dado);
		aux = aux->prox;
	}
	
	aux = l2;
	while(aux != NULL){
		nova = final(nova, aux->dado);
		aux = aux->prox;
	}
	return nova;
}

int main(){
	No* lista = NULL;
	No* slista = NULL;
	
	lista = final(lista, 10);
	lista = final(lista, 20);
	lista = final(lista, 30);
	
	slista = final(slista, 40);
	slista = final(slista, 50);
	slista = final(slista, 60);
	
	No* resultado = concatena(lista, slista);
	
	No* aux = resultado;
	while(aux != NULL){
		printf("%d -> ", aux->dado);
		aux = aux->prox;
	}
	printf("NULL\n");
}
