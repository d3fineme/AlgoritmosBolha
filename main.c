#include <stdio.h>
#include <time.h>
#include "ES.h"
#include "impl_bolhas.h"
#include <windows.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char semente[3], nomeArquivoEntrada[100], nomeArquivoSaida[100];
    strcpy(semente,argv[1]);
    strcpy(nomeArquivoEntrada,argv[2]);
    strcpy(nomeArquivoSaida,argv[3]);
    double tempo, freq, start, stop;
    int seed;
    int *vetConfiguracao;
    long long int i, ctr[] = {0,0};
    seed = atoi(semente);
    vetConfiguracao = lerArquivo(nomeArquivoEntrada);
    
    for(i=1;i<vetConfiguracao[0]+1;i++){
        long long int vetDesordenado[vetConfiguracao[i]];
        long long int vetCrescente[vetConfiguracao[i]];
        long long int vetDecrescente[vetConfiguracao[i]];
        long long int vetor[vetConfiguracao[i]];
        geraVetorAleatorio(seed, vetConfiguracao[i], vetDesordenado);
        geraVetorCrescente(vetCrescente, vetConfiguracao[i]);
        geraVetorDecrescente(vetDecrescente, vetConfiguracao[i]);


        //-----ORDENAÇÃO PARA VETOR ALEATÓRIO
        copiaVetor(vetor, vetDesordenado, vetConfiguracao[i]);
        QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
        QueryPerformanceCounter((LARGE_INTEGER *)&start);
        bolha(vetor, vetConfiguracao[i], ctr);
        QueryPerformanceCounter((LARGE_INTEGER *)&stop);
        tempo = ((double)stop-(double)start) / (double)freq;
        escreveArquivo(nomeArquivoSaida, "aleatorio", "bolha", tempo, ctr[0], ctr[1], vetConfiguracao[i]);

        ctr[0] = 0;
        ctr[1] = 0;
        copiaVetor(vetor, vetDesordenado, vetConfiguracao[i]);
        QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
        QueryPerformanceCounter((LARGE_INTEGER *)&start);
        bolhaInteligente(vetor, vetConfiguracao[i], ctr);
        QueryPerformanceCounter((LARGE_INTEGER *)&stop);
        tempo = ((double)stop-(double)start) / (double)freq;
        escreveArquivo(nomeArquivoSaida, "aleatorio", "bolhaInteligente", tempo, ctr[0], ctr[1], vetConfiguracao[i]);


        ctr[0] = 0;
        ctr[1] = 0;
        copiaVetor(vetor, vetDesordenado, vetConfiguracao[i]);
        QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
        QueryPerformanceCounter((LARGE_INTEGER *)&start);
        BubbleSort_2(vetor, vetConfiguracao[i], ctr);
        QueryPerformanceCounter((LARGE_INTEGER *)&stop);
        tempo = ((double)stop-(double)start) / (double)freq;
        escreveArquivo(nomeArquivoSaida, "aleatorio", "bubbleSort_2", tempo, ctr[0], ctr[1], vetConfiguracao[i]);

        ctr[0] = 0;
        ctr[1] = 0;
        //----FIM ORDENAÇÃO ALATÓRIO------


        //-----ORDENAÇÃO PARA VETOR CRESCENTE
        copiaVetor(vetor, vetCrescente, vetConfiguracao[i]);
        QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
        QueryPerformanceCounter((LARGE_INTEGER *)&start);
        bolha(vetor, vetConfiguracao[i], ctr);
        QueryPerformanceCounter((LARGE_INTEGER *)&stop);
        tempo = ((double)stop-(double)start) / (double)freq;
        escreveArquivo(nomeArquivoSaida, "crescente", "bolha", tempo, ctr[0], ctr[1], vetConfiguracao[i]);

        ctr[0] = 0;
        ctr[1] = 0;
        copiaVetor(vetor, vetCrescente, vetConfiguracao[i]);
        QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
        QueryPerformanceCounter((LARGE_INTEGER *)&start);
        bolhaInteligente(vetor, vetConfiguracao[i], ctr);
        QueryPerformanceCounter((LARGE_INTEGER *)&stop);
        tempo = ((double)stop-(double)start) / (double)freq;
        escreveArquivo(nomeArquivoSaida, "crescente", "bolhaInteligente", tempo, ctr[0], ctr[1], vetConfiguracao[i]);


        ctr[0] = 0;
        ctr[1] = 0;
        copiaVetor(vetor, vetCrescente, vetConfiguracao[i]);
        QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
        QueryPerformanceCounter((LARGE_INTEGER *)&start);
        BubbleSort_2(vetor, vetConfiguracao[i], ctr);
        QueryPerformanceCounter((LARGE_INTEGER *)&stop);
        tempo = ((double)stop-(double)start) / (double)freq;
        escreveArquivo(nomeArquivoSaida, "crescente", "bubbleSort_2", tempo, ctr[0], ctr[1], vetConfiguracao[i]);

        ctr[0] = 0;
        ctr[1] = 0;
        //----FIM ORDENAÇÃO CRESCENTE------

        //-----ORDENAÇÃO PARA VETOR DECRESCENTE
        copiaVetor(vetor, vetDecrescente, vetConfiguracao[i]);
        QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
        QueryPerformanceCounter((LARGE_INTEGER *)&start);
        bolha(vetor, vetConfiguracao[i], ctr);
        QueryPerformanceCounter((LARGE_INTEGER *)&stop);
        tempo = ((double)stop-(double)start) / (double)freq;
        escreveArquivo(nomeArquivoSaida, "decrescente", "bolha", tempo, ctr[0], ctr[1], vetConfiguracao[i]);

        ctr[0] = 0;
        ctr[1] = 0;
        copiaVetor(vetor, vetDecrescente, vetConfiguracao[i]);
        QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
        QueryPerformanceCounter((LARGE_INTEGER *)&start);
        bolhaInteligente(vetor, vetConfiguracao[i], ctr);
        QueryPerformanceCounter((LARGE_INTEGER *)&stop);
        tempo = ((double)stop-(double)start) / (double)freq;
        escreveArquivo(nomeArquivoSaida, "decrescente", "bolhaInteligente", tempo, ctr[0], ctr[1], vetConfiguracao[i]);


        ctr[0] = 0;
        ctr[1] = 0;
        copiaVetor(vetor, vetDecrescente, vetConfiguracao[i]);
        QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
        QueryPerformanceCounter((LARGE_INTEGER *)&start);
        BubbleSort_2(vetor, vetConfiguracao[i], ctr);
        QueryPerformanceCounter((LARGE_INTEGER *)&stop);
        tempo = ((double)stop-(double)start) / (double)freq;
        escreveArquivo(nomeArquivoSaida, "decrescente", "bubbleSort_2", tempo, ctr[0], ctr[1], vetConfiguracao[i]);

        ctr[0] = 0;
        ctr[1] = 0;
        //----FIM ORDENAÇÃO DECRESCENTE------

    }
}
