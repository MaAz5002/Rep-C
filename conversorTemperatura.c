#include <stdio.h>

int main(){
    int grauCel;

    printf("Digite a temperatura em gCelsius:");
    scanf("%d", &grauCel);

    float grauFah = (grauCel*1.8) + 32;
    printf("%dC° em Fahrenheit é %.2f.\n", grauCel, grauFah);



}