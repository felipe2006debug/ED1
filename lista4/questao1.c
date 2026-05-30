/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 4
Exercício: 1
*/

/*1. O que é e como funciona uma estrutura do tipo fila? */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	/*
	Resposta: Uma fila (queue) é uma estrutura de dados linear em que os elementos são 
	inseridos em uma extremidade (rear / fim), e removidos na outra (front / início),
	obedecendo ao termo FIFO (First In, First Out). Entre as operações que podem ser feitas
	em uma fila, temos a enqueue, que insere no fim; dequeue, que remove no início; front,
	que consulta o primeiro; isEmpty, que verifica se está vazia; e a isFull, que ocorre
	quando há limite.
	Temos algumas propriedades fundamentais, tais como a ordem linear, em que os elementos
	são inseridos de forma a se obter uma sequência bem definida; a restrição de acesso, onde
	não é possível acessar qualquer posição, limitando-se somente a modificar as extremidades;
	a distinção de duas extremidades, ou seja, o front, que é o próximo a sair, e a rear, que
	é o último a ser inserido; e o crescimento controlado, onde a lista cresce e diminui
	dinamicamente, a depender das estradas e saídas.
	Temos ainda um caso que ocorre quando se remove no início, em que é possível conectar
	o final ao início, criando assim as filas circulares.
	*/
}
