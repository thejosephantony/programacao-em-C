#include <stdio.h>
#include <stdlib.h>

int maximo = 0;
int quantElem = 0;

int* criarLista(){
    int *vetor;
    vetor = (int*)malloc(maximo * sizeof(int));
    if(!vetor){
        printf("A memoria nao foi alocada. \n");
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
        return 0;
    }
    return -1;
}



int pesquisaSequencial(int *vetor, int elemento){
    for(int i = 0; i < quantElem; i++){
        if(vetor[i] == elemento){
            return i;
        }
    }
    return -1; // Elemento não encontrado
}

int exibaLista(int *vetor){
    printf("Lista: \n");
    printf("[");
    for(int x = 0; x < quantElem; x++){
        printf("%d", vetor[x]);
        printf(", ");
    }
    printf("]\n");
}

int main(){
    int *lista, op;
    printf("Digite quantos elementos quer ter na lista: ");
    scanf("%d", &maximo);
    lista = criarLista();

    do{
        printf("\n ---- MENU ---- \n");
        printf("1 - Insercao nao ordenada\n");
        printf("2 - Pesquisa sequencial\n");
        printf("3 - Exibir lista\n");
        printf("0 - Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &op);

        switch(op){
            case 1:
            insercaoNaoOrd(lista);
            break;
            case 2:{
                int aux;
                printf("Digite o elemento que deseja procurar: ");
                scanf("%d", &aux);
                int resposta = pesquisaSequencial(lista, aux);
                if (resposta == -1){
                    printf("Elemento nao encontrado. \n");
                }
                else{
                    printf("O elemento foi encontrado na posicao %d do vetor. \n", resposta);
                }
                }
            break;
            case 3:
                exibaLista(lista);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
            }
        } while(op != 0);
    }