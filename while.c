// #include <stdio.h>

// int main( void )
// {
// int x = 1, total = 0, y;

// while ( x <= 10 ) {
  
// y = x * x;
//  printf( "%d\n", y );
//  total += y;
//  ++x;
// } /* fim do while */

// printf("Total is %d\n", total);
//  return 0;
// }


// #include <stdio.h>

// int main(){

//     int contador = 0;
//     while(contador <= 10){
//         printf("%d\n", contador);
//         contador++;
//     }
//     return 0;
// }

// #include <stdio.h>
// int main(){
//     int contador;

//     for(contador = 0; contador <= 10; contador++){
//         printf("%d\n", contador);
//     }
//     return 0;
// }


// #include <stdio.h>

// int main(){
//   int cont;

//   for(cont = 1; cont <= 7; cont++){
//     printf("%d", cont);
//   }
//   return 0;
// }

// #include <stdio.h>
//   int main(){
//     int cont;

//     for(cont = 20; cont >= - 10; cont-=6){
//       printf("%d\n", cont);

//     }
//     return 0;
//   }


#include <stdio.h>

int main(){
  int contador;
  int valor;
  int soma = 0;
  int num;
  printf("Informe um valor:\n");
  scanf("%d", &valor);
  for(contador = 1; contador <= valor; contador++){
    printf("Digite o numero: \n");
    scanf("%d", &num);
    soma+=num;
  }
  printf("A soma eh %d \n", soma);
  return 0;
  
}