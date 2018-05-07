#include <stdio.h>
#include <stdlib.h>
#include "ES.h"


//A função de lerArquivo tem que ler os dados do arquivo de entrada
//que vão conter as informações da quantidade de instâncias e do tamanho dessas instâncias
//Esse dados serão armazenados em um vetor alocado de forma dinâmica, pois o valor
//da quantidade de instâncias não é fixo.
int *lerArquivo(char nomeArquivoEntrada[])
{
    int i=0,aux, primeira=0;//a varável primeira funciona como uma flag da leitura da primeira linha do arquivo
    int *vet;
    FILE *arq;
    arq = fopen(nomeArquivoEntrada, "r");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo");
        return NULL;
    }

    while (!feof(arq)){
        if(primeira==0){//se estiver lendo a primeira linha do arquivo
            fscanf(arq, "%d", &aux);
            vet = (int*) malloc((aux+1) * sizeof (int));//aloca o vetor do tamanho da qtde das instâncias definidas
            vet[i]=aux;//salva esse valor no primeiro elemento do vetor
            i++;
            primeira=1;//altera a flag
        }
        else{//lê o restante do arquivo e adiciona no restane do vetor
            fscanf(arq, "%d", &aux);
            vet[i]=aux;
            i++;
        }
    }

    fclose(arq);
    return vet;//retorna o vetor com as informações
}

void escreveArquivo(char nomeArquivoSaida[], char tipoVet[], char metodo[], double tempo, long long int comp, long long int tr, long long int tam)
{
    FILE *arq;
    arq = fopen(nomeArquivoSaida, "a");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo");
        return;
    }
    fprintf(arq, "Tipo vetor: %s - Tamanho do vetor: %lld - Metodo %s - Tempo: %.16f s - Comparacoes: %lld - Trocas: %lld\n", tipoVet, tam, metodo, tempo, comp, tr);
    fclose(arq);
}

//A função geraVetorAleatorio vai crar o vetor de forma aleatória utilizando a semente informada
//pelo usuário.
void geraVetorAleatorio(int semente, long long int tamanhoVet, long long int vet[]){
    long long int i;
    srand(semente);
    for(i=0;i<tamanhoVet;i++){
        vet[i] = rand()%tamanhoVet;
    }
}

void geraVetorCrescente(long long int vet[], long long int tamanhoVet){
    long long int i;
    for(i=0;i<tamanhoVet;i++){
        vet[i]=i;
    }
}

void geraVetorDecrescente(long long int vet[], long long int tamanhoVet){
    long long int i, inverte = tamanhoVet-1;
    for (i=0;i<tamanhoVet;i++){
        vet[i] = inverte;
        inverte--;
    }
}

void copiaVetor(long long int vetCopia[], long long int vetOriginal[], long long int tam){
    long long int i;
    for(i=0;i<tam;i++){
        vetCopia[i]=vetOriginal[i];
    }
}
