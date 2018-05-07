#include <stdio.h>
#include <stdlib.h>
#include "impl_bolhas.h"

void bolha(long long int vet[], long long int tam, long long int ctr[]) {
    long long int i, j, aux;
    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam - 1; j++) {
            ctr[0]++;
            if (vet[j] > vet[j + 1]) {
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
                ctr[1]++;
            }
        }
    }
    return;
}

void bolhaInteligente(long long int vet[], long long int tam, long long int ctr[]) {
    long long int i, j, aux;
    int troca = 0;
    for (i = 0; i < tam; i++) {
        j = 0;
        troca = 0;
        while (j < (tam-1-i)) {
            ctr[0]++;
            if (vet[j] > vet[j + 1]) {
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
                ctr[1]++;
                troca = 1;
            }
            j++;
        }
        if (troca == 0)
            return;
    }
    return;
}

void BubbleSort_2(long long int vet[], long long int tam, long long int ctr[])
{
    long long int i, j, troca=1;
    int aux;
    tam--;
    for(i=0; i<=tam/2&&troca; i++)
    {
        troca=0;
        for(j=i;j<=tam-i;j++)
        {
            ctr[0]++;
            if(vet[j] > vet[j+1])
            {
                aux=vet[j];
                vet[j]=vet[j+1];
                vet[j+1]=aux;
                troca=1;
                ctr[1]++;
            }
            ctr[0]++;
            if(vet[tam-j+1] < vet[tam-j])
            {
                aux=vet[tam-j];
                vet[tam-j]=vet[tam-j+1];
                vet[tam-j+1]=aux;
                troca=1;
                ctr[1]++;
            }
        }
    }
}
