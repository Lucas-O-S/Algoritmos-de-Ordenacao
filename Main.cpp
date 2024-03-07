#include <iostream>
#include "ClassePessoa.cpp"
#include <fstream>
#include <sstream>

using namespace std;

//Descobre o tamanho do vetor
int DefinirTamanhoVetor(string nomeArquivo){
   
   //cria variavel do arquivo
    fstream arquivo(nomeArquivo);

    // cria variavel do tamanho do vetor
    int tamanhoVetor = 0;

    //Verifica se arquivo foi aberto e devolve um erro caso não
    if(!arquivo.is_open()){
        cout << "Nao foi possivel abrir o arquivo";
        return -1;
    }

    //string para o dados de uma linha
    string linha;
   
   //Verifica o arquivo e enquanto receber linhas coloca o conteudo nela e adiciona +1 no tamanho
    while(getline(arquivo, linha )){
        tamanhoVetor ++;

    }

    //Retorna valor do tamanho do vetor
    return tamanhoVetor;
    
}

//metodo para retornar um ponteiro de ponteiro de um vetor de uma classe
Pessoa** CriarVetorPessoa(string nomeArquivo, int tamanho){
    
    //Cria o ponteiro de ponteiro de vetor a partir de um ponteiro de vetor que criar um vetor dinamico
    Pessoa** vetorPessoa = new Pessoa*[tamanho];

    //arquivo
    fstream  arquivo(nomeArquivo);
    
    
    string linha;

    int indice = 0;

        //Enquanto receber linhas ira adicionar novos membro ao arranjo
      while(getline(arquivo, linha )){

        //Strean de dados
        istringstream ss(linha);

        //Variaveis temporarias 
        string nome, dataNascimento, temporario;
        float peso, altura;

        //Pega o stream e coloca o primeiro valor até o primeiro separador e salva na variavel nome e reoete oara os proximos 
        getline(ss,nome,';');
        getline(ss,dataNascimento,';');

        // Em caso de variaveis não strings salva em uma string temporaria e converte
        getline(ss,temporario,';');
        peso = atof(temporario.c_str());

        getline(ss,temporario,';');
        altura = atof(temporario.c_str());



        //Salva uma nova pessoa ao vetor dinamico
        vetorPessoa[indice] = new Pessoa(nome,dataNascimento,peso,altura);

        
        indice++;
    }

    
    //Retorna o ponteiro de ponteiro
    return vetorPessoa;



}



int main()
{

    //Nome do arquivo CSV
    const string arquivoCSV = "dados_pessoais.csv";

    //Cria uma contante de tamannho do vetor com a função a seguir
    const int tamanhoVetor = DefinirTamanhoVetor(arquivoCSV);

    //Se o tamanho retornar -1 para o programa
    if(tamanhoVetor == -1){
        return -1;
    }

    //Cria um ponteiro de ponteiro de vetor para criar um vetor dinamico para uma metodo que devolve um vetor de uma classe
    Pessoa** vetorPessoa = CriarVetorPessoa(arquivoCSV, tamanhoVetor);
    
    
    //Teste para ver se foi salvo
    cout << vetorPessoa[1]->GetNome() << " - " << vetorPessoa[1]->GetIdade() << " - " << vetorPessoa[1]->GetPeso()  << " - " << vetorPessoa[1]->GetAltura() ;

   

    
}

