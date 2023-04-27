#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef int TipoFuncao();

// Protótipo da função de comparação
int ordemDecrescente(const void *a, const void *b);

// Protótipo da função para printar o vetor
void mostrarVetor(int *vetor, int tamanho);

int main(){

    int *vetor, tamanhoVetor, i;
    clock_t tempoPerdido; // não temos mais esse tempo que passou: https://youtu.be/m9YW0S-_R7w

    // Declaração do ponteiro para função
    TipoFuncao *ponteiro;

    printf("Digite quantas posicoes o vetor tem: ");
    scanf("%d", &tamanhoVetor);

    // Alocação de memória para o vetor    
    vetor = (int * )malloc(tamanhoVetor * sizeof(int));

    for (i = 0; i < tamanhoVetor; i++)
    {
        printf("Digite o valor da posicao %d do vetor: ", i);
        scanf("%d", &vetor[i]);    
    }
    
    printf("\nVetor Desordenado: ");

    mostrarVetor(vetor, tamanhoVetor);

    // Faz o ponteiro apontar para ordemDecrescente
    ponteiro = ordemDecrescente;

    tempoPerdido = clock();
    // Ordena o vetor em Ordem Decrescente
    for(i = 0; i < 1000000; i++)
    {
        qsort(vetor, tamanhoVetor, sizeof(int), *ponteiro);
    }
    tempoPerdido = clock() - tempoPerdido;

    printf("\nVetor em ordem Decrescente: ");

    mostrarVetor(vetor, tamanhoVetor);

    printf("\n\nTempo de processamento: %f", ((float)tempoPerdido)/ CLOCKS_PER_SEC);
    free(vetor);
    vetor = NULL;

    return 0;
}

int ordemDecrescente(const void *a, const void *b){
    if(*(int*)a == *(int*)b){
        return 0;
    }
    else{
        if (*(int*)a > *(int*)b)
        {
            return -1; // Valor de 'a' vem depois de 'b'
        }
        else
        {
            return 1; // valor de 'a' vem antes de 'b'
        }
    }
}

void mostrarVetor(int *vetor, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vetor[i]);
    }
}
