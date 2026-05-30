/* 
Nome: Felipe Novaes Silva 
Matrícula: 54881 
Lista: 2 
Exercício: 8
*/

#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int main(){
	int num;
	
	printf("\nValores para o vetor >= 10: ");
	scanf("%d", &num);
		
	while(num < 10){
		printf("\nTente novamente, valor >= 10: ");
		scanf("%d", &num);
	};
	
	double *v = malloc(num * sizeof(double));
	
	srand(time(NULL));
	
	for(int i = 0; i < 10; i++){
		*(v + i) = rand() % 100;
	}
	
	printf("\nValores dos 10 primeiros elementos: ");
	
	for(int i = 0; i < 10; i++)
		printf("%.2f ", *(v + i));
	free(v);
}
