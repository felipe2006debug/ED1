/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 7
Exercício: 5

Escreva uma função para achar o MAIOR número em uma árvore binária NÃO ordenada.
*/

#include <stdio.h>
#include <stdlib.h>

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO* ArvBin;

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*)malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);
    free(raiz);
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int altura_ArvBin(ArvBin *raiz){
    if(raiz == NULL || *raiz == NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if(alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return (alt_dir + 1);
}

int totalNO_ArvBin(ArvBin *raiz){
    if(raiz == NULL || *raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    return (alt_esq + alt_dir + 1); 
}

void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d\n", (*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

void emOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%d\n", (*raiz)->info);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}

void posOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf("%d\n", (*raiz)->info);
    }
}

void imprimeNO(struct NO* no, int nivel) {
        if(no == NULL) return;
        imprimeNO(no->dir, nivel + 1);
        for(int i = 0; i < nivel; i++) {
                printf("   ");
        }

        printf("%d\n", no->info);
        imprimeNO(no->esq, nivel + 1);
}

void imprime(ArvBin *raiz) {
    if(raiz == NULL || *raiz == NULL) {
        printf("Arvore vazia\n");
        return;
    }
    imprimeNO(*raiz, 0);
}

int insereBalanceado(ArvBin *raiz, int valor) {
    if (raiz == NULL) return 0;

    struct NO* novo = (struct NO*)malloc(sizeof(struct NO));
    if (novo == NULL) return 0;
    novo->info = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    if (*raiz == NULL) {
        *raiz = novo;
        return 1;
    }

    struct NO* fila[1000]; 
    int ini = 0, fim = 0;

    fila[fim++] = *raiz;

    while (ini < fim) {
        struct NO* atual = fila[ini++];

        if (atual->esq == NULL) {
            atual->esq = novo;
            return 1;
        } else {
            fila[fim++] = atual->esq;
        }

        if (atual->dir == NULL) {
            atual->dir = novo;
            return 1;
        } else {
            fila[fim++] = atual->dir;
        }
    }
    return 0;
}

int encontraMaior(struct NO * no){
  if(no == NULL) return -2147483648; //maior inteiro possivel

  int raiz = no->info;
  int esq = encontraMaior(no->esq);
  int dir = encontraMaior(no->dir);

  int maior = raiz;
  if(esq > maior) maior = esq;
  if(dir > maior) maior = dir;

  return maior;
}

//Wrapper = evita chamar a função completa de uma vez só

int maiorArv(ArvBin * raiz){
  if(estaVazia_ArvBin(raiz)) return 0;
  return encontraMaior(*raiz);
}

int main(){
  ArvBin * raiz = cria_ArvBin();
  insereBalanceado(raiz, 10);
  insereBalanceado(raiz, 5);
  insereBalanceado(raiz, 7);
  insereBalanceado(raiz, 99);
  insereBalanceado(raiz, 35);
  insereBalanceado(raiz, 2);

  imprime(raiz);

  printf("\nMaior elemento da arvore: %d", maiorArv(raiz));
}






