/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 4
Exercício: 3
*/

/*3. Implemente a função reverso, que reposiciona os elementos na fila de tal forma que
o início da fila dinâmica torna-se o fim, e vice-versa.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct no{
	int dado;
	struct no *prox;	
}no;

typedef struct{
	no *inicio;
	no *fim;	
}fila;

void inicia(fila *f){
	f->inicio = NULL;
	f->fim = NULL;
}

int vazia(fila *f){
	return (f->inicio == NULL);
}

int cheia(){
	no *temp = (no*) malloc(sizeof(no));
	if(temp == NULL) return 1;
	free(temp);
	return 0;
}

void insere(fila *f, int valor){
	if(cheia(f)){
		printf("Memoria cheia\n");
		return;
	}
	no *novo = (no*) malloc(sizeof(no));
	novo->dado = valor;
	novo->prox = NULL;
	
	if(vazia(f))
		f->inicio = novo;
	else
		f->fim->prox = novo;
	f->fim = novo;
}

int tamanho(fila *f){
	int cont = 0;
	no *aux = f->inicio;
	
	while(aux != NULL){
		cont++;
		aux = aux->prox;
	}
	return cont;
}

void reverso(fila *f){
	if(vazia(f) || f->inicio == f->fim) return;
	
	no *anterior = NULL;
	no *atual = f->inicio;
	no *prox_no = NULL;
	no *antigo_inicio = f->inicio;
	
	while(atual != NULL){
		prox_no = atual->prox;
		atual->prox = anterior;
		anterior = atual;
		atual = prox_no;
	}
	
	f->inicio = anterior;
	f->fim = antigo_inicio;
	f->fim->prox = NULL;
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

void imprime(fila *f){
	if(vazia(f)){
		printf("Fila vazia. \n");
		return;
	}
	
	no *aux = f->inicio;
	printf("Fila atual: ");
	while(aux != NULL){
		printf("[%d] ", aux->dado);
		aux = aux->prox;
	}
	printf("\n");
}

int main(){
	fila f;
	inicia(&f);
	
	insere(&f, 10);
	insere(&f, 20);
	insere(&f, 30);
	insere(&f, 40);
	insere(&f, 50);
	
	printf("Tamanho: %d\n", tamanho(&f));
	imprime(&f);
	
	printf("\nInvertendo a fila...\n");
	reverso(&f);
	imprime(&f);
	
	libera(&f);
}
