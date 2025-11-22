#include <stdio.h>

int main(){
  float peso;
  float altura;
  float imc;
  printf("Informe seu peso (kg): \n");
  scanf("%f", &peso);
  printf("Informe sua altura (m): \n");
  scanf("%f", &altura);
  imc =  (peso)/(altura*altura);
  printf("O seu imc é: %.2f\n", imc);

  printf("VALORES DE IMC\n");
  printf("Abaixo do peso: menor que 18.5\n");
  printf("Normal:         entre 18.5 e 24.9\n");
  printf("Acima do peso:  entre 25 e 29.9\n");
  printf("Obeso:          30 ou mais\n");

  return 0;
}