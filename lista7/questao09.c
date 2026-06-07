/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 7
Exercício: 9

Escreva uma função que exclui todos os nós de uma árvore binária de busca com ID par.
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

int insereABB(ArvBin * raiz, int valor){
  if(raiz == NULL) return 0;
  struct NO * novo;
  novo = malloc(sizeof(struct NO));

  if(novo == NULL) return 0;
  novo->info = valor;
  novo->dir = NULL;
  novo->esq = NULL;

  if(*raiz == NULL)
    *raiz = novo;
  else{
    struct NO * atual = *raiz;
    struct NO * ant = NULL;
    while(atual != NULL){
      ant = atual;
      if(valor == atual->info){
        free(novo);
        return 0;
      }
      if(valor > atual->info)
        atual = atual->dir;
      else
        atual = atual->esq;
    }
    if(valor > ant->info)
      ant->dir = novo;
    else
      ant->esq = novo;
  }
  return 1;
}

struct NO * remove_atual(struct NO * atual){
  struct NO * no1, * no2;
  if(atual->esq == NULL){
    no2 = atual->dir;
    free(atual);
    return no2;
  }
  no1 = atual;
  no2 = atual->esq;
  while(no2->dir != NULL){
    no1 = no2;
    no2 = no2->dir;
  }
  if(no1 != atual){
    no1->dir = no2->esq;
    no2->esq = atual->esq;
  }
  no2->dir = atual->dir;
  free(atual);
  return no2;
}

int remove_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL) return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
        }
    return 1;
}

void removePar(ArvBin* raiz) {
    if (raiz == NULL || *raiz == NULL) {
        return;
    }

    //Vai até o fundo da subárvore esquerda
    removePar(&((*raiz)->esq));

    //Vai até o fundo da subárvore direita
    removePar(&((*raiz)->dir));

    //Processa o nó atual (raiz da subárvore em questão)
    if ((*raiz)->info % 2 == 0) {
        *raiz = remove_atual(*raiz);
    }
}

int main(){
  ArvBin * raiz = cria_ArvBin();
  insereABB(raiz, 10);
  insereABB(raiz, 99);
  insereABB(raiz, 2);
  insereABB(raiz, 67);
  insereABB(raiz, 23);
  insereABB(raiz, 1);
  imprime(raiz);
  
  printf("Removendo Pares... \n");
  removePar(raiz);
  imprime(raiz);
}


