/*
Nome: Felipe Novaes Silva
Matricula: 54881
Lista: 1
Exercicio: 10
*/

#include <stdio.h>
int main(){
    float m[3][3] = {{1, 2.4, 3}, {2, 4.6, 9}, {7.9, 3, 5}};
    float *p = &m[0][0];

    for(int i = 0; i < 9; i++){
        printf("\nEndereco: %p", (void*)(p + i));
    }
}
