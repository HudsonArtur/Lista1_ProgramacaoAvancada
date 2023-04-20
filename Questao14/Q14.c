#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Função criada para organizar na ordem crescente
// n números do tipo float.
int RearranjoFloat(const void *a, const void *b);

// Função criada para mostrar os vetores na tela
void mostrarVetor(float *vetor, int tam);

int main()
{

    float *vetorOrdenado; // Declaração do ponteiro para float
    int quantNum = 0, i;  // Declaração das variáveis auxiliares
    double tempoPerdido, tempoFim, tempoInicio;

    // Parte do código que solicita o tamanho do vetor ao usuário
    printf("Quantos numeros voce prentende digitar: ");
    scanf("%d", &quantNum);

    vetorOrdenado = (float *)malloc(quantNum * sizeof(float)); // Alocação de memória para o vetor

    // Solicitando valores para o vetor ao usuário
    for (i = 0; i < quantNum; i++)
    {
        printf("\nDigite um valor para a posicao %d do vetor: ", i);
        scanf("%f", &vetorOrdenado[i]);
    }

    printf("\nVetor Desordenado: ");

    mostrarVetor(vetorOrdenado, quantNum);

    // Chamada da função qsort(), função utilizada para ordenação de vetores
    // seus parâmetros são (vetor_A_Ser_Ordenado, tamanho_do_vetor, sizeof(tipo_do_vetor), funcao_comparacao)
    tempoInicio = clock();
    qsort(vetorOrdenado, quantNum, sizeof(float), RearranjoFloat);
    tempoFim = clock();

    printf("\nVetor Ordenado: ");

    mostrarVetor(vetorOrdenado, quantNum);
    
    tempoPerdido = (double) (tempoFim - tempoInicio);

    printf("\n\nTempo de processamento: %f", tempoPerdido);
    
    free(vetorOrdenado);  // Libera a memória
    vetorOrdenado = NULL; // Atribui valor nulo ao vetor

    return 0;
}

// Função de fato, modificada para retornar indices
// por meio de comparações que fornecem informações
// sobre a posição de determinado valor no vetor
int RearranjoFloat(const void *a, const void *b)
{
    if (*(float *)a == *(float *)b)
    {
        return 0; // valores 'a' e 'b' iguais
    }
    else
    {
        if (*(float *)a < *(float *)b)
        {
            return -1; // valor 'a' vem antes de 'b'
        }
        else
        {
            return 1; // valor 'a' vem depois de 'b'
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