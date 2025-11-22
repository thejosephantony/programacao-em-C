#include <stdio.h>
#include <stdlib.h> // Para malloc, free, exit

int quantElem = 0;
int maximo = 4;

int* criarLista(){
    int *vetor;
    vetor = (int*) malloc(maximo * sizeof(int));
    if(!vetor){
        printf("a memoria nao foi alocada");
        exit(1);
    }
    return vetor;
}

int insercaoNaoOrd(int *vetor){
    if (quantElem < maximo){
        int valor;
        printf("Insira um valor: ");
        scanf("%d", &valor);
        vetor[quantElem] = valor;
        quantElem++;
        return 0; // Sucesso
    }
    else {
        return -1;
    } // Lista cheia, falha na inserção
}

int exibaLista(int *vetor){
    printf("Lista: \n");
    printf("[");
    for(int x = 0; x < quantElem; x++){
        printf("%5d", vetor[x]);
        printf(", ");
    }
    printf("]\n");
}

int main(){
    int *lista, op;

    printf("Digite quantos elementos quer na lista: ");
    scanf("%d", &maximo);
    lista = criarLista();

    do{
        printf("\n --- Menu --- \n");
        printf("1 - Insercao nao ord \n");
        printf("2 - Exibir lista \n");
        printf("0 - Sair \n");
        printf("Digite sua opcao:");
        scanf("%d", &op);

        switch(op){
            case 1:
                insercaoNaoOrd(lista);
                printf("\nElemento inserido com sucesso.\n");
                break;
                case 2:
                exibaLista(lista);
                break;
                case 0:
                printf("\n programa encerrado. \n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }
    } while(op != 0);
    }