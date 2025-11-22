#include <stdio.h>

int main(){
    int produto = 1;
    int contador;

    for (contador = 1; contador <= 15; contador = contador + 2){
        produto = produto * contador;
    }
    printf("O produto dos numeros impares de 1 a 15 eh: %d\n", produto);
    return 0;
}