#include <stdio.h>

// Sua função de inicializarTabuleiro
void inicializarTabuleiro(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

// (Sua função exibirTabuleiro viria aqui)
// void exibirTabuleiro(char tabuleiro[3][3]) { ... }

int main() {
    char meuTabuleiro[3][3]; // Declara o tabuleiro

    inicializarTabuleiro(meuTabuleiro); // Chama a função para inicializá-lo

    // Agora você pode exibir o tabuleiro ou começar o jogo
    // exibirTabuleiro(meuTabuleiro);

    return 0;
}