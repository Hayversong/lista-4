#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME 50

typedef struct {
    char nome[NOME];
    int identificador;
    struct Aviao *prox;
} Aviao;

Aviao *inicio = NULL, *fim = NULL;
int contador = 0;

void adicionarAviao(const char *nome, int identificador) {
    Aviao *novo = (Aviao *)malloc(sizeof(Aviao));
    strcpy(novo->nome, nome);
    novo->identificador = identificador;
    novo->prox = NULL;

    if (fim == NULL) {
        inicio = fim = novo;
    } else {
        fim->prox = novo;
        fim = novo;
    }

    contador++;
    printf("Avião \"%s\" (ID: %d) adicionado à fila.\n", nome, identificador);
}


void autorizarDecolagem() {
    if (inicio == NULL) {
        printf("nenhum aviao na fila para decolar\n");
        return;
    }

    Aviao *temp = inicio;
    printf("aviao \"%s\" (ID: %d) autorizado a decolar.\n", temp->nome, temp->identificador);
    inicio = inicio->prox;
    free(temp);
    contador--;

    if (inicio == NULL) {
        fim = NULL;
    }
}

void listarNumeroAvioes() {
    printf("avioes na fila: %d\n", contador);
}

void listarTodosAvioes() {
    if (inicio == NULL) {
        printf("Fila vazia.\n");
        return;
    }

    Aviao *temp = inicio;
    printf("avioes na fila:\n");
    while (temp != NULL) {
        printf("- Nome: %s | ID: %d\n", temp->nome, temp->identificador);
        temp = temp->prox;
    }
}

void listarPrimeiroAviao() {
    if (inicio == NULL) {
        printf("Fila vazia.\n");
        return;
    }

    printf("Primeiro avião na fila:\n");
    printf("Nome: %s\n", inicio->nome);
    printf("ID: %d\n", inicio->identificador);
}


void freeFila() {
    while (inicio != NULL) {
        Aviao *temp = inicio;
        inicio = inicio->prox;
        free(temp);
    }
}

int main() {
    adicionarAviao("Aviao Azul", 101);
    adicionarAviao("Aviao Verde", 102);
    adicionarAviao("Aviao Vermelho", 103);

    listarNumeroAvioes();
    listarTodosAvioes();
    listarPrimeiroAviao();
    autorizarDecolagem();
    listarNumeroAvioes();
    listarTodosAvioes();

    freeFila();
    return 0;
}

/*a lógica aplicada foi usar as estruturas normais de uma fila e adaptá-las para o "sistema de aviação", mudei os nomes do que seriam as funções pop e push e por último, fiz uma função para liberar a memória alocada para evitar conflito, o vscode identifica alguns erros no código porém ele funciona e compila normalmente, não sei o porquê*/