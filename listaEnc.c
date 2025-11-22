#include <stdio.h>
#include <stdlib.h> // Para malloc, free, exit

// --- Estruturas ---

typedef struct No {
    int dado;
    struct No *proxNo;
} No;

typedef struct Lista {
    No *inicio;
    int tamanho;
} Lista;

// --- Funções Auxiliares ---

// Inicializa a lista para garantir que esteja vazia e com tamanho 0
void inicializaLista(Lista *lista){
    lista->inicio = NULL;
    lista->tamanho = 0;
}

// Verifica se o malloc foi bem-sucedido
No* criarNo(int valor) {
    No *novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memoria para novo no.\n");
        exit(1); // Encerra o programa em caso de falha crítica de memória
    }
    novoNo->dado = valor;
    novoNo->proxNo = NULL;
    return novoNo;
}

// --- Funções de Inserção ---

// Insere um novo nó no início da lista
void inserirInicio(Lista *lista, int valor){
    No *novoNo = criarNo(valor); // Usa a função auxiliar para criar o nó
    novoNo->proxNo = lista->inicio; // O novo nó aponta para o antigo início
    lista->inicio = novoNo;         // O novo nó se torna o início
    lista->tamanho++;
}

// Insere um novo nó no fim da lista
void inserirFim(Lista *lista, int valor){
    No *novoNo = criarNo(valor); // Cria o novo nó

    if(lista->inicio == NULL){   // Se a lista estiver vazia, o novo nó é o primeiro
        lista->inicio = novoNo;
    } else {                     // Se a lista não estiver vazia, percorre até o fim
        No *atual = lista->inicio;
        while(atual->proxNo != NULL){
            atual = atual->proxNo;
        }
        atual->proxNo = novoNo; // O último nó existente aponta para o novo nó
    }
    lista->tamanho++;
}

// --- Funções de Remoção ---

// Remove o nó do início da lista
void removerInicio(Lista *lista){
    if (lista->inicio == NULL) { // Verifica se a lista não está vazia
        printf("Lista vazia, nada para remover do inicio.\n");
        return;
    }
    No *temp = lista->inicio;             // Guarda o nó a ser removido
    lista->inicio = lista->inicio->proxNo; // O início agora é o próximo nó
    free(temp);                           // Libera a memória do nó removido
    lista->tamanho--;
}

// Remove o nó do fim da lista
void removerFim(Lista *lista) {
    if (lista->inicio == NULL) { // Lista vazia, nada para remover
        printf("Lista vazia, nada para remover do fim.\n");
        return;
    }

    if (lista->inicio->proxNo == NULL) { // Se há apenas um nó na lista
        free(lista->inicio);
        lista->inicio = NULL; // A lista se torna vazia
    } else { // Se há dois ou mais nós
        No *atual = lista->inicio;
        // Percorre até o penúltimo nó
        while (atual->proxNo->proxNo != NULL) {
            atual = atual->proxNo;
        }
        free(atual->proxNo);   // Libera o último nó
        atual->proxNo = NULL;  // O penúltimo nó agora aponta para NULL
    }
    lista->tamanho--;
}

// --- Funções de Exibição e Liberação ---

// Exibe os elementos da lista
void exibir(Lista *lista) {
    No *atual = lista->inicio;
    printf("Lista (Tamanho: %d): ", lista->tamanho);
    if (atual == NULL) {
        printf("[Vazia]\n");
        return;
    }
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->proxNo;
    }
    printf("\n");
}

// Libera toda a memória alocada pela lista
void liberarLista(Lista *lista) {
    No *atual = lista->inicio;
    No *proximo;
    while (atual != NULL) {
        proximo = atual->proxNo;
        free(atual); // Libera o nó atual
        atual = proximo; // Avança para o próximo nó
    }
    lista->inicio = NULL; // Zera o ponteiro de início
    lista->tamanho = 0;   // Zera o tamanho
    printf("Toda a memória da lista foi liberada.\n");
}


// --- Função Principal (main) para Teste ---
int main() {
    Lista minhaLista;
    inicializaLista(&minhaLista);

    printf("--- Testando Inserções ---\n");
    exibir(&minhaLista); // Lista vazia

    inserirInicio(&minhaLista, 10);
    exibir(&minhaLista); // Lista: 10
    inserirFim(&minhaLista, 20);
    exibir(&minhaLista); // Lista: 10 20
    inserirInicio(&minhaLista, 5);
    exibir(&minhaLista); // Lista: 5 10 20
    inserirFim(&minhaLista, 25);
    exibir(&minhaLista); // Lista: 5 10 20 25

    printf("\n--- Testando Remoções ---\n");
    removerInicio(&minhaLista);
    exibir(&minhaLista); // Lista: 10 20 25
    removerFim(&minhaLista);
    exibir(&minhaLista); // Lista: 10 20
    removerFim(&minhaLista);
    exibir(&minhaLista); // Lista: 10
    removerInicio(&minhaLista);
    exibir(&minhaLista); // Lista: [Vazia]

    printf("\n--- Testando Remoção em Lista Vazia ---\n");
    removerInicio(&minhaLista); // Deve exibir mensagem de lista vazia
    removerFim(&minhaLista);    // Deve exibir mensagem de lista vazia

    printf("\n--- Testando Inserir Fim em Lista Vazia (depois de esvaziar) ---\n");
    inserirFim(&minhaLista, 100);
    exibir(&minhaLista); // Lista: 100

    printf("\n--- Liberando Memória ---\n");
    liberarLista(&minhaLista);
    exibir(&minhaLista); // Lista: [Vazia]

    return 0;
}