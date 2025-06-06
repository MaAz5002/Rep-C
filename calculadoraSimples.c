#include <stdio.h>

int main(){
    int num1,num2;
    
    printf("Insira um valor:\n");
    scanf("%d", &num1);
    printf("Insira um segundo valor:\n");
    scanf("%d", &num2);


    int resultSoma = num1+ num2;
    int resultMult = num1* num2;
    int resultSub = num1 - num2;
    int resultadoDiv = (float)num1 / num2; //converção do tipo

    printf("A soma dos valores é: %d\n",resultSoma );
    printf("A multiplicação dos valores é: %d\n",resultMult );
    printf("A subtração dos valores é: %d\n",resultSub );
    printf("A divisão dos valores é: %f\n",resultadoDiv );

    return 0;




}