/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 7
Exercício: 12

Duas ABBs são IGUAIS se são ambas vazias ou então se armazenam valores iguais em suas raízes,
suas sub-árvores esquerdas são iguais, e suas sub-árvores direitas são iguais. Implemente a função que
verifica se duas árvores são iguais.
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

int emOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 0;
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%d\n", (*raiz)->info);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
  return 1;
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

int iguais(struct NO * raiz, struct NO * raiz2){
  if(raiz == NULL && raiz2 == NULL) return 1;

  if(raiz == NULL || raiz2 == NULL || raiz->info != raiz2->info)
    return 0;

  return iguais(raiz->esq, raiz2->esq) && iguais(raiz->dir, raiz2->dir);
}

int main(){
  ArvBin * raiz = cria_ArvBin();
  ArvBin * raiz2 = cria_ArvBin();

  printf("Arvore 1: \n");
  insereABB(raiz, 10);
  insereABB(raiz, 99);
  insereABB(raiz, 2);
  insereABB(raiz, 67);
  insereABB(raiz, 23);
  insereABB(raiz, 1);
  
  insereABB(raiz, 24);
  imprime(raiz);

  printf("\n");
  printf("Arvore 2:");
  printf("\n");

  insereABB(raiz2, 56);
  insereABB(raiz2, 4);
  insereABB(raiz2, 488);
  insereABB(raiz2, 13);
  insereABB(raiz2, 30);
  insereABB(raiz2, 18);
  insereABB(raiz2, 67);
  imprime(raiz2);

  if(iguais(*raiz, *raiz2))
    printf("As arvores sao iguais. ");
  else
    printf("As arvores sao diferentes. ");
}

