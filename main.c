#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"
int main(){
    struct aluno al,a[4] = {{1,"Andre",9.5,7.8,8.5},
                            {2,"Ricardo",7.5,8.7,6.8},
                            {3,"Bianca",9.7,6.7,8.4},
                            {4,"Ana",5.7,6.1,7.4}};
    int escolha =0;
    printf("Escolha um exercicio para testar:\n 1: Separador de filas\n 2: Fila de filas, fila de pilhas e pilha de filas\n 3: Inverter os valores de uma fila usando uma pilha vazia\n 4: filas circulares\n");
    scanf("%d", &escolha);
    system("cls");
    if(escolha == 1 ){
    /*
    1) Considerando filas, implemente um método que receba como parâmetro
        a referência f1 e um valor de matrícula n e dívida a fila em duas, de tal
        forma que a segunda fila comece no primeiro nó logo após a primeira
        ocorrência de n na fila original. Esse método deve ser da seguinte
        assinatura:
        int separa(Fila f1, Fila f2, matricula n)
        Dentro do método separa, a segunda fila deve ser apontada pela
        referência f2, enquanto f1 deve continuar apontando para o início da fila
        anterior.
    */
        Fila* fi = cria_Fila();
        for(int i=0; i < 4; i++){
            insere_Fila(fi,a[i]);
            if(Fila_vazia(fi))
                printf("Erro!!!!!!\n");
        }
        imprime_Fila(fi);
        Fila* f2 = cria_Fila();
        int escolha = 0;
        printf("Digite um numero de matricula para dividir a fila:\n");
        scanf("%d",&escolha);
        Fila_split(fi,f2,escolha);
        printf("\n\n\nFila 1:\n\n");
        imprime_Fila(fi);
        printf("\n\n\nFila 2:\n\n");
        imprime_Fila(f2);
        libera_Fila(fi);
        libera_Fila(f2);
        /*
        lógica usada: A fila eh percorrida ate encontrar a matricula lancada,
        ai quando ela eh econtrada, o inicio da fila dois passa a ser o proximo
        elemento da matricula encontrada, o final da fila dois eh o mesmo da fila 1
        ate entao, e depois o final da fila 1 eh a posicao que a matricula foi encontrada
        */
    } else if(escolha==2){
        /*
        2) Implemente as seguintes combinações de estruturas de dados com fila:
            a. Uma fila de filas;
            b. Uma fila de pilhas;
            c. Uma pilha de filas;
        */
        printf("\n\nFila de filas:\n\n");
        Fila* filaFilas = cria_Fila();
        Fila* fila1 = cria_Fila();
        Fila* fila2 = cria_Fila();
        struct aluno fernando = {1, "Fernando", 9.0, 8.0, 10.0};
        struct aluno hayverson = {2, "Hayverson", 9.0, 8.0, 10.0};
        insere_Fila(fila1, fernando);
        insere_Fila(fila2, hayverson);
        insere_FilaFilas(filaFilas, fila1);
        insere_FilaFilas(filaFilas, fila2);
        imprime_FilaFilas(filaFilas);

        printf("\n\nFila de pilhas:\n\n");
        Fila* filaPilhas = cria_Fila();
        Pilha* pilha1 = cria_Pilha();
        Pilha* pilha2 = cria_Pilha();
        insere_Pilha(pilha1, fernando);
        insere_Pilha(pilha2, hayverson);
        insere_FilaPilhas(filaPilhas, pilha1);
        insere_FilaPilhas(filaPilhas, pilha2);
        imprime_FilaPilhas(filaPilhas);

        printf("\n\Pilha de filas:\n\n");
        Pilha* pilhaFilas = cria_Pilha();
        insere_PilhaFilas(pilhaFilas, fila1);
        insere_PilhaFilas(pilhaFilas, fila2);
        imprime_PilhaFilas(pilhaFilas);

        libera_Fila(filaFilas);
        libera_Fila(fila1);
        libera_Fila(fila2);
        libera_Fila(filaPilhas);
        libera_Pilha(pilha1);
        libera_Pilha(pilha2);
        /*
        lógica usada: Foram usadas as mesmas logicas das estruturas que ja tinha
        criado, so foram feitas as alteracoes para permitir fazer o que foi pedido
        */
    } else if(escolha == 3){
        /*
        3) Considere uma pilha P vazia e uma fila F não vazia. Utilizando apenas
            os testes de fila e pilha vazias, as operações Enfileira, Desenfileira,
            Empilha, Desempilha, e uma variável aux inteira, escreva um programa
            que inverte a ordem dos elementos da fila.
        */
        Pilha* pilha = cria_Pilha();
        Fila* fi = cria_Fila();
        for(int i=0; i < 4; i++){
            insere_Fila(fi,a[i]);
            if(Fila_vazia(fi))
                printf("Erro!!!!!!\n");
        }
        printf("\n\nFila original:\n\n");
        imprime_Fila(fi);

        printf("\n\nFila em ordemm invertida:\n\n");
        inverte_Fila(fi, pilha);
        imprime_Fila(fi);
        libera_Fila(fi);
        libera_Pilha(pilha);
        /*
        lógica usada: Todos os itens da fila foram movidos para a pilha, depois
        a fila foi esvaziada, depois foi so mover todos os itens da pilha para a
        fila de novo
        */

    } else if(escolha == 4){
        /*
        4) Considere a implementação de filas usando a característica de filas
            “circulares”, pesquise sobre o assunto. Escreva uma função
            FuraFila(Fila* f, float x) que insere um item na primeira posição da fila. O
            detalhe é que seu procedimento deve ser O(1), ou seja, não pode
            movimentar os outros itens da fila. (observe que este neste caso,
            estaremos desrespeitando o conceito de FILA – primeiro a entrar é o
            primeiro a sair). Altere também a função de percorrer a Fila para que ela
            se aproveite da característica da fila circular.
        */
        FilaF* fi = cria_FilaF();
        insere_FilaF(fi, 8.0);
        insere_FilaF(fi, 2.0);
        insere_FilaF(fi, 7.0);
        imprime_FilaF(fi);
        float x;
        printf("Valor a ser inserido:\n");
        scanf("%f",&x);
        FuraFila(fi, x);
        imprime_FilaF(fi);
        libera_Fila(fi);
        /*
        Logica usada: basicamente a estrutura da fila circular permite fazer
        com que o ponteiro do fi->fim->prox aponte pro primeiro elemento,
        então, mesmo que tenha sido o ultimo a entrar, tem como colocar
        ele logo depois do fim->fim, que eh o comeco da fila, fazendo ele
        apontar pro antigo primeiro, virando o novo primeiro
        */
    }


    system("pause");
    return 0;
}


