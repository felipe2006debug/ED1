/*
Nome: Felipe Novaes Silva
Matricula: 54881
Lista: 1
Exercicio: 9
*/

#include <stdio.h>
int main(){
    float v[10] = {1, 2.4, 3, 5.9, 4, 6, 7, 8, 8.6, 10};
    float *p = v;

    for(int i = 0; i < 10; i++){
        printf("\nEndereco: %p", (void*)(p + i));
    }
}
