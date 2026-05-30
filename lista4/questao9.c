/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 4
Exercício: 9
*/

/*9. Faça uma função que receba uma fila como argumento e retorne o valor armazenado em 
seu início. A função deve remover também esse elemento. */

#include <stdio.h>
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

int retorna(fila *f){
	if(f->inicio == NULL) return -1;
	
	no *temp = f->inicio;
	int valor = temp->dado;
	f->inicio = f->inicio->prox;
	
	if(f->inicio == NULL) f->fim = NULL;
	
	free(temp);
	return valor;
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
	insere(&f, 20);
	insere(&f, 30);
	insere(&f, 40);
	insere(&f, 50);
	
	printf("Antes da remocao\n");
	imprime(&f);
	
	int num = retorna(&f);
	printf("Valor do inicio: %d\n", num);
	
	printf("Depois da remocao\n");
	imprime(&f);
	
	libera(&f);
}
