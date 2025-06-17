#include <stdio.h>
#include <string.h>



void exibirTabuleiro(char tabuleiro[3][3]) {
    printf("\n"); 

    
    for (int i = 0; i < 3; i++) {
        

       
        for (int j = 0; j < 3; j++) {
            
            printf(" %c ", tabuleiro[i][j]);

            
            if (j < 2) {
                printf("|");
            }
        }
       
        printf("\n"); 

        
        if (i < 2) {
            printf("-----------\n"); 
        }
    }
    printf("\n"); 
}

void inicializacaoTabu(char tabuleiro[3][3]){

    for (int i = 0; i < 3; i++)
        for (int  j = 0; j < 3; j++)
        //coloca um espaço em branco entre os caractere a cada repetiçao do loop
        {
           tabuleiro[i][j] = ' ';
        }
        
}

char verificarVitoria(char tabuleiro[3][3]){

    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] != ' ' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]) {
            return tabuleiro[i][0]; // Retorna o símbolo do vencedor ('X' ou 'O')
        }
    }

    // Verificar Colunas
    for (int j = 0; j < 3; j++) {
        if (tabuleiro[0][j] != ' ' && tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[1][j] == tabuleiro[2][j]) {
            return tabuleiro[0][j]; // Retorna o símbolo do vencedor ('X' ou 'O')
        }
    }

    // Verificar Diagonais
    // Diagonal Principal (\)
    if (tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) {
        return tabuleiro[0][0];
    }
    // Diagonal Secundária (/)
    if (tabuleiro[0][2] != ' ' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
        return tabuleiro[0][2];
    }

    // Verificar Empate (se não há espaços vazios e ninguém venceu)
    int celulasPreenchidas = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] != ' ') {
                celulasPreenchidas++;
            }
        }
    }
    if (celulasPreenchidas == 9) { // Se todas as 9 células estão preenchidas
        return 'E'; // Retorna 'E' para empate
    }

    // Se nenhuma das condições acima for atendida, o jogo continua
    return 'C'; // Retorna 'C' para 'Continua'

}

int main() {
    char tabuleiro[3][3];
    
    inicializacaoTabu(tabuleiro);

    int linha, coluna; 
    int rodada = 0; // Contador de jogadas válidas
    char jogadorAtual = 'X'; // Começa com o jogador X (pode ser alterado para o usuário escolher)
    char statusDoJogo; // Para armazenar o retorno de verificarVitoria

    printf("Bem-vindo ao Jogo da Velha!\n");

    
    while (rodada < 9) {
        exibirTabuleiro(tabuleiro); // Exibe o estado atual do tabuleiro

        // solicita a posiçao para o kogador da rodada
        printf("Jogador %c, digite a linha e a coluna (ex: 1 2): ", jogadorAtual);
        
        // Verifica a entrada do usuario
        if (scanf("%d %d", &linha, &coluna) != 2) {
            printf("Entrada inválida! Digite dois números.\n");
            // codigo para evitar entradas erradas/vazias
            while (getchar() != '\n'); 
            continue; // Pula para a próxima apos a verificaçao da entrada
        }


        // Validação da Jogada
        if (linha >= 0 && linha < 3 && 
            coluna >= 0 && coluna < 3 && 
            tabuleiro[linha][coluna] == ' ') { 
            
            // Atualiza o tabuleiro com a jogada do jogador atual
            tabuleiro[linha][coluna] = jogadorAtual;
            rodada++; // monitora as rodadas da partida

            // Verifica o status do jogo após a jogada, confere se ouve ou não algum jogador
            statusDoJogo = verificarVitoria(tabuleiro);

            // caso haja algum ganhador o procedimento verificarVitoria é chamado
            if (statusDoJogo == 'X' || statusDoJogo == 'O') {
                exibirTabuleiro(tabuleiro); // Exibe o tabuleiro final
                printf("Parabéns! O Jogador %c venceu!\n", statusDoJogo);
                break; //caso haja um ganhador o jogo é encerrado
            } else if (statusDoJogo == 'E') {
                exibirTabuleiro(tabuleiro); // Exibe o tabuleiro final
                printf("O jogo terminou em EMPATE!\n");
                break; // Encerra o loop, o jogo acabou
            }
            // Se statusDoJogo for 'C', o jogo continua, então alterna o jogador

            // Alterna os jogadores de acordo com a rodada
            if (jogadorAtual == 'X') {
                jogadorAtual = 'O';
            } else {
                jogadorAtual = 'X';
            }
        } else {
            printf("Jogada inválida! A linha ou coluna está fora dos limites ou a posição já está ocupada. Tente novamente.\n");
            // Se a jogada for inválida, o loop continua e o mesmo jogador tenta novamente
        }
    }

   
    if (rodada == 9 && statusDoJogo == 'C') { // Se o loop terminou por 9 jogadas e o status ainda é 'Continua'
        exibirTabuleiro(tabuleiro); // Garante que o tabuleiro final é exibido
        printf("O jogo terminou em EMPATE!\n"); // Declara empate
    }

    return 0; 
}

   

    



