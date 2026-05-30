/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 3
Exercício: 6
*/

#define MAX 100

typedef struct{
	int dados[MAX];
	int tamanho;
}Lista;

Lista concatenar(Lista l1, Lista l2){
	Lista resultado;
	resultado.tamanho = 0;
	
	for(int i = 0; i < l1.tamanho; i++){
		resultado.dados[resultado.tamanho] = l1.dados[i];
		resultado.tamanho++;
	}
	
	for(int i = 0; i < l2.tamanho; i++){
		resultado.dados[resultado.tamanho] = l2.dados[i];
		resultado.tamanho++;
	}
	
	return resultado;
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	Lista l1, l2, resultado;
	l1.tamanho = 3;
	l1.dados[0] = 1;
	l1.dados[1] = 2;
	l1.dados[2] = 3;
	
	l2.tamanho = 2;
	l2.dados[0] = 4;
	l2.dados[1] = 5;
	
	resultado = concatenar (l1, l2);
	for(int i = 0; i < resultado.tamanho; i++)
		printf("%d ", resultado.dados[i]);
}
