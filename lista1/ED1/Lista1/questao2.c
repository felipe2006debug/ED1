/*
Nome: Felipe Novaes Silva
Matricula: 54881
Lista: 1
Exercicio: 2
*/

#include <stdio.h>
int main(){
    int x = 10;
    float y = 10.5;
    char z = 'z';

    int *a = &x;
    float *b = &y;
    char *c = &z;

    printf("\n===Valores antes de modificar===");
    printf("\nx: %d", x);
    printf("\ny: %.2f", y);
    printf("\nc: %c", z);

    *a = 20;
    *b = 20.10;
    *c = 'a';

    printf("\n===Valores depois de modificar===");
    printf("\nx: %d", x);
    printf("\ny: %.2f", y);
    printf("\nc: %c", z);
}
