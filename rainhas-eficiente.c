#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAMANHO 17

unsigned long long int count;
int tabuleiro[TAMANHO];

/*Testa a solução*/
int testa_solucao(int linha,int coluna)
{
    for(int i=0;i<=linha;++i) 
    {
        if(tabuleiro[i]==coluna)
            return 0;
        else
        if(abs(tabuleiro[i]-coluna)==abs(i-linha))
            return 0; 
    } 
    return 1;
} 
void rainhas(int linha,int n){
    if(linha==n) 
        count++; //Achou uma solução
    else
    for(int coluna=0;coluna<n;++coluna) 
    {
        if(testa_solucao(linha,coluna))  
        {
            //Salva o número da coluna usando a linha como indice
            tabuleiro[linha]=coluna; 
            rainhas(linha+1,n); //Chama a proxima linha
        }
        tabuleiro[linha]=-1; //Reinicia a posição
    }
}
int main()
{
    int i,j;
    int n=TAMANHO;
    for(int i=0;i<TAMANHO;++i)
        tabuleiro[i]=-1;
    rainhas(0,n);
    fprintf(stderr,"%d SOLUCOES\n",count);
    return 0;
} 