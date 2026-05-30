/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 4
Exercício: 4
*/

/*4. Desenvolva uma função para testar se uma fila F1 tem mais elementos que uma fila F2. 
Não utilize o nó descritor "qtd" para tal finalidade. */

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
	if(novo == NULL){
		printf("\nErro ao alocar memoria. ");
		return;
	}
	
	novo->dado = valor;
	novo->prox = NULL;
	
	if(f->inicio == NULL)
		f->inicio = novo;
	else
		f->fim->prox = novo;	
	f->fim = novo;
}

void imprime(fila *f){
	no *aux = f->inicio;
	
	while(aux != NULL){
		printf("[%d] ", aux->dado);
		aux = aux->prox;
	}
	printf("\n");
}

int maiorFila(fila *f, fila *g){
	no *auxf = f->inicio;
	no *auxg = g->inicio;
	
	while(auxf != NULL && auxg != NULL){
		auxf = auxf->prox;
		auxg = auxg->prox;
	}
	if(auxf != NULL && auxg == NULL)
		return 1;
	return 0;

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
	fila f, g;
	inicia(&f);
	inicia(&g);
	
	insere(&f, 10);
	insere(&f, 20);
	insere(&f, 30);
	insere(&f, 40);
	
	insere(&g, 10);
	insere(&g, 20);
	insere(&g, 30);
	insere(&g, 40);
	insere(&g, 50);
	
	printf("Fila F\n");
	imprime(&f);
	printf("Fila G\n");
	imprime(&g);
	
	if(maiorFila(&f, &g))
		printf("\nFila F eh maior que Fila G. ");
	else
		printf("\nFila F nao eh maior que a Fila G. ");
		
	libera(&f);
	libera(&g);
}
