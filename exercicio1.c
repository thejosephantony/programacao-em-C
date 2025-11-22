#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor;
    int num, i;
    float soma = 0;

    printf("Qts. numeros desejas? ");
    scanf("%d", &num);

    vetor = (int *)malloc(num * sizeof(int));   // aloca a memoria
    if (vetor == NULL) {
        printf("Erro em alocar memoria.\n");
        return 1;
    }

    for (i = 0; i < num; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }

    printf("Media dos numeros: %.2f\n", soma / num);

    printf("Multiplos de 6 sao:\n");
    for (i = 0; i < num; i++) {
        if (vetor[i] % 6 == 0) {
            printf("%d ", vetor[i]);
        }
    }
    printf("\n");

    free(vetor); // libera a memoria 

    return 0;
}
