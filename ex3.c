#include <stdio.h>

int main(){
    int idade;

    printf("Qual a sua idade?");
    scanf("%d", &idade);
    if (idade >= 18)
    {
        printf("Você é maior de idade");
    }else if (idade <= 18)
    {
        printf("Você aimda é um bebê");
    }
    return 0;
    
}