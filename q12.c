#include <stdio.h>

int main(){
    int soma = 0;
    int contador;

    for(contador = 2; contador <= 30; contador = contador + 2){
        soma = soma + contador;
    }
    printf("A soma dos num pares de 2 a 30 eh: %d\n", soma);
    return 0;

}