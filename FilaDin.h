
struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};


typedef struct fila Fila;
typedef struct filafilas FilaFilas;
typedef struct filapilhas FilaPilhas;
typedef struct elemento* Pilha;
typedef struct elemento* PilhaFilas;
typedef struct filaf FilaF;

Pilha* cria_Pilha();
Fila* cria_Fila();
FilaFilas* cria_FilaFilas();
FilaPilhas* cria_FilaPilhas();
PilhaFilas* cria_PilhaFilas();
FilaF* cria_FilaF();

void libera_Fila(Fila* fi);
int consulta_Fila(Fila* fi, struct aluno *al);
int insere_Fila(Fila* fi, struct aluno al);
int insere_FilaFilas(FilaFilas* f1, Fila* f2);
int insere_FilaPilhas(FilaPilhas* fi, Pilha* pi);
int insere_PilhaFilas(PilhaFilas* pi, Fila* fi);
int insere_FilaF(FilaF* fi, float x);
int remove_Fila(Fila* fi);
int tamanho_Fila(Fila* fi);
int Fila_vazia(Fila* fi);
int Fila_cheia(Fila* fi);
void imprime_Fila(Fila* fi);
void imprime_FilaPilhas(FilaPilhas* fi);
void imprime_PilhaFilas(PilhaFilas* pi);
void imprime_FilaF(FilaF* fi);
int Fila_split(Fila* f1, Fila* f2, int mat);
int inverte_Fila(Fila* fi, Pilha* pi);
int FuraFila(FilaF* fi, float x);

void libera_Pilha(Pilha* pi);
int consulta_topo_Pilha(Pilha* pi, struct aluno *al);
int insere_Pilha(Pilha* pi, struct aluno al);
int remove_Pilha(Pilha* pi);
int tamanho_Pilha(Pilha* pi);
int Pilha_vazia(Pilha* pi);
int Pilha_cheia(Pilha* pi);
void imprime_Pilha(Pilha* pi);



