#include <stdio.h>

int main() {

    double a,b,c;

    printf("Introduza o 1 valor: \n");
    scanf("%lf", &a);

    printf("Introduza o 2valor: \n");
    scanf("%lf \n" , &b);

    printf("Introduza o 2 valor: \n");
    scanf("%lf \n", &c);

    if(a > b && a > c) {
        printf("O maior: ", a);
    }

    else if (b > a && c) {
        printf("O maior: ", b);
    }

        printf("O maior: ", c);
}