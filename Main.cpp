#include <iostream>
#include "ClassePessoa.cpp"
#include <fstream>
#include <sstream>

using namespace std;

int DefinirTamanhoVetor(string nomeArquivo){
   
    fstream arquivo(nomeArquivo);

    int tamanhoVetor = 0;

    
    if(!arquivo.is_open()){
        cout << "Nao foi possivel abrir o arquivo";
        return -1;
    }

    string linha;
   
    while(getline(arquivo, linha )){
        tamanhoVetor ++;

    }

    return tamanhoVetor;
    
}

Pessoa** CriarVetorPessoa(string nomeArquivo, int tamanho){
    
    Pessoa** vetorPessoa = new Pessoa*[tamanho];

    fstream  arquivo(nomeArquivo);
    

    string linha;
    int indice = 0;

   
      while(getline(arquivo, linha )){
        istringstream ss(linha);

        string nome, dataNascimento, temporario;
        float peso, altura;

        getline(ss,nome,';');
        getline(ss,dataNascimento,';');

        getline(ss,temporario,';');
        peso = atof(temporario.c_str());

        getline(ss,temporario,';');
        altura = atof(temporario.c_str());




        vetorPessoa[indice] = new Pessoa(nome,dataNascimento,peso,altura);


        indice++;
    }

    

    return vetorPessoa;



}

int main()
{


    const string arquivoCSV = "dados_pessoais.csv";

    const int tamanhoVetor = DefinirTamanhoVetor(arquivoCSV);


    if(tamanhoVetor == -1){
        return -1;
    }

    Pessoa** vetorPessoa = CriarVetorPessoa(arquivoCSV, tamanhoVetor);;
    
    

    cout << vetorPessoa[1]->GetNome() << " - " << vetorPessoa[1]->GetIdade() << " - " << vetorPessoa[1]->GetPeso()  << " - " << vetorPessoa[1]->GetAltura() ;

   

    
}

