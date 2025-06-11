#include <stdio.h>

int main(){
    int nota;

    printf("Qual a sua nota?");
    scanf("%d", &nota);
    if (nota >= 9)
    {
        printf("Exelente!");
    }else if (nota >= 7 && nota < 9 )
    {
        printf("Aprovado!");
    }else if (nota >= 5 && nota < 7 )
    {
        printf("Em Recuperação.");
    }
    
    return 0;
    
}