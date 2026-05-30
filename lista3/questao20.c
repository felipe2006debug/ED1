/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 3
Exercício: 20
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

void imprime(No* lista, No* slista){
	No* aux = lista;
	No* saux = slista;
	
	printf("Lista 1\n");
	while(aux != NULL){
		printf("%d -> ", aux->dado);
		aux = aux->prox;
	}
	printf("NULL\n");
	
	printf("\nLista 2\n");
	while(saux != NULL){
		printf("%d -> ", saux->dado);
		saux = saux->prox;
	}
	printf("NULL\n");
}

void verifica(No* lista, No* slista){
	No* aux = lista;
	No* saux = slista;
	
	int iguais = 1;
	
	while(aux != NULL && saux != NULL){
		if(aux->dado != saux->dado){
			iguais = 0;
			break;
		}
		aux = aux->prox;
		saux = saux->prox;
	}
	
	if(aux != NULL || saux != NULL)
		iguais = 0;
	
	if(iguais)
		printf("\nIguais. ");
	else
		printf("\nDiferentes. ");
}

int main(){
	No* lista = NULL;
	No* slista = NULL;
	
	lista = inicio(lista, 10);
	lista = inicio(lista, 20);
	lista = inicio(lista, 30);
	lista = inicio(lista, 40);
	lista = inicio(lista, 50);
	
	slista = inicio(slista, 10);
	slista = inicio(slista, 20);
	slista = inicio(slista, 30);
	slista = inicio(slista, 40);
	slista = inicio(slista, 50);
	
	imprime(lista, slista);
	verifica(lista, slista);
}
