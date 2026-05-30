/* 
Nome: Felipe Novaes Silva 
Matrícula: 54881 
Lista: 2 
Exercício: 9
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct alunos{
	int mat;
	char sobrenome[20];
	int ano;
};

int main(){
	int num;
	
	printf("\nQuantidade de alunos: ");
	scanf("%d", &num);
	
	struct alunos *a = (struct alunos*) malloc(num * sizeof(struct alunos));
	
	for(int i = 0; i < num; i++){
		printf("\nMatricula %d: ", i + 1);
		scanf("%d", &a[i].mat);
		
		printf("\nSobrenome %d: ", i + 1);
		setbuf(stdin, 0);
		fgets(a[i].sobrenome, 20, stdin);
		
		printf("\nAno %d: ", i + 1);
		scanf("%d", &a[i].ano);
	}
	
	for(int i = 0; i < num; i++){
		printf("\nMatricula %d: ", a[i].mat);
		printf("\nSobrenome %s: ", a[i].sobrenome);
		printf("Ano %d: ", a[i].ano);
		printf("\n-------------------------------------");
	}
	
	free(a);
}
