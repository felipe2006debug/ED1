/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 4
Exercício: 6
*/

/*6. Faça uma função que receba três filas, duas já preenchidas em ordem crescente e 
preencha a última com os valores das duas primeiras em ordem crescente. */

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

void insereH(fila *f, fila *g, fila *h){
	no *auxF = f->inicio;
	no *auxG = g->inicio;
	
	while(auxF != NULL && auxG != NULL){
		if(auxF->dado < auxG->dado){
			insere(h, auxF->dado);
			auxF = auxF->prox;
		}
		else{
			insere(h, auxG->dado);
			auxG = auxG->prox;
		}
	}
	while(auxF != NULL){
		insere(h, auxF->dado);
		auxF = auxF->prox;
	}
	while(auxG != NULL){
		insere(h, auxG->dado);
		auxG = auxG->prox;
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
	fila f, g, h;
	
	inicia(&f);
	inicia(&g);
	inicia(&h);
	
	insere(&f, 10);
	insere(&f, 20);
	insere(&f, 30);
	insere(&f, 40);
	insere(&f, 50);
	
	insere(&g, 60);
	insere(&g, 70);
	insere(&g, 80);
	insere(&g, 90);
	insere(&g, 100);
	
	insereH(&f, &g, &h);
	
	printf("Fila F\n");
	imprime(&f);
	
	printf("Fila G\n");
	imprime(&g);
	
	printf("Fila H\n");
	imprime(&h);
	
	libera(&f);
	libera(&g);
	libera(&h);
}
