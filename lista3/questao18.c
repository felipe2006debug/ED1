/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 3
Exercício: 18
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

No* elimina(No* lista, int valor){
	No* atual = lista;
	No *anterior = NULL;
	No *aux;
	
	while(atual != NULL){
		if(atual->dado == valor){
			if(anterior == NULL){
				lista = atual->prox;
				aux = atual;
				atual = lista;
			}
			else{
				anterior->prox = atual->prox;
				aux = atual;
				atual = atual->prox;
			}
			free(aux);
		}
		else{
			anterior = atual;
			atual = atual->prox;
		}
	}
	return lista;
}

void exibe(No* lista){
	No* atual = lista;
	
	while(atual != NULL){
		printf("%d -> ", atual->dado);
		atual = atual->prox;
	}
	printf("NULL\n");
}

int main(){
	No* lista = NULL;
	
	lista = inicio(lista, 10);
	lista = inicio(lista, 20);
	lista = inicio(lista, 30);
	lista = inicio(lista, 30);
	lista = inicio(lista, 30);
	
	lista = elimina(lista, 30);
	exibe(lista);
}
