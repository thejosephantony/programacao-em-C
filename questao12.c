#include <stdio.h>

int main(){
    float km, litros;
    float consumo;
    float total_litros = 0, total_km = 0;
    consumo = 0;

    printf("Informe quantos litros abasteceu (-1 para terminar): \n");
    scanf("%f", &litros);

    while (litros != -1){
        printf("Informe quantos km rodou: \n");
        scanf("%f", &km);

        consumo = km / litros;
        printf("O consumo atual foi de %.2f km/L \n", consumo);
        total_km = km + total_km;
        total_litros = litros + total_litros;

        printf("Informe quantos litros abasteceu (-1 para terminar): \n");
        scanf("%f", &litros);

    }

    printf("O consumo total foi de %.2f km/L \n", total_km / total_litros);

    return 0;

}