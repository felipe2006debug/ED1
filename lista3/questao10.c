/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 3
Exercício: 10
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100

typedef struct{
	int codProd;
	char nomeProd[10];
	float valor;
	int qtdeEstoque;
}produto;

typedef struct{
	produto dados[MAX];
	int tamanho;
}Lista;

int menorPreco(Lista *l, produto *resultado){
	if(l->tamanho == 0)
		return 0;
	
	int menor = 0;
	
	for(int i = 0; i < l->tamanho; i++){
		if(l->dados[i].valor < l->dados[menor].valor)
			menor = i;
	}
	*resultado = l->dados[menor];
	return 1;
}

int main(){
	Lista l;
	produto p;
	
	l.tamanho = 3;
	
	l.dados[0] = (produto){1, "Arroz", 20.5, 10};
	l.dados[1] = (produto){2, "Feijao", 15.0, 5};
	l.dados[2] = (produto){3, "Macarrao", 18.0, 8};
	
	if(menorPreco(&l, &p)){
		printf("\nProduto mais barato: %s", p.nomeProd);
		printf("\nValor: %.2f", p.valor);
	}
	else
		printf("\nErro. ");
}
