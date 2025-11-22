#include <stdio.h>
#include <stdlib.h> // Para malloc, free, exit

// --- Variáveis Globais ---
// quantElem: Quantidade atual de elementos na lista.
// maximo: Capacidade máxima da lista (tamanho alocado do vetor).
int quantElem = 0;
int maximo = 0;

// --- Funções de Manipulação da Lista ---

/*
 * Cria uma lista vazia com a capacidade definida por 'maximo'.
 * Retorna um ponteiro para o início da memória alocada.
 * 'quantElem' é inicializado para 0, indicando uma lista vazia.
 */
int* criaLista(){
    int *vetor;
    vetor = (int*) malloc(maximo * sizeof(int));
    if(!vetor){
        printf("\nOcorreu um erro! A memoria não foi alocada.");
        exit(1);
    }
    quantElem = 0; // A lista começa vazia
    printf("\nLista criada com capacidade de %d elementos.\n", maximo);
    return vetor;
}

/*
 * Insere um elemento de forma não ordenada no final do vetor.
 * Retorna 0 em caso de sucesso e -1 se a lista estiver cheia.
 */
int insercaoNaoOrd(int *vetor){
    if (quantElem < maximo){
        int valor;
        printf("Insira um valor: ");
        scanf("%d", &valor);
        vetor[quantElem] = valor;
        quantElem++;
        return 0; // Sucesso
    } else {
        return -1; // Lista cheia, falha na inserção
    }
}

/*
 * Realiza uma pesquisa sequencial no vetor.
 * Percorre apenas os elementos válidos ('quantElem').
 * Retorna o índice do elemento se encontrado, ou -1 caso contrário.
 */
int pesquisaSequencial(int *vetor, int elemento){
    for(int i = 0; i < quantElem; i++){
        if (vetor[i] == elemento){
            return i; // Elemento encontrado
        }
    }
    return -1; // Elemento não encontrado
}

/*
 * Remove um elemento de uma lista não ordenada.
 * A remoção é eficiente (O(1) após a busca) pois a ordem não é mantida.
 * Retorna 0 em caso de sucesso e -1 se o elemento não for encontrado ou lista vazia.
 */
int remocaoNo(int *vetor, int elemento){
    if (quantElem == 0) {
        printf("Erro: A lista está vazia. Nenhuma remoção pode ser feita.\n");
        return -1;
    }

    int indiceEncontrado = pesquisaSequencial(vetor, elemento);

    if(indiceEncontrado != -1){
        vetor[indiceEncontrado] = vetor[quantElem - 1]; // Substitui pelo último
        quantElem--; // Decrementa o contador
        return 0; // Sucesso
    } else {
        return -1; // Falha (elemento não encontrado)
    }
}

/*
 * Insere um elemento em uma lista linear sequencial ordenada (em ordem crescente).
 * Retorna 0 em caso de sucesso, -1 se a lista estiver cheia.
 */
int insercaoOrdenada(int *vetor) {
    if (quantElem == maximo) {
        printf("Erro: Lista cheia. Inserção ordenada não realizada.\n");
        return -1;
    }

    int valor;
    printf("Insira o valor a ser inserido (mantendo a ordem): ");
    scanf("%d", &valor);

    int pos = 0;
    while (pos < quantElem && vetor[pos] < valor) {
        pos++; // Encontra a posição correta
    }

    for (int i = quantElem; i > pos; i--) {
        vetor[i] = vetor[i - 1]; // Desloca para a direita
    }

    vetor[pos] = valor; // Insere o valor
    quantElem++; // Atualiza o contador

    printf("Elemento %d inserido na posição %d com sucesso.\n", valor, pos);
    return 0; // Sucesso
}

/*
 * Realiza uma pesquisa binária em um vetor ORDENADO.
 * Retorna o índice do elemento se encontrado, ou -1 caso contrário.
 */
int pesquisaBinaria(int *vetor, int elemento) {
    int inicio = 0;
    int fim = quantElem - 1;
    int meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (vetor[meio] == elemento) {
            return meio; // Elemento encontrado
        } else if (vetor[meio] < elemento) {
            inicio = meio + 1; // Busca na metade direita
        } else {
            fim = meio - 1; // Busca na metade esquerda
        }
    }
    return -1; // Elemento não encontrado
}

/*
 * Remove um elemento de uma lista linear sequencial ORDENADA.
 * Após a remoção, os elementos são deslocados para a esquerda para manter a ordem.
 * Retorna 0 em caso de sucesso, -1 se o elemento não for encontrado ou lista vazia.
 */
int remocaoOrdenada(int *vetor, int elemento) {
    if (quantElem == 0) {
        printf("Erro: A lista está vazia. Nenhuma remoção pode ser feita.\n");
        return -1;
    }

    // Usamos pesquisa binária para encontrar o elemento de forma eficiente
    int indiceEncontrado = pesquisaBinaria(vetor, elemento);

    if (indiceEncontrado != -1) {
        // Desloca os elementos para a esquerda para preencher o espaço
        for (int i = indiceEncontrado; i < quantElem - 1; i++) {
            vetor[i] = vetor[i + 1];
        }
        quantElem--; // Decrementa o contador
        printf("Elemento %d removido com sucesso (lista ordenada).\n", elemento);
        return 0; // Sucesso
    } else {
        printf("Erro: Elemento %d não encontrado na lista.\n", elemento);
        return -1; // Falha (elemento não encontrado)
    }
}

/*
 * Remove o i-ésimo item (base 0) de uma lista ORDENADA.
 * Os elementos subsequentes são deslocados para a esquerda.
 * Retorna 0 em caso de sucesso, -1 se a posição for inválida ou lista vazia.
 */
int removerIesimoItemOrdenado(int *vetor, int posicao) {
    if (quantElem == 0) {
        printf("Erro: A lista está vazia. Não é possível remover o item.\n");
        return -1;
    }
    if (posicao < 0 || posicao >= quantElem) {
        printf("Erro: Posição %d inválida para remoção (lista ordenada). A lista tem %d elementos.\n", posicao, quantElem);
        return -1; // Posição inválida
    }

    int valorRemovido = vetor[posicao]; // Opcional: armazenar o valor para exibição

    // Desloca os elementos para a esquerda para preencher o espaço
    for (int i = posicao; i < quantElem - 1; i++) {
        vetor[i] = vetor[i + 1];
    }
    quantElem--; // Decrementa o contador

    printf("Item %d (valor %d) removido com sucesso da posição %d (lista ordenada).\n", valorRemovido, valorRemovido, posicao);
    return 0; // Sucesso
}

/*
 * Remove um item na i-ésima posição (base 0) de uma lista NÃO ORDENADA.
 * Esta é a forma eficiente para remoção por posição em listas não ordenadas.
 * Retorna 0 em caso de sucesso, -1 se a posição for inválida ou lista vazia.
 */
int removerItemPosicaoNaoOrdenada(int *vetor, int posicao) {
    if (quantElem == 0) {
        printf("Erro: A lista está vazia. Não é possível remover o item.\n");
        return -1;
    }
    if (posicao < 0 || posicao >= quantElem) {
        printf("Erro: Posição %d inválida para remoção (lista não ordenada). A lista tem %d elementos.\n", posicao, quantElem);
        return -1; // Posição inválida
    }

    int valorRemovido = vetor[posicao]; // Opcional: armazenar o valor para exibição

    // Substitui o elemento na posição 'posicao' pelo último elemento da lista
    vetor[posicao] = vetor[quantElem - 1];
    quantElem--; // Decrementa o contador

    printf("Item %d (valor %d) removido com sucesso da posição %d (lista não ordenada).\n", valorRemovido, valorRemovido, posicao);
    return 0; // Sucesso
}


/*
 * Exibe o conteúdo do vetor que representa a lista.
 * Percorre apenas os 'quantElem' elementos válidos.
 * Imprime os elementos formatados e informações de tamanho/capacidade.
 */
void exibeLista(int *vetor){
    printf("\n--- Conteúdo da Lista ---\n");
    if (quantElem == 0) {
        printf("A lista está vazia.\n");
    } else {
        printf("[");
        for(int x = 0; x < quantElem; x++){
            printf("%d", vetor[x]);
            if (x < quantElem - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
    printf("Quantidade de elementos (quantElem): %d\n", quantElem);
    printf("Capacidade máxima (maximo): %d\n", maximo);
    printf("---------------------------\n");
}

// Libera a memória alocada para o vetor (lista).
void liberaVetor(int *vetor) {
    if (vetor) {
        free(vetor);
        printf("Memória do vetor liberada com sucesso.\n");
    }
}

void main(){
    int *lista, aux, resp, op, pos;

    printf("\nDigite quantos elementos deseja ter na lista: ");
    scanf("%d",&maximo);
    lista = criaLista();

    do{
        printf("\n\n--- Menu da Lista Sequencial ---\n");
        printf("1 - Inserção não ordenada\n");
        printf("2 - Pesquisa sequencial\n");
        printf("3 - Remoção de nó não ordenada (por valor)\n");
        printf("4 - Inserção ordenada\n");
        printf("5 - Pesquisa binária\n"); // Nova opção
        printf("6 - Remoção de nó ordenada (por valor)\n"); // Nova opção
        printf("7 - Remover item em posição específica (Lista Ordenada)\n"); // Nova opção
        printf("8 - Remover item em posição específica (Lista Não Ordenada)\n"); // Nova opção
        printf("9 - Exibir lista\n");
        printf("0 - Sair do programa\n");
        printf("--------------------------------\n");
        printf("Digite sua opção: ");
        scanf("%d",&op);

        switch(op){
            case 1: // Inserção não ordenada
                if(insercaoNaoOrd(lista) == -1)
                    printf("\nLista cheia. Inserção não realizada.");
                else
                    printf("\nElemento inserido com sucesso.");
                break;
            case 2: // Pesquisa sequencial
                printf("\nDigite o elemento que deseja procurar:");
                scanf("%d",&aux);
                resp = pesquisaSequencial(lista, aux);
                if(resp == -1)
                    printf("\nElemento não encontrado.");
                else
                    printf("\nElemento encontrado na posição %d do vetor.",resp);
                break;
            case 3: // Remoção não ordenada (por valor)
                printf("\nDigite o elemento que deseja remover:");
                scanf("%d",&aux);
                if(remocaoNo(lista,aux) == 0)
                    printf("\nElemento removido com sucesso.");
                else
                    printf("\nFalha na remoção do elemento ou lista vazia.");
                break;
            case 4: // Inserção Ordenada
                insercaoOrdenada(lista); // A função já lida com a mensagem de sucesso/erro
                break;
            case 5: // Pesquisa Binária (NOVO)
                printf("\nDigite o elemento que deseja procurar (Pesquisa Binária):");
                scanf("%d",&aux);
                resp = pesquisaBinaria(lista, aux);
                if(resp == -1)
                    printf("\nElemento não encontrado via Pesquisa Binária.");
                else
                    printf("\nElemento encontrado na posição %d do vetor via Pesquisa Binária.",resp);
                break;
            case 6: // Remoção de nó ordenada (por valor) (NOVO)
                printf("\nDigite o elemento que deseja remover (da lista ordenada):");
                scanf("%d",&aux);
                if(remocaoOrdenada(lista,aux) == 0)
                    printf("\nRemoção ordenada concluída com sucesso.");
                else
                    printf("\nFalha na remoção ordenada do elemento ou lista vazia.");
                break;
            case 7: // Remover i-ésimo item (Lista Ordenada) (NOVO)
                printf("\nDigite a posição (índice 0) do item a ser removido (Lista Ordenada):");
                scanf("%d",&pos);
                if(removerIesimoItemOrdenado(lista, pos) == 0)
                    printf("\nItem removido da posição %d com sucesso.", pos);
                else
                    printf("\nFalha na remoção por posição (lista ordenada).");
                break;
            case 8: // Remover item na i-ésima posição (Lista Não Ordenada) (NOVO)
                printf("\nDigite a posição (índice 0) do item a ser removido (Lista Não Ordenada):");
                scanf("%d",&pos);
                if(removerItemPosicaoNaoOrdenada(lista, pos) == 0)
                    printf("\nItem removido da posição %d com sucesso.", pos);
                else
                    printf("\nFalha na remoção por posição (lista não ordenada).");
                break;
            case 9: // Exibir lista
                exibeLista(lista);
                break;
            case 0: // Sair
                printf("\nEncerrando programa.\n");
                break;
            default:
                printf("\n\nOpção indisponível. Selecione uma nova opção.");
        }
    } while(op != 0);

    free(lista); // Libera a memória alocada para a lista antes de sair do programa.
}