#include <stdlib.h>
#include <stdio.h>

//******************************
// typedef a seguir cria um tipo chamado 'TipoFuncao',
// que defini um tipo de dados que é uma função.
typedef int TipoFuncao();

int Load();

int Print();

int FuncaoInvalida();

int main()
{

    int opcao, retorno;
    // Cria um ponteiro que irá apontar para as duas funções criadas
    TipoFuncao *ptrF;

    do
    {
        printf("Digite sua opcao(1,2) :");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            ptrF = Load;
            break;
        case 2:
            ptrF = Print;
            break;
        default:
            ptrF = FuncaoInvalida;
            break;
        }
        retorno = (*ptrF)(); // chama uma função a partir de ptrF
                             // e obtem o retorno
        printf("Retorno da funcao: %d\n\n", retorno);
    } while (opcao < 3 && opcao > 0);

    return 0;
}

int Load()
{
    printf("Entrou em Load!\n");
    return 10;
}

int Print()
{
    printf("Entrou em Print!\n");
    return 20;
}

int FuncaoInvalida()
{
    printf("Opcao Invalida!\n");
    return 0;
}