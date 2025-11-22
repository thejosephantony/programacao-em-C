#include <stdio.h>

int main(){
    int num1, num2;
    printf("Digite dois numeros: \n");
    scanf("%d %d", &num1, &num2);
    int soma = num1 + num2;
    int subtracao = num1 - num2;
    int multiplicacao = num1 * num2;
    int divisao = num1 / num2;
    int restoDiv = num1 % num2;

    printf("A soma: %d \n", soma);
    printf("A subtracao: %d \n", subtracao);
    printf("A multiplicacao: %d \n", multiplicacao);
    printf("A divisao: %d \n", divisao);
    printf("O resto da divisao: %d \n", restoDiv);

    return 0;
}