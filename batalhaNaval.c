#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Siga os comentários para implementar cada parte do desafio.

#define LETRAS 11
#define LINHAS 10
#define COLUNAS 11
#define TAMANHO 3
#define EMBARCACAO 3
#define ATAQUE 1

int main() {
    // Nível Novato - Posicionamento dos Navios
 
    printf("==========TABULEIRO BATALHA NAVAL==========\n\n");
    char letras [11] = {' ','A','B','C','D','E','F','G','H','I','J'};
    int numeros [10][11];

//====================================================== 

//Print das letras dos Tabuleiro

    printf("*** Tabuleiro Vazio ***\n\n");
    for (int i = 0; i < LETRAS; i++)
    {
        printf("%c ", letras[i]);
    }
    printf("\n");
//======================================================    

// Declara e imprime a matriz 10 x 10
    for (int i = 0; i < LINHAS; i++)
    {   numeros[i][0] = i+1;
        for (int j = 1; j < COLUNAS; j++)
        {
            numeros[i][j] = 0;
        }
    }
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            printf("%d ", numeros[i][j]);
        }
        printf("\n");
    }
    printf("\n");


//========================================================

//Coordenadas para posicionamento
        //HORIZONTAL
    int linhaH = 3; // - Posição inicial da embarcação referente a linha
    int colunaH = 3;// - Posição inicial da embarcação referente a coluna

        //VERTICAL
    int linhaV = 5; // - Posição inicial da embarcação referente a linha
    int colunaV = 7;// - Posição inicial da embarcação referente a coluna

//========================================================

//Check de colisao e sobreposição

//CHECK POSIÇÃO HORIZONTAL
    int orientacaoH =
        (linhaH >= 0 && linhaH <= 10) &&
        (colunaH >= 1 && colunaH <= 10) &&
        (colunaH + TAMANHO - 1 <= 10);

    if(!orientacaoH){
        printf("Erro! Embarcação Horizontal fora do tabuleiro.\n");
        return 0;
    }
        //CHECK POSIÇÃO VERTICAL
    int orientacaoV =
        (linhaV >= 0 && linhaV <= 10) &&
        (colunaV >= 1 && colunaV <= 10) &&
        (linhaV + TAMANHO - 1 <= 9);

    if(!orientacaoV){
        printf("Erro! Embarcação Vertical fora do tabuleiro.\n");
        return 0;
    }
        //CHECK COLISÃO H
    for (int i = 0; i < TAMANHO; i++)
    {
        if(numeros[linhaH][colunaH + i] != 0){
            printf("Erro! Embarcação Horizontal sobreposta\n");
            return 0;
        }
    }
    

        // - Posiciona H
    for (int i = 0; i < TAMANHO; i++)
    {
        numeros[linhaH][colunaH + i] = EMBARCACAO;
    }

        //CHECK COLISÃO V   
    for (int i = 0; i < TAMANHO; i++)
    {
        if(numeros[linhaV + i][colunaV] != 0){
            printf("Erro! Embarcação Vertical sobreposta.\n");
            return 0;
        }
    }
        // - Posiciona V
    for (int i = 0; i < TAMANHO; i++)
    {
        numeros[linhaV + i][colunaV] = EMBARCACAO;
    }
//========================================================

// Apresentação do tabuleiro preenchido

    printf("Posicionamento das embarcações Horizontal e Vertical:\n\n");

    for (int i = 0; i < LETRAS; i++)
    {
        printf("%c ", letras[i]);
    }   printf("\n");
        

    for (int i = 0; i < LINHAS; i++)
    {  for (int j = 0; j < COLUNAS; j++)
    {
        printf("%d ", numeros[i][j]);
    }   printf("\n");
    }
    printf("\n");

//========================================================
      
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    //Embarcação na Diagonal Principal e Secundaria

//Variaveis de posicionamento
    int lin_diag1 = 0;
    int col_diag1 = 1;

//========================================================

// CHECK DE POSIÇÃO E COLISÃO

    int orientacao_diag1 = 
    (lin_diag1 >= 0 && lin_diag1 <= 10) &&
    (col_diag1 >= 1 && col_diag1 <= 10) &&
    (lin_diag1 + 1 <=10 && col_diag1 +1 <= 10);

    if(!orientacao_diag1){
        printf("Erro! Embarcação Diagonal Principal fora do tabuleiro.\n");
        return 0;
    }
    for (int i = 0; i < TAMANHO; i++)
    {
        if(numeros[lin_diag1 + i][col_diag1 + i] != 0){
            printf("Erro! Embarcação Diagonal Principal Sobrepostas.\n");
            return 0;
        }
    }
//========================================================

//Posiciona embarcação na diagonal principal

    for (int i = 0; i < TAMANHO; i++)
    {   
         numeros[lin_diag1 + i][col_diag1 + i] = EMBARCACAO;   
    }   

//========================================================

//Posicionamento da embarcação na Diagonal Secundaria

//Variaveis de posicionamento
    int lin_diag2 = 6;
    int col_diag2 = 10;

//========================================================

// CHECK DE POSIÇÃO E COLISÃO
    int orientacao_diag2 = 
    (lin_diag2 >= 0 && lin_diag2 <= 10) &&
    (col_diag2 >= 1 && col_diag2 <= 10) &&
    (lin_diag2 + 1 <= 10 && col_diag2 >= 0);

    if(!orientacao_diag2){
        printf("Erro! Embarcação Diagonal Secundaria fora do tabuleiro.\n.");
        return 0;
    }
    for (int i = 0; i < TAMANHO; i++)
    {
        if(numeros[lin_diag2 + i][col_diag2 - i] != 0){
            printf("Erro! Embarcação Diagonal Secundaria Sobrepostas.\n");
            return 0;
        }
    }
//========================================================

//Posiciona embarcação na diagonal secundaria
    
    for (int i = 0; i < TAMANHO; i++)
    {
        numeros[lin_diag2 + i][col_diag2 - i] = EMBARCACAO;  
    }
//========================================================       
// Apresentação do tabuleiro preenchido

    printf("Posicionamento das embarcações Diagonal:\n\n");

    for (int i = 0; i < LETRAS; i++)
    {
        printf("%c ", letras[i]);
    }   printf("\n");
        

    for (int i = 0; i < LINHAS; i++)
    {  for (int j = 0; j < COLUNAS; j++)
    {
        printf("%d ", numeros[i][j]);
    }   printf("\n");
    }
    printf("\n");

    // Nível Mestre - Habilidades Especiais com Matrizes
   //========================================================       
// Tabuleiro de Habilidades

int matrizHabilidade[LINHAS][COLUNAS];

for (int i = 0; i < LINHAS; i++)
{   matrizHabilidade[i][0] = i + 1;
    for (int j = 1; j < COLUNAS; j++)
    {
        matrizHabilidade[i][j] = 0;
    }
}
//========================================================       
// Habilidade Cone

int cone_x = 4, cone_y = 0; //Coordenada do inicio da Habilidade

for (int i = 0; i < 1; i++){
    matrizHabilidade[cone_y][cone_x] = ATAQUE;
    for (int j = 0; j < 3; j++)
    {
        matrizHabilidade[cone_y+1][(cone_x-1)+j] = ATAQUE;
        for (int k = 0; k < 5; k++)
        {
            matrizHabilidade[cone_y+2][(cone_x-2)+k] = ATAQUE;
        } 
    }
}

//========================================================       
// Habilidade Cruz

int cruz_y = 7, cruz_x = 7; //Coordenada do centro da Habilidade

for (int i = 0; i < 1; i++)
{   matrizHabilidade[cruz_y-3][cruz_x] = ATAQUE;
    for (int j = 1; j < 2; j++)
    {   matrizHabilidade[(cruz_y-3) + j][cruz_x] = ATAQUE;
        for (int k = 0; k < 5; k++)
        {   matrizHabilidade[cruz_y-1][(cruz_x-2)+k] = ATAQUE;
            for (int l = 5; l < 6; l++)
            {   matrizHabilidade[cruz_y][cruz_x] = ATAQUE;
                for (int m = 6; m < 7; m++)
                {   matrizHabilidade[cruz_y+1][cruz_x] = ATAQUE; 
                }
            } 
        }
    }
}

//========================================================       
// Habilidade Octaedro

int octa_y = 6, octa_x = 2; //Coordenada do centro da Habilidade

for (int i = 0; i < 1; i++)
{   matrizHabilidade[octa_y-1][octa_x] = ATAQUE;
    for (int j = 1; j < 4; j++)
    {   matrizHabilidade[octa_y][(octa_x-2)+j] = ATAQUE;
        for (int k = 4; k < 5; k++)
        {   matrizHabilidade[(octa_y+1)][octa_x] = ATAQUE;
        }
    } 
}

//========================================================       
// Apresentação do tabuleiro de Habilidades preenchido

printf("==== Tabuleiro Habilidades ====\n\n");

for (int i = 0; i < LETRAS; i++)
{
    printf("%c ", letras[i]);
}
printf("\n");

for (int i = 0; i < LINHAS; i++)
{
    for (int j = 0; j < COLUNAS; j++)
    {
        printf("%d ", matrizHabilidade[i][j]);
    }
    printf("\n");
}
printf("\n");

    

    return 0;
}
