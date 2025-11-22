#include <stdio.h>

int main(){
    float pi = 3.14159;
    int raio;

    printf("Informe o raio: ");
    scanf("%d", &raio);

    printf("O diametro: %d\n", 2*raio);
    printf("O perimetro: %.2f\n", 2*pi*raio);
    printf("A area: %.2f\n", pi*raio*raio);

    return 0;

}