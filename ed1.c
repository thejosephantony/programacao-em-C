// uma função que recebe como parâmetro o dia, o mês, o ano e uma estrutura do tipo Data, onde o resultado deve ser armazenado, e retorna 
// verdadeiro se a data estiver válida; caso contrário, retorna falso. A vali
// dação da data pode ser feita da seguinte forma:


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
    int dia;
    int mes;
    int ano;
} Data;

int verificaData(int dia, int mes, int ano, Data *data){
    if (ano < 1 || ano > 9999){
        return 0;
    }
    if (mes < 1 || mes > 12){
        return 0;
    }

    int diasNoMes;
    switch (mes){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            diasNoMes = 31;
            break;
        case 4: case 6: case 9: case 11:
            diasNoMes = 30;
            break;
        case 2:
        if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)){
            diasNoMes = 29;  // ano bissexto
            break;
        }
        else {
            diasNoMes = 28;
            break;
        }
    }

    if (dia < 1 || dia > diasNoMes){
        return 0;
    }
    data -> dia = dia;
    data -> mes = mes;
    data -> ano = ano;

    return 1;
}

int main(){
    Data data;
    int dia, mes, ano;

    printf("Dia: \n");
    scanf("%d", &dia);

    printf("Mes: \n");
    scanf("%d", &mes);

    printf("Ano: \n");
    scanf("%d", &ano);

    if (verificaData(dia, mes, ano, &data)){
        printf("Data verdadeira: %02d/%02d/%04d\n", data.dia, data.mes, data.ano);
    }
    else{
        printf("Data invalida. \n");
    }

    return 0;
}