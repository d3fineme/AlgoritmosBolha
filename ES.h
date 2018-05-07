#ifndef ES_H
#define ES_H

int *lerArquivo(char nomeArquivoEntrada[]);
void escreveArquivo(char nomeArquivoSaida[], char tipoVet[], char metodo[], double tempo, long long int comp, long long int tr, long long int tam);
void geraVetorAleatorio(int semente, long long int tamanhoVet, long long int vet[]);
void geraVetorCrescente(long long int vet[], long long int tamanhoVet);
void geraVetorDecrescente(long long int vet[], long long int tamanhoVet);
void copiaVetor(long long int vetCopia[], long long int vetOriginal[], long long int tam);

//CRIAR O GERA ALEATÓRIO

#endif /* ES_H */

