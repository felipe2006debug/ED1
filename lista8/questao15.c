/*
Nome: Felipe Novaes Silva
Matrícula: 54881
Lista: 8
Exercício: 15

Implemente a versão iterativa do algoritmo de inserção de uma árvore AVL.
*/

#include <stdio.h>
#include <stdlib.h>

struct NO{
    int info;
    int alt; // altura daquela sub-arvore
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO* ArvAVL;

ArvAVL* cria_ArvAVL(){
    ArvAVL* raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
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

void libera_ArvAVL(ArvAVL* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada nó
    free(raiz);//libera a raiz
}

int alt_NO(struct NO* no){
    if(no == NULL)
        return -1;
    else
        return no->alt;
}

//Calcula o fator de balanceamento de um nó
int fatorBalaceamento_NO(struct NO* no){
    return labs(alt_NO(no->esq) - alt_NO(no->dir));
}

//Calcula o maior valor
int maior(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}

int estaVazia_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNO_ArvAVL(ArvAVL *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvAVL(&((*raiz)->esq));
    int alt_dir = totalNO_ArvAVL(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

int altura_ArvAVL(ArvAVL *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvAVL(&((*raiz)->esq));
    int alt_dir = altura_ArvAVL(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

void preOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("No %d: %d\n",(*raiz)->info,alt_NO(*raiz));
        preOrdem_ArvAVL(&((*raiz)->esq));
        preOrdem_ArvAVL(&((*raiz)->dir));
    }
}

void emOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvAVL(&((*raiz)->esq));
        printf("No %d: H(%d) fb(%d)\n",(*raiz)->info,alt_NO(*raiz),fatorBalaceamento_NO(*raiz));
        emOrdem_ArvAVL(&((*raiz)->dir));
    }
}

void posOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvAVL(&((*raiz)->esq));
        posOrdem_ArvAVL(&((*raiz)->dir));
        printf("%d\n",(*raiz)->info);
    }
}

int consulta_ArvAVL(ArvAVL *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            return 1;
        }
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

void rotacaoLL(ArvAVL *raiz){
    struct NO *no;
    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = (*raiz);
    (*raiz)->alt = maior(alt_NO((*raiz)->esq),alt_NO((*raiz)->dir))+1;
    (no)->alt = maior(alt_NO(no->esq), (*raiz)->alt)+1;
    (*raiz) = no;
}

void rotacaoRR(ArvAVL *raiz){
    struct NO *no;
    no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = (*raiz);
    (*raiz)->alt = maior(alt_NO((*raiz)->esq),alt_NO((*raiz)->dir))+1;
    (no)->alt = maior(alt_NO(no->dir), (*raiz)->alt)+1;
    (*raiz) = no;
}

void rotacaoLR(ArvAVL *raiz){
    rotacaoRR(&(*raiz)->esq);
    rotacaoLL(raiz);
}

void rotacaoRL(ArvAVL *raiz){
    rotacaoLL(&(*raiz)->dir);
    rotacaoRR(raiz);
}

int insere_ArvAVL(ArvAVL *raiz, int valor){
    int res;
    if(*raiz == NULL){ //arvore vazia ou no folha
        struct NO *novo;
        novo = (struct NO*)malloc(sizeof(struct NO));
        if(novo == NULL)
            return 0;

        novo->info = valor;
        novo->alt = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }
    struct NO *atual = *raiz;
    if(valor < atual->info){
        if((res=insere_ArvAVL(&(atual->esq),valor)) == 1){
            if(fatorBalaceamento_NO(atual) >=2){
                if(valor < (*raiz)->esq->info)
                    rotacaoLL(raiz);
                else
                    rotacaoLR(raiz);
            }
        }
    }
    else{
        if(valor > atual->info){
            if((res=insere_ArvAVL(&(atual->dir),valor)) == 1){
                if(fatorBalaceamento_NO(atual) >=2){
                    if((*raiz)->dir->info < valor)
                        rotacaoRR(raiz);
                    else
                        rotacaoRL(raiz);
                }
            }
        }
        else{
            printf("Valor duplicado!!\n");
            return 0;
        }
    }
    atual->alt = maior(alt_NO(atual->esq), alt_NO(atual->dir))+1;
    return res;
}

//Função responsável por tratar a remoção de um nó com 2 filhos
struct NO* procuraMenor(struct NO* atual){
    struct NO *no1 = atual;
    struct NO *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

//Função responsável pela busca do nó a ser removido
int remove_ArvAVL(ArvAVL *raiz, int valor){
    if(*raiz == NULL){
        printf("Valor não existe!!\n");
        return 0;
    }
    int res;
    if(valor < (*raiz)->info){
        if((res=remove_ArvAVL(&(*raiz)->esq,valor)) == 1){
            if(fatorBalaceamento_NO(*raiz) >=2){
                if(alt_NO((*raiz)->dir->esq) <= alt_NO((*raiz)->dir->dir))
                    rotacaoRR(raiz);
                else
                    rotacaoRL(raiz);

            }
        }
    }
    if((*raiz)->info < valor){
        if((res=remove_ArvAVL(&(*raiz)->dir,valor)) == 1){
            if(fatorBalaceamento_NO(*raiz) >=2){
                if(alt_NO((*raiz)->esq->dir) <= alt_NO((*raiz)->esq->esq))
                    rotacaoLL(raiz);
                else
                    rotacaoLR(raiz);

            }
        }
    }
    if((*raiz)->info == valor){
        //Pai tem um filho ou nenhum
        if(((*raiz)->esq == NULL || (*raiz)->dir == NULL)){
            struct NO *oldNOde = (*raiz);
            if((*raiz)->esq != NULL)
                *raiz = (*raiz)->esq;
            else
                *raiz = (*raiz)->dir;
            free(oldNOde);
        }
        //Pai tem dois filhos: substituir pelo nó mais a esquerda da
        //sub-arvore da direita
        else{
            struct NO* temp = procuraMenor((*raiz)->dir);
            (*raiz)->info = temp->info;
            remove_ArvAVL(&(*raiz)->dir, (*raiz)->info);
            if(fatorBalaceamento_NO(*raiz) >=2){
                if(alt_NO((*raiz)->esq->dir) <= alt_NO((*raiz)->esq->esq))
                    rotacaoLL(raiz);
                else
                    rotacaoLR(raiz);
            }
        }
        return 1;
    }
    return res;
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

void imprime(ArvAVL * raiz) {
    if(raiz == NULL || *raiz == NULL) {
        printf("Arvore vazia\n");
        return;
    }
    imprimeNO(*raiz, 0);
}

int insereIterativo(ArvAVL * raiz, int valor){
    if (raiz == NULL) return 0;

    struct NO* caminho[100];
    int topo = 0;

    struct NO** ptr = raiz;
    struct NO* atual = *raiz;

    while (atual != NULL) {
        if (valor == atual->info) {
            printf("Valor duplicado!!\n");
            return 0;
        }
        caminho[topo++] = atual; 
        if (valor < atual->info) {
            ptr = &(atual->esq);
            atual = atual->esq;
        } else {
            ptr = &(atual->dir);
            atual = atual->dir;
        }
    }

    struct NO* novo = (struct NO*)malloc(sizeof(struct NO));
    if (novo == NULL) return 0;
    novo->info = valor;
    novo->alt = 0;
    novo->esq = NULL;
    novo->dir = NULL;

    *ptr = novo; 

    for (int i = topo - 1; i >= 0; i--) {
        atual = caminho[i];

        atual->alt = maior(alt_NO(atual->esq), alt_NO(atual->dir)) + 1;

        int fb = alt_NO(atual->esq) - alt_NO(atual->dir);

        if (abs(fb) >= 2) {
            struct NO** atual_ptr;
            
            if (i == 0) {
                atual_ptr = raiz;
            } else { 
                struct NO* pai = caminho[i - 1];
                if (pai->esq == atual) {
                    atual_ptr = &(pai->esq);
                } else {
                    atual_ptr = &(pai->dir);
                }
            }

            if (fb >= 2) { 
                if (valor < (*atual_ptr)->esq->info)
                    rotacaoLL(atual_ptr);
                else
                    rotacaoLR(atual_ptr);
            } else { 
                if (valor > (*atual_ptr)->dir->info)
                    rotacaoRR(atual_ptr);
                else
                    rotacaoRL(atual_ptr);
            }
        }
    }
    return 1;
}


int main(){
  ArvAVL * raiz = cria_ArvAVL();

  insereIterativo(raiz, 10);
  insereIterativo(raiz, 20);
  insereIterativo(raiz, 30);
  insereIterativo(raiz, 54);
  insereIterativo(raiz, 32);
  insereIterativo(raiz, 99);
  insereIterativo(raiz, 1);
  
  imprime(raiz);
  
}
