#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define TAMANHO_FILA 100
#define TRUE 1
#define FALSE 0

typedef struct {
    int elementos[TAMANHO_FILA];
    int inicio;
    int fim;
    int quantidade;
} Fila;

void inicializaFila(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
    f->quantidade = 0;
}

int filaVazia(Fila *f) {
    return (f->quantidade == 0);
}

int filaCheia(Fila *f) {
    return (f->quantidade == TAMANHO_FILA);
}

int push(Fila *f, int valor) {
    if (filaCheia(f)) {
        return FALSE;
    }
    f->fim = (f->fim + 1) % TAMANHO_FILA;
    f->elementos[f->fim] = valor;
    f->quantidade++;
    return TRUE;
}

int pop(Fila *f, int *valor) {
    if (filaVazia(f)) {
        return FALSE;
    }
    *valor = f->elementos[f->inicio];
    f->inicio = (f->inicio + 1) % TAMANHO_FILA;
    f->quantidade--;
    return TRUE;
}

int inicioFila(Fila *f, int *valor) {
    if (filaVazia(f)) {
        return FALSE;
    }
    *valor = f->elementos[f->inicio];
    return TRUE;
}

void furarFila(Fila *f, int valor) {
    if (filaCheia(f)) {
        return;
    }
    
    if (filaVazia(f)) {
        push(f, valor);
        return;
    }
    
    int pos = (f->inicio - 1 + TAMANHO_FILA) % TAMANHO_FILA;
    f->inicio = pos;
    f->elementos[pos] = valor;
    f->quantidade++;
}

void menu() {
    printf("\n Menu de Operacoes com Fila: \n");
    printf("1-Inicializa fila\n");
    printf("2-Verifica se a fila ta vazia\n");
    printf("3-Verifica se a fila ta cheia\n");
    printf("4-Push\n");
    printf("5-Pop\n");
    printf("6-Le o numero no inicio da fila\n");
    printf("7-Testar qual fila possui mais elementos\n");
    printf("8-Furar a fila\n");
    printf("9-Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    Fila fila1, fila2;
    int opcao, valor;
    int usandoFila1 = TRUE; 
    
    inicializaFila(&fila1);
    inicializaFila(&fila2);
    
    opcao = 0;
    
    while (opcao != 9) {
        menu();
        scanf("%d", &opcao);
        
        Fila *filaAtual = usandoFila1 ? &fila1 : &fila2;
        
        switch(opcao) {
            case 1:
                inicializaFila(filaAtual);
                printf("fila %d inicializada.\n", usandoFila1 ? 1 : 2);
                break;
                
            case 2:
                if (filaVazia(filaAtual)) {
                    printf("a fila %d esta vazia.\n", usandoFila1 ? 1 : 2);
                } else {
                    printf("a fila %d nao esta vazia.\n", usandoFila1 ? 1 : 2);
                }
                break;
                
            case 3:
                if (filaCheia(filaAtual)) {
                    printf("a fila %d esta cheia.\n", usandoFila1 ? 1 : 2);
                } else {
                    printf("a fila %d nao esta cheia.\n", usandoFila1 ? 1 : 2);
                }
                break;
                
            case 4:
                printf("digite o valor a ser adicionado: ");
                scanf("%d", &valor);
                if (push(filaAtual, valor)) {
                    printf("valor %d adicionado na fila %d.\n", valor, usandoFila1 ? 1 : 2);
                } else {
                    printf("fila %d cheia\n", usandoFila1 ? 1 : 2);
                }
                break;
                
            case 5:
                if (pop(filaAtual, &valor)) {
                    printf("valor %d removido da fila %d\n", valor, usandoFila1 ? 1 : 2);
                } else {
                    printf("fila %d vazia!\n", usandoFila1 ? 1 : 2);
                }
                break;
                
            case 6:
                if (inicioFila(filaAtual, &valor)) {
                    printf("inicio da fila %d: %d\n", usandoFila1 ? 1 : 2, valor);
                } else {
                    printf("fila %d vazia\n", usandoFila1 ? 1 : 2);
                }
                break;
                
            case 7:
                if (fila1.quantidade > fila2.quantidade) {
                    printf("fila 1 tem mais elementos (%d) que Fila 2 (%d).\n", fila1.quantidade, fila2.quantidade);
                } else if (fila2.quantidade > fila1.quantidade) {
                    printf("fila 2 tem mais elementos (%d) que Fila 1 (%d).\n", fila2.quantidade, fila1.quantidade);
                } else {
                    printf("as filas tem a mesma quantidade de elementos (%d).\n", fila1.quantidade);
                }
                break;
                
            case 8:
                printf("digite o valor para furar a fila: ");
                scanf("%d", &valor);
                furarFila(filaAtual, valor);
                printf("valor %d inserido no inicio da fila %d.\n", valor, usandoFila1 ? 1 : 2);
                break;
                
            case 9:
                printf("fechando o programa...\n");
                break;
            default:
                printf("opcao invalida\n");
        }
    }
    
    return 0;
}

/*a lógica usada foi pegar todas as operações já conhecidas de fila e aplicar nas funções do programa para garantir não ter erros e pder focar na main, tive certos problemas para ver qual fila era maior mas me toquei que bastava usar a "quantidade" que dava pra comparar sem problema nenhum, todas as operações do menu tem funções separardas e no programa e para deixar o programa mais funcional e legível, usei switch case para cada uma das opções do menu*/