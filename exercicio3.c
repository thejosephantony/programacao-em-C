#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanho 100


typedef struct {
    char nome[tamanho];
    int matricula;
    float media;
} Aluno;


int compararPorNome(const void *a, const void *b) {
    Aluno *alunoA = (Aluno *)a;
    Aluno *alunoB = (Aluno *)b;
    return strcmp(alunoA->nome, alunoB->nome);
}

int compararPorMedia(const void *a, const void *b) {
    Aluno *alunoA = (Aluno *)a;
    Aluno *alunoB = (Aluno *)b;
    if (alunoB->media > alunoA->media) return 1;
    if (alunoB->media < alunoA->media) return -1;
    return 0;
}


void exibirLista(Aluno *vetor, int N) {
    for (int i = 0; i < N; i++) {
        printf("Nome: %s | Matricula: %d | Media: %.2f\n",
               vetor[i].nome, vetor[i].matricula, vetor[i].media);
    }
}

int main() {
    int N, i, opcao;
    Aluno *alunos;
    Aluno *copia; 

    printf("Qts alunos deseja cadastrar? ");
    scanf("%d", &N);

    alunos = (Aluno *)malloc(N * sizeof(Aluno));     // aloca a memoria
    copia = (Aluno *)malloc(N * sizeof(Aluno));
    if (alunos == NULL || copia == NULL) {
        printf("erro ao alocar memoria.\n");
        return 1;
    }


    for (i = 0; i < N; i++) {
        printf("\nAluno %d:\n", i + 1);
        getchar(); 
        printf("Nome: ");
        fgets(alunos[i].nome, tamanho, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0'; 

        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);

        printf("Media: ");
        scanf("%f", &alunos[i].media);
    }


    do {
        printf("\nComo quer ver os alunos?\n");
        printf("1 - Ordem alfabetica\n");
        printf("2 - Ordem de classificacao (maior media)\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1 || opcao == 2) {

            memcpy(copia, alunos, N * sizeof(Aluno));


            if (opcao == 1)
                qsort(copia, N, sizeof(Aluno), compararPorNome);
            else
                qsort(copia, N, sizeof(Aluno), compararPorMedia);

            printf("\n--- Lista de Alunos ---\n");
            exibirLista(copia, N);
        } else if (opcao != 0) {
            printf("erro, opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);


    free(alunos); // libera a memoria
    free(copia);

    return 0;
}
