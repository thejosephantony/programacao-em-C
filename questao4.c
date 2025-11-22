#include <stdio.h>

int main(){
    int a, b;
    printf("Digite dois numeros: ");
    scanf("%d %d", &a, &b);

    if (a > b){
        printf("%d eh maior", a);
    }
    if (b > a){
        printf("%d eh maior", b);
    }

    if (a == b){
        printf("Esses numeros sao iguais");
    }
    return 0;
}