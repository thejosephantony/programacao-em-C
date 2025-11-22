#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *proxNo;
    struct No *antNo;
} tipoNo;

typedef struct {
    tipoNo *inicio;
    tipoNo *fim;
    int tamanho;
} tipoLista;

// Inicializa a lista
void inicializaLista(tipoLista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

// Cria um novo nó
tipoNo* criarNo(int valor) {
    tipoNo *novoNo = (tipoNo*)malloc(sizeof(tipoNo));
    if (novoNo == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    novoNo->dado = valor;
    novoNo->proxNo = NULL;
    novoNo->antNo = NULL;
    return novoNo;
}

// Insere no início da lista
void inserirInicio(tipoLista *lista, int valor) {
    tipoNo *novoNo = criarNo(valor);

    if(lista->inicio == NULL) { // Lista vazia
        lista->inicio = novoNo;
        lista->fim = novoNo;
        novoNo->proxNo = novoNo;
        novoNo->antNo = novoNo;
    } else {
        novoNo->proxNo = lista->inicio;
        novoNo->antNo = lista->fim;
        lista->inicio->antNo = novoNo;
        lista->fim->proxNo = novoNo;
        lista->inicio = novoNo;
    }
    lista->tamanho++;
}

// Insere no final da lista
void inserirFim(tipoLista *lista, int valor) {
    tipoNo *novoNo = criarNo(valor);

    if(lista->inicio == NULL) { // Lista vazia
        lista->inicio = novoNo;
        lista->fim = novoNo;
        novoNo->proxNo = novoNo;
        novoNo->antNo = novoNo;
    } else {
        novoNo->proxNo = lista->inicio;
        novoNo->antNo = lista->fim;
        lista->fim->proxNo = novoNo;
        lista->inicio->antNo = novoNo;
        lista->fim = novoNo;
    }
    lista->tamanho++;
}

// Exibe a lista do início ao fim
void exibirLista(tipoLista *lista) {
    if (lista->inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    
    tipoNo *atual = lista->inicio;
    printf("Lista: ");
    
    do {
        printf("%d ", atual->dado);
        atual = atual->proxNo;
    } while (atual != lista->inicio);
    
    printf("\n");
}

// Remove o primeiro nó da lista
void removerInicio(tipoLista *lista) {
    if (lista->inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    
    if (lista->inicio == lista->fim) { // Único nó
        free(lista->inicio);
        lista->inicio = NULL;
        lista->fim = NULL;
    } else {
        tipoNo *temp = lista->inicio;
        lista->inicio = lista->inicio->proxNo;
        lista->inicio->antNo = lista->fim;
        lista->fim->proxNo = lista->inicio;
        free(temp);
    }
    lista->tamanho--;
}

// Remove o último nó da lista
void removerFim(tipoLista *lista) {
    if (lista->fim == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    
    if (lista->inicio == lista->fim) { // Único nó
        free(lista->fim);
        lista->inicio = NULL;
        lista->fim = NULL;
    } else {
        tipoNo *temp = lista->fim;
        lista->fim = lista->fim->antNo;
        lista->fim->proxNo = lista->inicio;
        lista->inicio->antNo = lista->fim;
        free(temp);
    }
    lista->tamanho--;
}

// Pesquisa um elemento na lista
void pesquisarElemento(tipoLista *lista, int valor) {
    if (lista->inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    
    tipoNo *atual = lista->inicio;
    int posicao = 1;
    int encontrado = 0;
    
    do {
        if (atual->dado == valor) {
            printf("Elemento %d encontrado na posicao %d\n", valor, posicao);
            encontrado = 1;
        }
        atual = atual->proxNo;
        posicao++;
    } while (atual != lista->inicio);
    
    if (!encontrado) {
        printf("Elemento %d nao encontrado na lista\n", valor);
    }
}

// Destrói a lista inteira
void destruirLista(tipoLista *lista) {
    while (lista->inicio != NULL) {
        removerInicio(lista);
    }
}

// Menu interativo
void menu() {
    tipoLista lista;
    inicializaLista(&lista);
    int opcao, valor;
    
    do {
        printf("\n--- Menu Lista Circular Duplamente Encadeada ---\n");
        printf("1. Inserir no inicio\n");
        printf("2. Inserir no fim\n");
        printf("3. Remover do inicio\n");
        printf("4. Remover do fim\n");
        printf("5. Exibir lista\n");
        printf("6. Pesquisar elemento\n");
        printf("7. Tamanho da lista\n");
        printf("8. Destruir lista\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                printf("Valor: ");
                scanf("%d", &valor);
                inserirInicio(&lista, valor);
                break;
            case 2:
                printf("Valor: ");
                scanf("%d", &valor);
                inserirFim(&lista, valor);
                break;
            case 3:
                removerInicio(&lista);
                break;
            case 4:
                removerFim(&lista);
                break;
            case 5:
                exibirLista(&lista);
                break;
            case 6:
                printf("Valor a pesquisar: ");
                scanf("%d", &valor);
                pesquisarElemento(&lista, valor);
                break;
            case 7:
                printf("Tamanho da lista: %d\n", lista.tamanho);
                break;
            case 8:
                destruirLista(&lista);
                printf("Lista destruida!\n");
                break;
            case 0:
                destruirLista(&lista);
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

int main() {
    menu();
    return 0;
}