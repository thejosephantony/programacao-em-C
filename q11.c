#include <stdio.h>

int main (){
    int num;
    int menor;
    int contador;
    int quant;

    printf("Informe a quantidade de num: \n");
    scanf("%d", &quant);

    for(contador = 1; contador <= quant; contador++){
        printf("Informe um numero: ");
        scanf("%d", &num);

        if (num < menor){
            menor = num;
        }
    }

    printf("O menor numero informado eh: %d\n", menor);
    return 0;
}