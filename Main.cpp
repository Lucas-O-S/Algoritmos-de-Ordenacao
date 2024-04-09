#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

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
    return tamanhoVetor-1;
    
}

//metodo para adicionar valores ao array
void CriarVetorPessoa(string nomeArquivo,  Pessoa* arranjoPessoas){
    

    //arquivo
    fstream  arquivo(nomeArquivo);
    
    
    string linha;

    int indice = 0;

    bool ignorarPrimeiro = false;


    //Enquanto receber linhas ira adicionar novos membro ao arranjo
      while(getline(arquivo, linha )){

        if(!ignorarPrimeiro){
            ignorarPrimeiro = true;
            continue;
        }    
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

    cout << "\n";

    //BubbleSort(arranjoPessoas, tamanhoVetor,escolha);
    //InsertionSort(arranjoPessoas, tamanhoVetor,escolha);
    //SelectionSort(arranjoPessoas, tamanhoVetor,escolha);
    //IniciarMergeSort(arranjoPessoas,tamanhoVetor,escolha);
    IniciarQuickSort(arranjoPessoas,tamanhoVetor,escolha);
    
    //////////////////////////////////////////////////////////////////////////////////////

    cout << "\n";

    //Devolve a média da
    double idadeMedia = calcularMedia(arranjoPessoas, tamanhoVetor, 1);
    double pesoMedia = calcularMedia(arranjoPessoas, tamanhoVetor, 2);
    double alturaMedia = calcularMedia(arranjoPessoas, tamanhoVetor, 3);

    //Devolve mediana
    QuickSort(arranjoPessoas,0,tamanhoVetor, 1); 
    double idadeMediana = calcularMediana(arranjoPessoas,tamanhoVetor,1);

    QuickSort(arranjoPessoas,0,tamanhoVetor, 2); 
    double pesoMediana = calcularMediana(arranjoPessoas,tamanhoVetor,2);

    QuickSort(arranjoPessoas,0,tamanhoVetor, 3); 
    double alturaMediana = calcularMediana(arranjoPessoas,tamanhoVetor,3);

    double idadeDesvio = CalcularDesvio(arranjoPessoas,tamanhoVetor, 1, idadeMedia);
    double pesoDesvio = CalcularDesvio(arranjoPessoas,tamanhoVetor, 2, pesoMedia);
    double alturaDesvio = CalcularDesvio(arranjoPessoas,tamanhoVetor, 3, alturaMedia);



    cout << fixed << setprecision(2) << "Idade: \n Media - " << idadeMedia << "\n Mediana: " << idadeMediana << "\n Desvio Padrao: " << idadeDesvio << "\n" << endl;
    cout << fixed << setprecision(2) << "Peso: \n Media - " << pesoMedia  << "\n Mediana: " << pesoMediana << "\n Desvio Padrao: " << pesoDesvio <<  "\n" << endl;
    cout << fixed << setprecision(2) << "Altura: \n Media - " << alturaMedia << "\n Mediana: " << alturaMediana << "\n Desvio Padrao: " << alturaDesvio <<  "\n" << endl;




    cout << "";
}