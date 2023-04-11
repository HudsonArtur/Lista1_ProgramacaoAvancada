#include <stdlib.h>
#include <stdio.h>

// Função criada para organizar na ordem crescente
// n números do tipo float.
void RearranjoFloat(float *vetorOrdenado, int quantNum);

void mostrarVetor(float *vetor, int tam);

int main()
{

    float *vetorOrdenado;
    int quantNum = 0, i;

    printf("Quantos numeros voce prentende digitar: ");
    scanf("%d", &quantNum);

    vetorOrdenado = (float *)malloc(quantNum * sizeof(float));

    for (i = 0; i < quantNum; i++)
    {
        printf("\nDigite um valor para a posicao %d do vetor: ", i);
        scanf("%f", &vetorOrdenado[i]);
    }

    printf("\nVetor Desordenado: ");

    mostrarVetor(vetorOrdenado, quantNum);

    RearranjoFloat(vetorOrdenado, quantNum);

    printf("\nVetor Ordenado: ");

    mostrarVetor(vetorOrdenado, quantNum);

    free(vetorOrdenado);
    vetorOrdenado = NULL;

    return 0;
}

void RearranjoFloat(float *vetorOrdenado, int quantNum)
{
    float inter;
    for (int i = 0; i < quantNum; i++)
    {
        for (int j = i; j < quantNum; j++)
        {
            if (vetorOrdenado[i] > vetorOrdenado[j])
            {
                inter = vetorOrdenado[j];
                vetorOrdenado[j] = vetorOrdenado[i];
                vetorOrdenado[i] = inter;
            }
        }
    }
}

void mostrarVetor(float *vetor, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%f ", vetor[i]);
    }
}