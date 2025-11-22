#include <stdio.h>

int main(){
    int num;
    int contador = 0;
    int maior;

    while(contador < 10){
        printf("Informe um numero: \n");
        scanf("%d", &num);
        if (contador == 0){
            maior = num;
        }
        else {
            if (num > maior){
                maior = num;
            }
        }
        contador++;
    }
    printf("O maior foi: %d\n", maior);

}