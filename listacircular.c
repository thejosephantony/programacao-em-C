#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *proxNo;
} No;

// Cria uma lista circular com um único nó
No* criarListaCircular(int valor) {
    No *novoNo = (No*)malloc(sizeof(No));
    if(novoNo == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    novoNo->dado = valor;
    novoNo->proxNo = novoNo; // Aponta para si mesmo
    return novoNo;
}

// Insere no início da lista circular
No* inserirNoInicio(No *ultimo, int valor) {
    if(ultimo == NULL) {
        return criarListaCircular(valor);
    }

    No *novoNo = (No*)malloc(sizeof(No));
    if(novoNo == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    novoNo->dado = valor;
    novoNo->proxNo = ultimo->proxNo;
    ultimo->proxNo = novoNo;
    return ultimo;
}

// Insere no final da lista circular
No* inserirNoFim(No *ultimo, int valor) {
    if(ultimo == NULL) {
        return criarListaCircular(valor);
    }

    No *novoNo = (No*)malloc(sizeof(No));
    if(novoNo == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    novoNo->dado = valor;
    novoNo->proxNo = ultimo->proxNo;
    ultimo->proxNo = novoNo;
    return novoNo; // Retorna o novo último nó
}

// Exibe a lista circular
void exibirLista(No *ultimo) {
    if(ultimo == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No *atual = ultimo->proxNo;
    printf("Lista: ");

    do {
        printf("%d ", atual->dado);
        atual = atual->proxNo;
    } while(atual != ultimo->proxNo);

    printf("\n");
}

// Remove o primeiro nó da lista circular
No* removerDaFrente(No *ultimo) {
    if(ultimo == NULL) {
        printf("Lista vazia.\n");
        return NULL;
    }

    // Caso com apenas um nó
    if(ultimo->proxNo == ultimo) {
        free(ultimo);
        return NULL;
    }

    No *primeiro = ultimo->proxNo;
    ultimo->proxNo = primeiro->proxNo;
    free(primeiro);
    return ultimo;
}

// Pesquisa um elemento na lista circular
No* pesquisar(No *ultimo, int valor) {
    if(ultimo == NULL) {
        printf("Lista vazia.\n");
        return NULL;
    }

    No *atual = ultimo->proxNo;
    do {
        if(atual->dado == valor) {
            return atual;
        }
        atual = atual->proxNo;
    } while(atual != ultimo->proxNo);
    
    printf("Elemento %d nao encontrado na lista.\n", valor);
    return NULL;
}

// Destrói toda a lista circular
No* destruirLista(No *ultimo) {
    if(ultimo == NULL) {
        return NULL;
    }

    No *atual = ultimo->proxNo;
    No *temp;

    while(atual != ultimo) {
        temp = atual;
        atual = atual->proxNo;
        free(temp);
    }

    free(ultimo);
    return NULL;
}

// Menu interativo para testar a lista circular
int main() {
    No *ultimo = NULL;
    int opcao, valor;

    do {
        printf("\n--- Menu Lista Circular ---\n");
        printf("1. Inserir em lista vazia\n");
        printf("2. Exibir lista\n");
        printf("3. Inserir no inicio\n");
        printf("4. Inserir no fim\n");
        printf("5. Remover da frente\n");
        printf("6. Pesquisar elemento\n");
        printf("7. Destruir lista\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Valor: ");
                scanf("%d", &valor);
                ultimo = criarListaCircular(valor);
                break;
            case 2:
                exibirLista(ultimo);
                break;
            case 3:
                printf("Valor: ");
                scanf("%d", &valor);
                ultimo = inserirNoInicio(ultimo, valor);
                break;
            case 4:
                printf("Valor: ");
                scanf("%d", &valor);
                ultimo = inserirNoFim(ultimo, valor);
                break;
            case 5:
                ultimo = removerDaFrente(ultimo);
                break;
            case 6:
                printf("Valor a pesquisar: ");
                scanf("%d", &valor);
                No *resultado = pesquisar(ultimo, valor);
                if(resultado != NULL) {
                    printf("Elemento encontrado!\n");
                }
                break;
            case 7:
                ultimo = destruirLista(ultimo);
                printf("Lista destruida!\n");
                break;
            case 0:
                ultimo = destruirLista(ultimo);
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 0);

    return 0;
}