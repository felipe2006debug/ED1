/* 
Nome: Felipe Novaes Silva 
Matrícula: 54881 
Lista: 2 
Exercício: 11
*/

int retorna(int num1, int num2, int **mat);

#include<stdio.h>
#include<stdlib.h>
int main(){
	int l, c;
	int **m;

	printf("\nLinhas: ");
	scanf("%d", &l);
	
	printf("\nColunas: ");
	scanf("%d", &c);
	
	m = malloc(l * sizeof(int*));
	
	for(int i = 0; i < l; i++){
		m[i] = malloc(c * sizeof(int));
	}
	
	for(int i = 0; i < l; i++){
		for(int j = 0; j < c; j++){
			printf("\nDigite os numeros: ");
			scanf("%d", &m[i][j]);
		}
	}
	
	int r = retorna(l, c, m);
	
	if(r == 1)
		printf("\nValor encontrado. ");
	else
		printf("\nValor nao encontrado. ");
}

int retorna(int l, int c, int **m){
	int val;
	
	printf("\nDigite um valor: ");
	scanf("%d", &val);
	
	for(int i = 0; i < l; i++){
		for(int j = 0; j < c; j++){
			if(val == m[i][j])
				return 1;
		}
	}
	return 0;
}
