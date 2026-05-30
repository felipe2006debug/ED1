/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 3
Exercício: 7
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

typedef struct{
	int dados[MAX];
	int tamanho;
	int ok;
}Lista;

int quantNum(){
	int num;
	printf("\nNumeros a remover: ");
	scanf("%d", &num);
	
	return num;
}

Lista removen(Lista l1, int res){
	Lista resultado;
	resultado.tamanho = 0;
	
	if(res > l1.tamanho){
		resultado.ok = 0;
		return resultado;
	}
	
	for(int i = res; i < l1.tamanho; i++){
		resultado.dados[resultado.tamanho] = l1.dados[i];
		resultado.tamanho++;
	}
	resultado.ok = 1;
	return resultado;
}

int main(){
	int res;
	res = quantNum();
	
	Lista l1, resultado;
	l1.tamanho = 4;
	l1.dados[0] = 1;
	l1.dados[1] = 2;
	l1.dados[2] = 3;
	l1.dados[3] = 4;
	
	resultado = removen(l1, res);
	
	if(resultado.ok){
		for(int i = 0; i < resultado.tamanho; i++)
			printf("%d ", resultado.dados[i]);
	}
	else
		printf("\nNao foi possivel remover. ");
}

