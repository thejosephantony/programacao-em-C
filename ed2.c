#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define contatos_max 100

typedef struct AgendaEndereco {
    char nome[50];
    char endereco[100];
    char telefone[15];
} AgendaEndereco;

AgendaEndereco agenda[contatos_max];
int contatos_count = 0;

void limpaBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrarContatos(){
    if (contatos_count >= contatos_max){
        printf("Agenda cheia.");
        return;
    }
    printf("\n------ Cadastrar Contato ------\n");
    printf("Digite o nome: \n");
    scanf("%49[^\n]", agenda[contatos_count].nome);
    limpaBuffer();
    printf("Digite o endereco: \n");
    scanf("%99[^\n]", agenda[contatos_count].endereco);
    limpaBuffer();
    printf("Digite o telefone: \n");
    scanf("%14[^\n]", agenda[contatos_count].telefone);
    limpaBuffer();

    contatos_count++;
    printf("\nContato cadastrado com sucesso!\n");

}

void listarAgenda() {
    printf("\n--- Dados Cadastrados ---\n");
    for(int i = 0; i < contatos_count; i++){
    printf("Nome: %s\n", agenda[i].nome);
    printf("Endereco: %s\n", agenda[i].endereco);
    printf("Telefone: %s\n", agenda[i].telefone);
}}

int main() {
    int option;

    do {
        printf("\n=== MENU ===\n");
        printf("1- Cadastrar contato\n");
        printf("2- Listar contatos\n");
        printf("0- Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &option);
        limpaBuffer();

        switch(option) {
            case 1:
                cadastrarContatos();
                break;
            case 2:
                listarAgenda();
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (option != 0);

    return 0;
}