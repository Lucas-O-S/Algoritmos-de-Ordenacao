#include <iostream>
#include <fstream>
#include <sstream>

#include "ClassePessoa.cpp"
#include "DadosNumeriocos.cpp"
#include "AlgoritmosDeOrdenacao.cpp"

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

//metodo para adicionar valores ao array
void CriarVetorPessoa(string nomeArquivo,  Pessoa* arranjoPessoas){
    

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
        arranjoPessoas[indice].AddValoresPessoa(nome,dataNascimento,peso,altura);

        
        indice++;
    }

    
    //Retorna o ponteiro de ponteiro



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

    //Cria array dinamico
    Pessoa* arranjoPessoas = new Pessoa[tamanhoVetor];


    CriarVetorPessoa(arquivoCSV,arranjoPessoas);

    int escolha;

    while(true){
        cout << "Deseja organizar arranjo com bese em qual parametro:";
        cout << "\n- 1: IDADE \n- 2: PESO \n- 3: ALTURA " << endl;
        cout << "Escolha: ";
        cin >> escolha;



        if(escolha < 0 || escolha > 3){
            cout << "-- Valor invalido --" << endl;
        }

        else{
            if(escolha - static_cast<int>(escolha) != 0){
                cout << "-- Valor invalido --" << endl;

            }
            else{
                break;

            }
        }   

    }

    BubbleSort(arranjoPessoas, tamanhoVetor,escolha);
    InsertionSort(arranjoPessoas, tamanhoVetor,escolha);
    SelectionSort(arranjoPessoas, tamanhoVetor,escolha);
    IniciarMergeSort(arranjoPessoas,tamanhoVetor,escolha);
    IniciarQuickSort(arranjoPessoas,tamanhoVetor,escolha);
    
}