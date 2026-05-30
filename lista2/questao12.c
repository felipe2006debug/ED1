/* 
Nome: Felipe Novaes Silva 
Matrícula: 54881 
Lista: 2 
Exercício: 12
*/

#include<stdio.h>
#include<stdlib.h>
int main(){
	int l, c;
	float **m;
	
	printf("\nLinhas: ");
	scanf("%d", &l);
	
	printf("\nColunas: ");
	scanf("%d", &c);
	
	m = malloc(l * sizeof(float*));
	
	for(int i = 0; i < l; i++)
		m[i] = malloc(c * sizeof(float));
		
	for(int i = 0; i < l; i++){
		for(int j = 0; j < c; j++){
			printf("\nDigite os numeros: ");
			scanf("%f", &m[i][j]);
		}
	}
	
	for(int i = 0; i < l; i++){
		for(int j = 0; j < c; j++){
			printf("%.2f ", m[i][j]);
		}
		printf("\n");
	}
}
