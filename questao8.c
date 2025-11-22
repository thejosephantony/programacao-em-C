#include <stdio.h>

int main(){
    int num;
    printf("Digite um numero inteiro: \n");
    scanf("%d", &num);

    if(num % 2 == 0){
        printf("%d eh par \n", num);
    }

    if(num % 2 != 0){
        printf("%d eh impar \n", num);
    }
    return 0;

}