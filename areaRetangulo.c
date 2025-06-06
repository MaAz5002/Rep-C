#include <stdio.h>

int main(){
    float base,altura;

    printf("Qual o valor da base do triângulo?\n");
    scanf("%f", &base);

    printf("Qual o valor da altura do triângulo?\n");
    scanf("%f", &altura);

    float area = base * altura;

    printf("A área do tringulo é %.2f", area);

}