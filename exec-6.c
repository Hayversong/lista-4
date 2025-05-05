#include <stdio.h>
#include <stdlib.h>

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


int fila_Vazia(Fila *f) {
    return f->frente > f->fim;
}

// Enfileira um elemento
void push(Fila *f, int valor) {
    if (f->fim < TAM_MAX - 1) {
        f->fim++;
        f->dados[f->fim] = valor;
    } else {
        printf("Fila cheia!\n");
    }
}

int pop(Fila *f) {
    if (!fila_Vazia(f)) {
        return f->dados[f->frente++];
    } else {
        printf("Fila vazia!\n");
        return -1;
    }
}

int frente(Fila *f) {
    if (!fila_Vazia(f)) {
        return f->dados[f->frente];
    }
        return -1;
}

void mesclarFilas(Fila *f1, Fila *f2, Fila *resultado) {
    while (!fila_Vazia(f1) && !fila_Vazia(f2)) {
        if (frente(f1) <= frente(f2)) {
            push(resultado, pop(f1));
        } else {
            push(resultado, pop(f2));
        }
    }

    while (!fila_Vazia(f1)) {
        push(resultado, pop(f1));
    }

    while (!fila_Vazia(f2)) {
        push(resultado, pop(f2));
    }
}

void imprimirFila(Fila *f) {
    for (int i = f->frente; i <= f->fim; i++) {
        printf("%d ", f->dados[i]);
    }
}

int main() {
    Fila fila1, fila2, filaResultado;

    inicializarFila(&fila1);
    inicializarFila(&fila2);
    inicializarFila(&filaResultado);

    //fila1
    push(&fila1, 1);
    push(&fila1, 3);
    push(&fila1, 5);

    //fila2
    push(&fila2, 2);
    push(&fila2, 4);
    push(&fila2, 6);

    //juntando as duas filas
    mesclarFilas(&fila1, &fila2, &filaResultado);

    printf("Fila resultante:\n");
    imprimirFila(&filaResultado);

    return 0;
}

/*seguindo a ideia de que a fila cresce da esquerda pra direita no vetor, a função push move o ponteiro da frente para direita sem realocar nada, então enquanto as duas filas tem elementos, o elemento de cada uma das filas vai ser comparado e quando as filas 1 e 2 acabarem os elementos vão ser colocados na fila de resultado*/