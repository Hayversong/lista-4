#include <stdio.h>

#define TAM_MAX 100

typedef struct {
    int dados[TAM_MAX];
    int frente;
    int fim;
} Fila;

void inicializarFila(Fila *f) {
    f->frente = 0;
    f->fim = -1;
}

int filaVazia(Fila *f) {
    return f->frente > f->fim;
}

void push(Fila *f, int valor) {
    if (f->fim < TAM_MAX - 1) {
        f->fim++;
        f->dados[f->fim] = valor;
    } else {
        printf("fila cheia\n");
    }
}

int pop(Fila *f) {
    if (!filaVazia(f)) {
        return f->dados[f->frente++];
    } else {
        printf("fila vazia\n");
        return -1;
    }
}

void imprimirFila(Fila *f) {
    for (int i = f->frente; i <= f->fim; i++) {
        printf("%d ", f->dados[i]);
    }
    printf("\n");
}

void reverso(Fila *f) {
    int i = f->frente;
    int j = f->fim;

    while (i < j) {
        int temp = f->dados[i];
        f->dados[i] = f->dados[j];
        f->dados[j] = temp;
        i++;
        j--;
    }
}

int main() {
    Fila f;
    inicializarFila(&f);

    push(&f, 10);
    push(&f, 20);
    push(&f, 30);
    push(&f, 40);
    push(&f, 50);

    printf("Fila original: \n");
    imprimirFila(&f);

    reverso(&f);

    printf("Fila invertida: \n");
    imprimirFila(&f);

    return 0;
}

/*a lógica utilizada para implementar a função foi fazer um laço de repetição que compara os elementos da fila e reordena eles ao contrário*/