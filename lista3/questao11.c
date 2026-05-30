/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 3
Exercício: 11
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

Lista pares(Lista l1){
	Lista resultado;
	resultado.tamanho = 0;
	
	for(int i = 0; i < l1.tamanho; i++){
		if(l1.dados[i] % 2 == 0){
			resultado.dados[resultado.tamanho] = l1.dados[i];
			resultado.tamanho++;
		}
	}
	return resultado;
}

int main(){
	Lista l1, res;
	l1.tamanho = 4;
	
	l1.dados[0] = 1;
	l1.dados[1] = 2;
	l1.dados[2] = 3;
	l1.dados[3] = 4;
	
	res = pares(l1);
	

	for(int i = 0; i < res.tamanho; i++)
		printf("\n%d", res.dados[i]);

}
