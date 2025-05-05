#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h" //inclui os Protótipos

//Definição do tipo Fila
struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;
//Definição do Nó Descritor da Fila
struct elemento2{
    Fila* dados2;
    struct elemento2 *prox2;
};
typedef struct elemento2 Elem2;

struct filafilas{
    struct elemento2 *inicio;
    struct elemento2 *final;
    int qtd;
};

struct elemento3 {
    Pilha* dados3;
    struct elemento3* prox3;
};
typedef struct elemento3 Elem3;

struct filapilhas {
    Elem3* inicio;
    Elem3* final;
    int qtd;
};

struct elemento4 {
    Fila* dados4;
    struct elemento4* prox4;
};
typedef struct elemento4 ElemPilhaFila;
struct fila {
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

struct elemento5{
    float valor;
    struct elemento5 *prox5;
};
typedef struct elemento5 Elem5;

struct filaf {
    Elem5* fim;
};

Fila* cria_Fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}
FilaPilhas* cria_FilaPilhas(){
    FilaPilhas* fi = (FilaPilhas*) malloc(sizeof(FilaPilhas));
    if (fi != NULL) {
        fi->inicio = NULL;
        fi->final = NULL;
        fi->qtd = 0;
    }
    return fi;
}

FilaFilas* cria_FilaFilas(){
    FilaFilas* fi = (FilaFilas*) malloc(sizeof(FilaFilas));
    if(fi != NULL){
        fi->inicio = NULL;
        fi->final = NULL;
        fi->qtd = 0;
    }
    return fi;
}
PilhaFilas* cria_PilhaFilas() {
    PilhaFilas* pi = (PilhaFilas*) malloc(sizeof(PilhaFilas));
    if (pi != NULL)
        *pi = NULL;
    return pi;
}
FilaF* cria_FilaF(){
    FilaF* fi = (FilaF*) malloc(sizeof(FilaF));
    if(fi != NULL){
        fi->fim = NULL;
    }
    return fi;
}
void libera_Fila(Fila* fi){
    if(fi != NULL){
        Elem* no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int consulta_Fila(Fila* fi, struct aluno *al){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    *al = fi->inicio->dados;
    return 1;
}

int insere_Fila(Fila* fi, struct aluno al){
    if(fi == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if(fi->final == NULL)//fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    fi->qtd++;
    return 1;
}

int insere_FilaFilas(FilaFilas* f1, Fila* f2){
    if(f1 == NULL || f2 == NULL)
        return 0;
    Elem2 *no = (Elem2*) malloc(sizeof(Elem2));
    if(no == NULL)
        return 0;
    no->dados2 = f2;
    no->prox2 = NULL;
    if(f1->final == NULL)
        f1->inicio = no;
    else
        f1->final->prox2 = no;
    f1->final = no;
    f1->qtd++;
    return 1;
}

int insere_FilaPilhas(FilaPilhas* fi, Pilha* pi){
    if (fi == NULL || pi == NULL) return 0;
    Elem3* no = (Elem3*) malloc(sizeof(Elem3));  // <-- CORRIGIDO
    if (no == NULL) return 0;
    no->dados3 = pi;
    no->prox3 = NULL;
    if (fi->final == NULL)
        fi->inicio = no;
    else
        fi->final->prox3 = no;
    fi->final = no;
    fi->qtd++;
    return 1;
}

int insere_PilhaFilas(PilhaFilas* pi, Fila* fi) {
    if (pi == NULL || fi == NULL)
        return 0;
    ElemPilhaFila* no = (ElemPilhaFila*) malloc(sizeof(ElemPilhaFila));
    if (no == NULL)
        return 0;
    no->dados4 = fi;
    no->prox4 = *pi;
    *pi = no;
    return 1;
}
int insere_FilaF(FilaF* fi, float x) {
    if (fi == NULL){
        return 0;
    }
    Elem5* no = (Elem5*) malloc(sizeof(Elem5));
    if (no == NULL){
        return 0;
    }
    no->valor = x;
    if (fi->fim == NULL) {
        fi->fim = no;
        no->prox5 = no;
    } else {
        no->prox5 = fi->fim->prox5;
        fi->fim->prox5 = no;
        fi->fim = no;
    }
    return 1;
}

int remove_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL)//fila ficou vazia
        fi->final = NULL;
    free(no);
    fi->qtd--;
    return 1;
}

int tamanho_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    return fi->qtd;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL)
        return 1;
    if(fi->inicio == NULL)
        return 1;
    return 0;
}

int Fila_cheia(Fila* fi){
    return 0;
}

void imprime_Fila(Fila* fi){
    if(fi == NULL)
        return;
    Elem* no = fi->inicio;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }
}
imprime_FilaFilas(Fila* fi){
    if(fi == NULL){
        return;
    }
    Elem2* no = fi->inicio;
    while(no!=NULL){
        imprime_Fila(no->dados2);
        no = no->prox2;
    }

}

void imprime_FilaPilhas(FilaPilhas* fi) {
    if (fi == NULL || fi->inicio == NULL) {
        return;
    }
    Elem3* no = fi->inicio;
    while (no != NULL) {
        imprime_Pilha(no->dados3);
        no = no->prox3;
    }
}

void imprime_PilhaFilas(PilhaFilas* pi) {
    if (pi == NULL || *pi == NULL) {
        return;
    }
    ElemPilhaFila* no = *pi;
    while (no != NULL) {
        imprime_Fila(no->dados4);
        no = no->prox4;
    }
}
void imprime_FilaF(FilaF* fi) {
    if (fi == NULL || fi->fim == NULL) {
        return;
    }
    printf("Fila:\n\n");
    Elem5* no = fi->fim->prox5;
    do {
        printf("%.2f\n", no->valor);
        printf("-------------------------------\n");
        no = no->prox5;
    }while (no != fi->fim->prox5);
}
int Fila_split(Fila* f1, Fila* f2, int mat){
    if(f1 == NULL || f2 == NULL || Fila_vazia(f1) || !Fila_vazia(f2) || f1->final->dados.matricula == mat){
        return 0;
    }
    Elem *aux = f1->inicio;
    while (aux != NULL && aux->dados.matricula != mat){
        aux = aux->prox;
    }
    if(aux != NULL){
        f2->inicio = aux->prox;
        f2->final = f1->final;
        f1->final = aux;
        aux->prox = NULL;
    }else{
        return 0;
    }
    return 1;
}

int inverte_Fila(Fila* fi, Pilha* pi) {
    if (fi == NULL)
        return 0;
    struct aluno aux;
    while (!Fila_vazia(fi)){
        consulta_Fila(fi, &aux);
        insere_Pilha(pi, aux);
        remove_Fila(fi);
    }
    while (!Pilha_vazia(pi)){
        consulta_topo_Pilha(pi, &aux);
        insere_Fila(fi, aux);
        remove_Pilha(pi);
    }
    return 1;
}
int FuraFila(FilaF* fi, float x) {
    if (fi == NULL)
        return 0;
    Elem5* no = (Elem5*) malloc(sizeof(Elem5));
    if (no == NULL)
        return 0;
    no->valor = x;
    if (fi->fim == NULL) {
        no->prox5 = no;
        fi->fim = no;
    } else {
        no->prox5 = fi->fim->prox5;
        fi->fim->prox5 = no;
    }
    return 1;
}


Pilha* cria_Pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

void libera_Pilha(Pilha* pi){
    if(pi != NULL){
        Elem* no;
        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}

int consulta_topo_Pilha(Pilha* pi, struct aluno *al){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    *al = (*pi)->dados;
    return 1;
}

int insere_Pilha(Pilha* pi, struct aluno al){
    if(pi == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*pi);
    *pi = no;
    return 1;
}

int remove_Pilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    Elem *no = *pi;
    *pi = no->prox;
    free(no);
    return 1;
}

int tamanho_Pilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    int cont = 0;
    Elem* no = *pi;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int Pilha_cheia(Pilha* pi){
    return 0;
}

int Pilha_vazia(Pilha* pi){
    if(pi == NULL)
        return 1;
    if(*pi == NULL)
        return 1;
    return 0;
}

void imprime_Pilha(Pilha* pi){
    if(pi == NULL)
        return;
    Elem* no = *pi;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }
}

