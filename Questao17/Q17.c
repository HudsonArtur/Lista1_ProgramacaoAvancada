#include <stdlib.h>
#include <stdio.h>

//Função criada para somar dois vetores
//Argumentos: (ponteiro para inteiro 1, 
//ponteiro para inteiro 2, ponteiro para inteiro resultante,
// tamanho dos vetores)
void somaVetores(int *vetor1, int *vetor2, int *soma, int tam);

// Protótipo da função para printar o vetor
void mostrarVetor(int *vetor, int tamanho);

// Protótipo da função para povoar o vetor
void povoaVetor(int *vetor, int tam);

int main(){

    int *vetor1, *vetor2, *resultante;
    int tam;

    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &tam);

    vetor1 = (int *)malloc(tam * sizeof(int));

    vetor2 = (int *)malloc(tam * sizeof(int));

    resultante = (int *)malloc(tam * sizeof(int));

    printf("\n******Vetor 1******\n");
    povoaVetor(vetor1, tam);

    printf("\n******Vetor 2******\n");
    povoaVetor(vetor2, tam);

    somaVetores(vetor1,vetor2,resultante,tam);

    printf("\nVetor 1: ");
    mostrarVetor(vetor1, tam);
    
    printf("\nVetor 2: ");
    mostrarVetor(vetor2, tam);

    printf("\nResultante: ");
    mostrarVetor(resultante, tam);

    free(vetor1);
    free(vetor2);
    free(resultante);

    vetor1 = NULL;
    vetor2 = NULL;
    resultante = NULL;

    return 0;
}

void somaVetores(int *vetor1, int *vetor2, int *soma, int tam){
    for (int i = 0; i < tam; i++)
    {
        soma[i] = vetor1[i] + vetor2[i];
    }   
}

void mostrarVetor(int *vetor, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vetor[i]);
    }
}

void povoaVetor(int *vetor, int tam){
    for (int i = 0; i < tam; i++)
    {
        printf("\nEscreva o valor da posicao %d do vetor: ", i);
        scanf("%d", &vetor[i]); 
    }
    
}
