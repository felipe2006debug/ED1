/* 
Nome: Felipe Novaes Silva 
Matrícula: 54881 
Lista: 2 
Exercício: 10
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	int cod;
	char nome[50];
	int quant;
	float prc;
}produto;

int main(){
	int num;
	int temp;
	float maiorp;
	char maiorpr[50];
	float maiorq;
	char maiorqu[50];
	
	printf("\nDigite a quantidade de produtos: ");
	scanf("%d", &num);
	
	produto *p = malloc(num * sizeof(produto));
	
	for(int i = 0; i < num; i++){
		printf("\n---Produto %d---", i + 1);
		
		printf("\nCodigo: ");
		scanf("%d", &p[i].cod);
		
		printf("\nNome: ");
		setbuf(stdin, 0);
		fgets(p[i].nome, 50, stdin);
		
		printf("\nQuantidade: ");
		scanf("%d", &p[i].quant);
		
		printf("\nPreco: ");
		scanf("%f", &p[i].prc);
	}
	
	maiorp = p[0].prc;
	strcpy(maiorpr, p[0].nome);
	
	maiorq = p[0].quant;
	strcpy(maiorqu, p[0].nome);
	
	for(int i = 0; i < num; i++){
		if(p[i].prc > maiorp){
			maiorp = p[i].prc;
			strcpy(maiorpr, p[i].nome);
		}
		
		if(p[i].quant > maiorq){
			maiorq = p[i].quant;
			strcpy(maiorqu, p[i].nome);
		}
	}
	
	printf("\nProduto: %s mais caro: %f", maiorpr, maiorp);
	printf("\nProduto %s com maior quantidade: %d", maiorqu, maiorq);
	
	free(p);
}
