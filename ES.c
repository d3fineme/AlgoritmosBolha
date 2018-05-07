#include <stdio.h>
#include <stdlib.h>
#include "ES.h"


//A fun��o de lerArquivo tem que ler os dados do arquivo de entrada
//que v�o conter as informa��es da quantidade de inst�ncias e do tamanho dessas inst�ncias
//Esse dados ser�o armazenados em um vetor alocado de forma din�mica, pois o valor
//da quantidade de inst�ncias n�o � fixo.
int *lerArquivo(char nomeArquivoEntrada[])
{
    int i=0,aux, primeira=0;//a var�vel primeira funciona como uma flag da leitura da primeira linha do arquivo
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
            vet = (int*) malloc((aux+1) * sizeof (int));//aloca o vetor do tamanho da qtde das inst�ncias definidas
            vet[i]=aux;//salva esse valor no primeiro elemento do vetor
            i++;
            primeira=1;//altera a flag
        }
        else{//l� o restante do arquivo e adiciona no restane do vetor
            fscanf(arq, "%d", &aux);
            vet[i]=aux;
            i++;
        }
    }

    fclose(arq);
    return vet;//retorna o vetor com as informa��es
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

//A fun��o geraVetorAleatorio vai crar o vetor de forma aleat�ria utilizando a semente informada
//pelo usu�rio.
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
