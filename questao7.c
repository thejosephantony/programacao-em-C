#include <stdio.h> 

int main(){
    int a, b, c, d, e;
    printf("Digite cinco inteiros: \n");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    if(a >= b && a >= c && a >= d && a >= e){
        printf("O maior eh: %d \n", a);
    }
    else if (b >= a && b >= c && b >= d && b >= e){
        printf("O maior eh: %d \n", b);
    }
    else if (c >= a && c >= b && c >= d && c >= e){
        printf("O maior eh: %d \n", c);
    }
    else if (d >= a && d >= b && d >= c && d >= e){
        printf("O maior eh: %d \n", d);
    }
    else{
        printf("O maior eh: %d \n", e);
    }


    if (a <= b && a <= c && a <= d && a <= e){
        printf("O menor eh: %d \n", a);
    }
    else if (b <= a && b <= c && b <= d && b <= e){
        printf("O menor eh: %d \n", b);
    }
    else if (c <= a && c <= b && c <= d && c <= e){
        printf("O menor eh: %d \n", c);
    }
    else if (d <= a && d <= b && d <= c && d <= e){
        printf("O menor eh: %d \n", d);
    }
    else{
        printf("O menor eh: %d \n", e);
    }

    return 0;

}