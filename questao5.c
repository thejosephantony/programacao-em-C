#include <stdio.h>

int main(){
    int num1, num2, num3;
    int soma;
    float media;
    int produto;
    printf("Digite tres numeros diferentes: \n");
    scanf("%d %d %d", &num1, &num2, &num3);
    if ((num1 != num2) && (num1 != num3) && (num2 != num3)){
        soma = num1 + num2 + num3;
        media = soma/3;
        produto = num1 * num2 * num3;

        printf("A soma eh: %d \n", soma);
        printf("A media eh: %.2f \n", media);
        printf("O produto eh: %d \n", produto);

        if(num1 < num2 && num1 < num3){
            printf("O menor eh: %d \n", num1);
        }
        else if (num2 < num1 && num2 < num3){
            printf("O menor eh: %d \n", num2);
        }
        else{
            printf("O menor eh: %d \n", num3);
        }

        if(num1 > num2 && num1 > num3){
            printf("O maior eh: %d \n", num1);
        }
        else if (num2 > num1 && num2 > num3){
            printf("O maior eh: %d \n", num2);
        }
        else{
            printf("O maior eh: %d \n", num3);
        }

    }
    else{
        printf("Os numeros nao sao todos diferentes \n");
    }
    return 0;
}