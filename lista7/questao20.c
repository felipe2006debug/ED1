#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    float area;
    int populacao;
} Municipio;

struct NO_Mun {
    Municipio info;
    struct NO_Mun *esq;
    struct NO_Mun *dir;
};

typedef struct NO_Mun* ArvBinMun;

struct NO_Mun* insere_Mun(struct NO_Mun *raiz, Municipio m) {
    if (raiz == NULL) {
        struct NO_Mun *novo = (struct NO_Mun*)malloc(sizeof(struct NO_Mun));
        novo->info = m;
        novo->esq = novo->dir = NULL;
        return novo;
    }

    int comparacao = strcmp(m.nome, raiz->info.nome);
    
    if (comparacao < 0) {
        raiz->esq = insere_Mun(raiz->esq, m);
    } else if (comparacao > 0) {
        raiz->dir = insere_Mun(raiz->dir, m);
    }
    
    return raiz;
}

int conta_municipios(struct NO_Mun *raiz) {
    if (raiz == NULL) return 0;
    return 1 + conta_municipios(raiz->esq) + conta_municipios(raiz->dir);
}

void mostra_populacao_maior_que(struct NO_Mun *raiz, int x) {
    if (raiz != NULL) {
        mostra_populacao_maior_que(raiz->esq, x);
        
        if (raiz->info.populacao > x) {
            printf("- %s (%d habitantes)\n", raiz->info.nome, raiz->info.populacao);
        }
        
        mostra_populacao_maior_que(raiz->dir, x);
    }
}

void mostra_densidade(struct NO_Mun *raiz) {
    if (raiz != NULL) {
        mostra_densidade(raiz->esq);
        
        float densidade = raiz->info.populacao / raiz->info.area;
        printf("- %s: %.2f hab/km2\n", raiz->info.nome, densidade);
        
        mostra_densidade(raiz->dir);
    }
}

float soma_area_total(struct NO_Mun *raiz) {
    if (raiz == NULL) return 0.0;
    return raiz->info.area + soma_area_total(raiz->esq) + soma_area_total(raiz->dir);
}

void lista_alfabetica(struct NO_Mun *raiz) {
    if (raiz != NULL) {
        lista_alfabetica(raiz->esq);
        
        printf("Nome: %-20s | Area: %8.2f km2 | Pop: %8d\n", 
               raiz->info.nome, raiz->info.area, raiz->info.populacao);
               
        lista_alfabetica(raiz->dir);
    }
}

Municipio* maior_populacao(struct NO_Mun *raiz) {
    if (raiz == NULL) return NULL;

    Municipio *maior = &(raiz->info);
    Municipio *maior_esq = maior_populacao(raiz->esq);
    Municipio *maior_dir = maior_populacao(raiz->dir);

    if (maior_esq != NULL && maior_esq->populacao > maior->populacao) {
        maior = maior_esq;
    }
    if (maior_dir != NULL && maior_dir->populacao > maior->populacao) {
        maior = maior_dir;
    }

    return maior;
}

int main() {
    struct NO_Mun *raiz = NULL;

    Municipio m1 = {"Sao Paulo", 1521.11, 11451245};
    Municipio m2 = {"Nova Andradina", 4776.10, 53225}; 
    Municipio m3 = {"Dourados", 4086.40, 225495};
    Municipio m4 = {"Curitiba", 434.96, 1933105};
    Municipio m5 = {"Bataypora", 1827.00, 11305};

    raiz = insere_Mun(raiz, m1);
    raiz = insere_Mun(raiz, m2);
    raiz = insere_Mun(raiz, m3);
    raiz = insere_Mun(raiz, m4);
    raiz = insere_Mun(raiz, m5);

    printf("--- (e) Cidades em Ordem Alfabetica ---\n");
    lista_alfabetica(raiz);

    printf("\n--- (a) Total de Municipios Cadastrados ---\n");
    printf("Total: %d\n", conta_municipios(raiz));

    printf("\n--- (b) Municipios com mais de 100.000 habitantes ---\n");
    mostra_populacao_maior_que(raiz, 100000);

    printf("\n--- (c) Densidade Demografica ---\n");
    mostra_densidade(raiz);

    printf("\n--- (d) Area em relacao ao Territorio Nacional ---\n");
    float area_brasil = 8510000.0;
    float area_cadastrada = soma_area_total(raiz);
    float porcentagem = (area_cadastrada / area_brasil) * 100.0;
    printf("Area total cadastrada: %.2f km2\n", area_cadastrada);
    printf("Isso representa %.4f%% do territorio nacional.\n", porcentagem);

    printf("\n--- (f) Cidade com a maior populacao ---\n");
    Municipio *maior = maior_populacao(raiz);
    if (maior != NULL) {
        printf("A cidade com maior populacao eh %s com %d habitantes.\n", maior->nome, maior->populacao);
    }

    return 0;
}
