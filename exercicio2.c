#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanho 100

typedef struct {
    char nome[tamanho];
    int idade;
    float peso;
} Atleta;

int main() {
    int N, i, menoresIdade = 0;
    float somaPesos = 0;


    printf("Qts. atletas deseja cadastrar? ");
    scanf("%d", &N);

    Atleta *vetor = (Atleta *)malloc(N * sizeof(Atleta));        //aloca a memoria
    if (vetor == NULL) {
        printf("erro ao alocar memoria.\n");
        return 1;
    }


    for (i = 0; i < N; i++) {
        printf("\nAtleta %d:\n", i + 1);
        printf("Nome: ");
        getchar(); 
        fgets(vetor[i].nome, tamanho, stdin);
        vetor[i].nome[strcspn(vetor[i].nome, "\n")] = '\0';

        printf("Idade: ");
        scanf("%d", &vetor[i].idade);

        printf("Peso: ");
        scanf("%f", &vetor[i].peso);

        somaPesos += vetor[i].peso;

        if (vetor[i].idade < 18) {                       // defini menor de idade com menos de 18 anos
            menoresIdade++;
        }
    }


    printf("\n--- Lista de Atletas ---\n");
    for (i = 0; i < N; i++) {
        printf("Nome: %s | Idade: %d | Peso: %.2f kg\n",
               vetor[i].nome, vetor[i].idade, vetor[i].peso);
    }


    printf("Media dos pesos: %.2f kg\n", somaPesos / N);
    printf("Qtds. de atletas menores de idade: %d\n", menoresIdade);


    free(vetor);        // libera a memoria

    return 0;
}
