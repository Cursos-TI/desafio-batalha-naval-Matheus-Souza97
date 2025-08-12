#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
 
    printf("==========TABULEIRO BATALHA NAVAL==========\n\n");
    char letras [11] = {' ','A','B','C','D','E','F','G','H','I','J'};
    int numeros [10][11] = {
        {1,0,0,0,0,0,0,0,0,0,0},
        {2,0,0,0,0,0,0,0,0,0,0},
        {3,0,0,0,0,0,0,0,0,0,0},
        {4,0,0,0,0,0,0,0,0,0,0},
        {5,0,0,0,0,0,0,0,0,0,0},
        {6,0,0,0,0,0,0,0,0,0,0},
        {7,0,0,0,0,0,0,0,0,0,0},
        {8,0,0,0,0,0,0,0,0,0,0},
        {9,0,0,0,0,0,0,0,0,0,0},
        {10,0,0,0,0,0,0,0,0,0,0},

    };

    

    int tamanho_embarcacao = 3; // - Variavel para identificar quantas casas ocupa a embarcação
    int embarcacao = 3; // - Posição ocupada pela embarcação

        //HORIZONTAL
    int linhaH = 3; // - Posição inicial da embarcação referente a linha
    int colunaH = 3;// - Posição inicial da embarcação referente a coluna

        //VERTICAL
    int linhaV = 5; // - Posição inicial da embarcação referente a linha
    int colunaV = 7;// - Posição inicial da embarcação referente a coluna

        //CHECK POSIÇÃO HORIZONTAL
    int orientacaoH =
        (linhaH >= 0 && linhaH < 10) &&
        (colunaH >= 1 && colunaH <= 10) &&
        (colunaH + tamanho_embarcacao - 1 <= 10);

    if(!orientacaoH){
        printf("Erro! Embarcação Horizontal fora do tabuleiro.\n");
        return 0;
    }
        //CHECK POSIÇÃO VERTICAL
    int orientacaoV =
        (linhaV >= 0 && linhaV < 10) &&
        (colunaV >= 1 && colunaV <= 10) &&
        (linhaV + tamanho_embarcacao - 1 <= 9);

    if(!orientacaoV){
        printf("Erro! Embarcação Vertical fora do tabuleiro.\n");
        return 0;
    }
        //CHECK COLISÃO H
    for (int i = 0; i < tamanho_embarcacao; i++)
    {
        if(numeros[linhaH][colunaH + i] != 0){
            printf("Erro! Embarcação Horizontal sobreposta\n");
            return 0;
        }
    }
    

        // - Posiciona H
    for (int i = 0; i < tamanho_embarcacao; i++)
    {
        numeros[linhaH][colunaH + i] = embarcacao;
    }

        //CHECK COLISÃO V   
    for (int i = 0; i < tamanho_embarcacao; i++)
    {
        if(numeros[linhaV + i][colunaV] != 0){
            printf("Erro! Embarcação Vertical sobreposta.\n");
            return 0;
        }
    }
        // - Posiciona V
    for (int i = 0; i < tamanho_embarcacao; i++)
    {
        numeros[linhaV + i][colunaV] = embarcacao;
    }
    

    printf("Posicionamento das embarcações:\n");

    for (int i = 0; i < 11; i++)
    {
           printf("%c ", letras[i]);
    }   printf("\n");
        

    for (int l = 0; l < 10; l++)
    {  for (int m = 0; m < 11; m++)
    {
        printf("%d ", numeros[l][m]);
    }   printf("\n");
    }
      

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
