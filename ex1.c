#include <stdio.h>

int main(){
    int diaSemana;

    printf("Digite um numero de 1 a 7 para o dia da semana:");
    scanf("%d", &diaSemana);


    switch(diaSemana){
        case 1:
        printf("hoje eh domingo.\n");
        break;

        case 2:
        printf("hoje eh Segunda Feira.\n");
        break;

        case 3:
        printf("hoje eh Terça feira.\n");
        break;

        case 4:
        printf("hoje eh Quarta feira.\n");
        break;

        case 5:
        printf("hoje eh Quinta feira.\n");
        break;

        case 6:
        printf("hoje eh Sexta feira.\n");
        break;

        case 7:
        printf("hoje eh Sabado.\n");
        break;

    } 

    return 0;
}