/* 
Nome: Felipe Novaes Silva 
Matrícula: 54881 
Lista: 2 
Exercício: 7
*/

#include<stdio.h>
#include<stdlib.h>
int main(){
	int *v = NULL;
	int num;
	int i = 0;
	
	while(1){
		printf("\nDigite numeros: ");
		scanf("%d", &num);
		
		if(num < 0)
			break;
			
		v = realloc(v, (i + 1) * sizeof(int));
		v[i] = num;
		i++;
	};
	
	printf("\nNumeros digitados: ");
	for(int j = 0; j < i; j++)
		printf("%d ", *(v + j));
		
	free(v);
}
