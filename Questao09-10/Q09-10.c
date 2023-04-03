#include <stdlib.h>

int main()
{

    int tam = 4, i;

    // Declaração dos vetores

    char x[tam];
    int y[tam];
    float z[tam];
    double d[tam];

    //Endereçamento dos vetores

    printf("x eh do tipo: char! e tem o endereco original: %p\n", x);
    for (i = 1; i <= tam; i++)
    {
        printf("Endereco de x + %d: %p\n\n", i, x + i);
    }

    printf("x eh do tipo: int! e tem o endereco original: %p\n", y);
    for (i = 1; i <= tam; i++)
    {
        printf("Endereco de x + %d: %p\n\n", i, y + i);
    }

    printf("x eh do tipo: float! e tem o endereco original: %p\n", z);
    for (i = 1; i <= tam; i++)
    {
        printf("Endereco de x + %d: %p\n\n", i, z + i);
    }

    printf("x eh do tipo: double! e tem o endereco original: %p\n", d);
    for (i = 1; i <= tam; i++)
    {
        printf("Endereco de x + %d: %p\n\n", i, d + i);
    }

    return 0;
}