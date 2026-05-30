/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 4
Exercício: 8
*/

/*8. Dada as operações de fila insere I e remove R, escreva a configuração final da fila 
após as seguintes operações: I(10), I(20), R, I(30), I(45), I(21), R, R. */

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

void remover(fila *f){
	if(f->inicio == NULL) return;
	
	no *temp = f->inicio;
	f->inicio = f->inicio->prox;
	
	if(f->inicio == NULL) f->fim = NULL;
	
	free(temp);
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
	remover(&f);
	insere(&f, 30);
	insere(&f, 45);
	insere(&f, 21);
	remover(&f);
	remover(&f);
	
	imprime(&f);
	libera(&f);
}
