#include <stdio.h>

int main(void){
    int num1;
    int num2;

    printf("numero 1: \n");
    scanf("%d", &num1);
    printf("numero 2: \n");
    scanf("%d", &num2);

    if (num1 % num2 == 0 || num2 % num1 == 0){
        printf("sao multiplos");
    }

    if (num1 % num2 != 0 && num2 % num1 != 0){
        printf("nao sao multiplos");
    }

    return 0;
}