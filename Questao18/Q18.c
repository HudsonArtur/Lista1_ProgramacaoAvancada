#include <stdlib.h>
#include <stdio.h>

// Função para multiplicar de forma matricial A e B,
// resultado deve ser depositado na matriz C.
// Multiplicação na forma AB.
void multiMatriz(int **matA, int **matB, int **matC, int linA, int colA, int colB);

// Função para povoar matrizes
void povoaMatriz(int **mat, int linhas, int colunas);

// Função que mostra a matriz na tela
void printaMatriz(int **mat, int linhas, int colunas);

// Função para alocação de memória para matrizes
int ** alocaMemory(int linhas, int colunas);

// Função que libera a memória utilizada e
// atribue null para os ponteiros
void liberaMemory(int **mat, int linhas);

int main()
{
#define LinA 3
#define ColA 2 // Coluna de A será também a quantidade de linhas de B
#define ColB 2

    int **matA, **matB, **matC;

    matA = alocaMemory(LinA,ColA);
    
    matB = alocaMemory(ColA,ColB);

    matC = alocaMemory(LinA,ColB);

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

    liberaMemory(matA, LinA);

    liberaMemory(matB, ColA);
    
    liberaMemory(matC, LinA);

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

int ** alocaMemory(int linhas, int colunas){
    int **mat;

    mat = malloc(linhas * sizeof(int **));
    for (int i = 0; i < linhas; i++)
    {
        mat[i] = malloc(colunas * sizeof(int*));
    }
    return mat;
}

void liberaMemory(int **mat, int linhas){
    for (int i = 0; i < linhas; i++)
    {
        free(mat[i]);
    }

    free(mat);
    mat = NULL;
}