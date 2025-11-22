// NOME: JOSEPH ANTONY DOS SANTOS LEITE


#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int bit;
    struct No* prox;
} No;

void decimalBinario(int decimal) {
    No* cabeca = NULL;
    No* novoNo = NULL;
    
    if (decimal == 0) {
        printf("0\n");
        return;
    }
    
    // conversor
    while (decimal > 0) {
        novoNo = (No*)malloc(sizeof(No));
        novoNo->bit = decimal % 2;
        novoNo->prox = cabeca;
        cabeca = novoNo;
        decimal = decimal / 2;
    }
    
    printf("O binario eh: ");         // imprime o numero em binario
    while (cabeca != NULL) {
        printf("%d", cabeca->bit);
        No* temp =  cabeca;
        cabeca = cabeca->prox;
        free(temp); 
    }
    printf("\n");
}

int main() {
    int numero;
    
    printf("Informe o numero decimal: \n");
    scanf("%d", &numero);
    
    decimalBinario(numero);
    
    return 0;
}