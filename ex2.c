#include <stdio.h>

int main(){
    int nInteiro;

    printf("Insira um numero");
    scanf("%d",&nInteiro);

    if (nInteiro < 0)
    {
       printf("O elemento é um valor negativo");
    }else if (nInteiro > 0)
    {
        printf("O elemento é um valor positivo");
    }else if (nInteiro == 0)
    {
        printf("O valor equivale a 0");
    }
    
    return 0;
    
    
}