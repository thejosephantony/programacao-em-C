#include <stdio.h>

int main(){
    int contador = 0;
    int num;

    printf("Digite um número: ");
    scanf("%d", &num);

    while(num % 2 == 0){
        printf("%d\n", 2 * contador);
        contador++;
    }
    return 0;
}