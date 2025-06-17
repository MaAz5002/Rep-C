#include <stdio.h>
#include <string.h>
#define MAX_PRODUTOS 50 // armezena o numero total de produtos possiveis dentro do vetor

//Declaração da estrutura
struct Produto{
        int codigo;
        char nome[50];
        float preco;
        int quantidade_estoque;
    };

// procedimento exclusivo para cadastro dos produtos
int cadastrar_produto(struct Produto lista_produto[], int *num_produto){
    int quantidade_produto;// armazena o numero de produtos que serão alocados
    int produto_cadastrados = 0; //  numero de produtos cadastrados dentro da lista

    printf("----- Cadastrar novos produtos ------\n");
    printf("Quantos produtos deseja cadastrar?\n");
    scanf(" %d ", &quantidade_produto);// solicita a numero de produtos

    if(produto_cadastrados <= 0){
        printf("Insira um valor valido!\n");
    }

    //validaçao para impedimento de cadastro de produtos além do definido
    if ((*num_produto + quantidade_produto) > MAX_PRODUTOS) {
        printf("Impossivel cadastrar %d produtos. O limite de %d sera excedido.\n",
               quantidade_produto, MAX_PRODUTOS);
        printf("Apenas %d produtos podem ser cadastrados.\n", MAX_PRODUTOS - *num_produto);
        quantidade_produto = MAX_PRODUTOS - *num_produto; // Ajusta para o máximo possível
        if (quantidade_produto <= 0) { // Se não houver mais espaço
            printf("Nao ha mais espaco para cadastrar produtos.\n");
            return 0;
        }
    }





//laço de repetição para adicionar os produtos a lista
    for(int i = 0; i < quantidade_produto; i++){
        int num_indice = *num_produto + produto_cadastrados;

        printf("------ Dados do Produto ------");
        printf(" Código: ");
        scanf(" %d", &lista_produto[num_indice].codigo);// adiciona o codigo

        printf(" Nome (sem espacos): "); 
        scanf(" %s", lista_produto[num_indice].nome);// adiciona o nome

        printf(" Preço: ");
        scanf(" %f", &lista_produto[num_indice].preco);// adiciona o preço

        printf(" Quantidade em estoque: ");
        scanf(" %d", &lista_produto[num_indice].quantidade_estoque);// adiciona o estoque do produto

        produto_cadastrados++; // incrmenta ao numero de produtos cadastrados



    }

    *num_produto += produto_cadastrados;// o numero de produtos é atualizado 
    return produto_cadastrados;

};

//Procedimento para mostrar os dados dos produtos cadastrados
void dadosProdutos( struct Produto lista_produto[], int num_produto){
    // verificação do vetor
    if (num_produto == 0) {
        printf("Nenhum produto cadastrado atualmente.\n");
        return; 
    }

    printf("------ Produtos Cadastrados ------\n");
    for(int i = 0; i < num_produto; i++){
        printf("Produto\n");
        printf(" Código:  %d\n", lista_produto[i].codigo);
        printf("  Nome: %s\n", lista_produto[i].nome);
        printf(" Preço:  %.2f\n", lista_produto[i].preco);
        printf(" Quantidade em Estoque: %d\n", lista_produto[i].quantidade_estoque);
    }


}


// Função principal
int main(){
    int entrada_usuario; //armazena qual a funçao pelo usuario
    struct Produto estoque[MAX_PRODUTOS];
    int qtd_produto = 0;
    do
    {
        printf("Insira a operação desejada para continuar:\n\
        1 - Cadastrar novo produto\n\
        2 - Exibir dados do produto\n\
        3 - Sair");
    
        scanf(" %d", &entrada_usuario);
   
    switch (entrada_usuario){
    
    case 1:
        cadastrar_produto(estoque, &qtd_produto);
        break;
    
    case 2:
       if (qtd_produto == 0) { // Verifica se algum produto foi cadastrado
                    printf("Nenhum produto cadastrado ainda!\n");
                } else {
                    dadosProdutos(estoque, qtd_produto);
                }
                break;

    
    case 3:
        printf("Programa encerrado");

    default:
        printf("Opçao inválida!Tente novamente");
        break;
    
    }
  
} while(entrada_usuario != 3);
 
    return 0;
}




