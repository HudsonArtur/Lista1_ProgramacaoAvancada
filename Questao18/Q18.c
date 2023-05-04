#include <stdlib.h>
#include <stdio.h>

// Função para multiplicar de forma matricial A e B,
// resultado deve ser depositado na matriz C.
// Multiplicação na forma AB.
void multiMatriz(int **matA, int **matB, int **matC, int linA, int colA, int colB);

// Protótipo para a função para povoar matrizes
void povoaMatriz(int **mat, int linhas, int colunas);

// Protótipo para a função que mostra a matriz na tela
void printaMatriz(int **mat, int linhas, int colunas);

int main()
{
#define LinA 3
#define ColA 2 // Coluna de A será também a quantidade de linhas de B
#define ColB 2

    int **matA, **matB, **matC;

    // aloca um vetor de 3 posições para as linhas
    matA = malloc(LinA * sizeof(int *));
    matB = malloc(ColA * sizeof(int *));
    matC = malloc(LinA * sizeof(int *));

    // aloca cada uma das linhas (vetores de linhas inteiros)
    for (int i = 0; i < LinA; i++)
    {
        matA[i] = malloc(ColA * sizeof(int));
    }

    for (int i = 0; i < ColA; i++)
    {
        matA[i] = malloc(ColB * sizeof(int));
    }
    for (int i = 0; i < LinA; i++)
    {
        matA[i] = malloc(ColB * sizeof(int));
    }

    printf("Povoe a matriz A: ");
    povoaMatriz(matA, LinA, ColA);

    printf("\nPovoe a matriz B: ");
    povoaMatriz(matB, ColA, ColB);

    multiMatriz(matA, matB, matC, LinA, ColA, ColB);

    printf("\n******MATRIZ A******\n");
    printaMatriz(matA, LinA, ColA);

    printf("\n\n******MATRIZ B******\n");
    printaMatriz(matB, ColA, ColB);

    printf("\n\n******MATRIZ RESULTANTE******\n");
    printaMatriz(matC, LinA, ColB);

    return 0;
}

void multiMatriz(int **matA, int **matB, int **matC, int linA, int colA, int colB)
{
    int aux = 0;
    for (int i = 0; i < linA; i++)
    {
        for (int j = 0; j < colB; j++)
        {
            aux = 0;
            for (int x = 0; x < colA; x++)
            {
                aux += matA[i][x] * matB[x][j];
            }
            matC[i][j] = aux;
        }
    }
}

void povoaMatriz(int **mat, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("\nPosicao [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}
void printaMatriz(int **mat, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf(" %d ", mat[i][j]);
        }
        printf("\n");
    }
}