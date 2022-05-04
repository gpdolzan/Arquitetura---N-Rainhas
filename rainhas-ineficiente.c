#include <stdio.h>

#define TAMANHO 15

unsigned long long int solucoes = 0;

int verifica_solucao(int v[TAMANHO][TAMANHO], int l, int c)
{
    for(int k = 0; k < l; k++)
        if(v[k][c] == 1)
            return 0;

    for(int i = 0; i < TAMANHO; i++)
        for(int j = 0; j < TAMANHO; j++)
            if((i + j == l + c) || (i - j == l - c))
                if(v[i][j] == 1)
                    return 0;

    return 1;
}

void rainhas(int v[TAMANHO][TAMANHO], int l)
{
    if(l > (TAMANHO - 1))
        solucoes++;
    else
        for(int c = 0; c < TAMANHO; c++)
        {
            if(verifica_solucao(v, l, c))
            {
                v[l][c] = 1;
                rainhas(v, l + 1);
            }
            v[l][c] = 0;
        }
}

int main()
{
    int arr[TAMANHO][TAMANHO];

    for(int i = 0; i < TAMANHO; i++)
        for(int j = 0; j < TAMANHO; j++)
            arr[i][j] = 0;

    rainhas(arr, 0);
    printf("solutions = %d\n", solucoes);
    return 0;
}