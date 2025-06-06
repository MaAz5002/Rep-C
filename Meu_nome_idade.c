#include<stdio.h>

int main(){
    char nome[50];
    int idade;

    printf("Qual o seu nome?.\n");
    scanf("%s", nome);

    printf("Qual a sua idade?.\n");
    scanf("%d", &idade);// essa função é P.O.D.R.E melhor usar "fgets"

    printf("Olá %s é um prazer te conhecer!.\n", nome);
    return 0;
}