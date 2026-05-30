/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 4
Exercício: 5
*/

/*5. Dada uma fila de inteiros, escreva um programa que exclua os números negativos. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct no{
	int dado;
	struct no* prox;	
}no;

typedef struct{
	no* inicio;
	no* fim;
}fila;

void inicia(fila *f){
	f->inicio = NULL;
	f->fim = NULL;
}

void insere(fila *f, int valor){
	no *novo = (no*) malloc(sizeof(no));
	
	if(novo == NULL) return;
	
	novo->dado = valor;
	novo->prox = NULL;
	
	if(f->inicio == NULL)
		f->inicio = novo;
	else
		f->fim->prox = novo;
	f->fim = novo;
}

void remover(fila *f){
	no *atual = f->inicio;
	no *anterior = NULL;
	
	while(atual != NULL){
		if(atual->dado < 0){
			no *temp = atual;
			if(anterior == NULL){
				f->inicio = atual->prox;
				atual = f->inicio;
			}
			else{
				anterior->prox = atual->prox;
				atual = atual->prox;
			}
			if(temp == f->fim)
				f->fim = anterior;
			free(temp);
		}
		else{
			anterior = atual;
			atual = atual->prox;
		}
	}
}

void imprime(fila *f){
	no *aux = f->inicio;
	
	while(aux != NULL){
		printf("[%d] ", aux->dado);
		aux = aux->prox;
	}
	printf("\n");
}

void libera(fila *f){
	no *aux = f->inicio;
	
	while(aux != NULL){
		no *temp = aux;
		aux = aux->prox;
		free(temp);
	}
	f->inicio = NULL;
	f->fim = NULL;
}

int main(){
	fila f;
	
	inicia(&f);
	
	insere(&f, 10);
	insere(&f, -20);
	insere(&f, -30);
	insere(&f, -40);
	insere(&f, 50);
	
	printf("Antes da remocao: \n");
	imprime(&f);
	
	remover(&f);
	
	printf("Depois da remocao: \n");
	imprime(&f);
	
	libera(&f);
}
