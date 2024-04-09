//codigo para buscar dados como media, mediana e desvio padrão
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>



using namespace std;

// Função para calcular a média do vetor Pessoa
double calcularMedia(Pessoa pessoa[], int tamanhoPessoa, int escolha)
{
    float soma = 0;

    for (int i = 0; i < tamanhoPessoa; i++)
    {
        soma += pessoa[i].EscolhaDado(escolha);
    }

    return static_cast <double> (soma) / tamanhoPessoa;
}

//Função para calcular a mediana do vetor Pessoa
double calcularMediana(Pessoa pessoa[], int tamanhoPessoa, int escolha)
{

    if (tamanhoPessoa % 2 == 0) {
        // Se o tamanho for par, calcula a média dos dois valores do meio
        int indice1 = tamanhoPessoa / 2 - 1;
        int indice2 = tamanhoPessoa / 2;
        return (pessoa[indice1].EscolhaDado(escolha) + pessoa[indice2].EscolhaDado(escolha)) / 2.0;
    }
    else {
        // Se o tamanho for ímpar, retorna o valor do meio
        return pessoa[tamanhoPessoa / 2].EscolhaDado(escolha);
    }
}

double CalcularDesvio(Pessoa pessoa[], int tamanhoPessoa, int escolha, double media){
    double variancia;

        for (int i = 0; i < tamanhoPessoa; i++)
    {
        variancia += pow((media - pessoa[i].EscolhaDado(escolha)),2);
    }

    variancia /= tamanhoPessoa;

    double desvio   = sqrt(variancia);

    return desvio;
}