#include <iostream>
#include <time.h>


//#include "ClassePessoa.cpp"


using namespace std;

#define tamanhoTeste 100 



void CopiarArranjo (Pessoa original[], Pessoa copia[], int tamanho){

    for(int i = 0; i < tamanho -1; i++ ){
        copia[i] = original[i];
    }
}

void ExibirArranjo(Pessoa arranjo[], int tamanho){
    for(int i = 0; i < tamanho-1; i++ ){
        arranjo[i].ExibirPessoa();
    }
}

void BubbleSort(Pessoa pessoas[], int tamanho){
    
    //Ajeitando antes de começar
    Pessoa* pessoasCopia = new Pessoa[tamanho];

    CopiarArranjo(pessoas, pessoasCopia, tamanho);

    //Começo de bubble sort
    
    //Salva o tempo antes de começar
    clock_t tempo = clock();

    for(int i = 0; i < tamanho - 1; i++){
        
        for(int j = 0; j < tamanho -1; j++){
            
            if(pessoasCopia[j].GetIdade() >= pessoasCopia[j+1].GetIdade()){
                Pessoa temp = pessoasCopia[j];
                pessoasCopia[j] = pessoasCopia[j+1];
                pessoasCopia[j+1] = temp;


            }


        }
            //cout << "\n" << i;

    }

    tempo = clock() - tempo;

    float tempoSegundos =   static_cast<float>(tempo)/CLOCKS_PER_SEC;

    cout << "Bubble sort levou " << tempoSegundos  << " segundos).\n";

    //ExibirArranjo(pessoasCopia, tamanhoTeste);

    

}

//Insertion Sort:
void InsertionSort(Pessoa pessoas[], int tamanho){
    
    //Ajeitando antes de começar
    Pessoa* pessoasCopia = new Pessoa[tamanho];

    CopiarArranjo(pessoas, pessoasCopia, tamanho);

    //Começo de Insertion sort
    
    //Salva o tempo antes de começar
    clock_t tempo = clock();

    for(int i = 1; i < tamanho - 1; i++){
        Pessoa chave = pessoasCopia[i];
        int j = i-1;

        while(j >=0 && chave.GetIdade() < pessoasCopia[j].GetIdade()){
            pessoasCopia[j+1] = pessoasCopia[j];
            j--;
        }

        pessoasCopia[j+1] = chave;

        //cout << "\n" << i;

    }

    tempo = clock() - tempo;

    float tempoSegundos =   static_cast<float>(tempo)/CLOCKS_PER_SEC;

    cout << "Insertion sort levou " << tempoSegundos  << " segundos).\n";

    //ExibirArranjo(pessoasCopia, tamanho);

    

}


//Selection Sort:
void SelectionSort(Pessoa pessoas[], int tamanho){
    
    //Ajeitando antes de começar
    Pessoa* pessoasCopia = new Pessoa[tamanho];

    CopiarArranjo(pessoas, pessoasCopia, tamanho);

    //Começo de Insertion sort
    
    //Salva o tempo antes de começar
    clock_t tempo = clock();

    for(int i = 0; i < tamanho - 1; i++){
        int menor = i;
        

        for(int j = i+1; j< tamanho - 1; j++){
            if(pessoasCopia[menor].GetIdade() > pessoasCopia[j].GetIdade()){
                menor = j;
            }
        }

        if(menor != i){
            Pessoa temp = pessoasCopia[i];
            pessoasCopia[i] = pessoasCopia[menor];
            pessoasCopia[menor] = temp;
        }
        //cout << "\n" << i;

    }

    tempo = clock() - tempo;

    float tempoSegundos =   static_cast<float>(tempo)/CLOCKS_PER_SEC;

    cout << "Selection sort levou " << tempoSegundos  << " segundos).\n";

    //ExibirArranjo(pessoasCopia, tamanho);

    

}

//MergeSort
void Merge(Pessoa pessoas[], int inicio, int meio, int fim){
    int tamanhoEsq = meio - inicio +1;
    int tamanhoDir = fim - meio;

    Pessoa pessoasEsq[tamanhoEsq], pessoasDir[tamanhoDir];

    for(int i = 0; i < tamanhoEsq; i++){
        pessoasEsq[i] = pessoas[inicio+i];
    }

    
    for(int i = 0; i < tamanhoDir; i++){
        pessoasDir[i] = pessoas[meio+i+1];
    }

    int i =0, j=0, k= inicio;

    while(i < tamanhoEsq && j < tamanhoDir ){

        if(pessoasEsq[i].GetIdade() <= pessoasDir[j].GetIdade()){
            pessoas[k] = pessoasEsq[i];
            i++;
            
        }
        else{
            pessoas[k] = pessoasDir[j];
            j++;

        }

        k++;

    }

    while(i < tamanhoEsq){
        pessoas[k] = pessoasEsq[i];
        i++;
        k++;

    }

    while(j < tamanhoDir){
        pessoas[k] = pessoasDir[j];
        j++;
        k++;

    }


}

void MergeSort(Pessoa pessoas[], int inicio, int fim){
    if(inicio < fim){
        int meio = inicio + (fim-inicio)/2;
        MergeSort(pessoas, inicio, meio);
        MergeSort(pessoas,meio+1, fim);

        Merge(pessoas,inicio,meio,fim);
    }
}

void IniciarMergeSort(Pessoa pessoas[], int tamanho){
  //Ajeitando antes de começar
    Pessoa* pessoasCopia = new Pessoa[tamanho];

    CopiarArranjo(pessoas, pessoasCopia, tamanho);

    //Começo de Insertion sort
    
    //Salva o tempo antes de começar
    clock_t tempo = clock();

    MergeSort(pessoasCopia,0,tamanho-1);

    tempo = clock() - tempo;

    float tempoSegundos =   static_cast<float>(tempo)/CLOCKS_PER_SEC;

    cout << "Merge sort levou " << tempoSegundos  << " segundos).\n";

    //ExibirArranjo(pessoasCopia, tamanho);

    

}


//Quick Sort
int particao(Pessoa pessoas[], int inicio, int fim){
    int pivo = pessoas[fim].GetIdade();

    int i = inicio-1;

    for(int j = inicio; j < fim; j++ ){
        if(pessoas[j].GetIdade() <= pivo){
            i++;
            swap(pessoas[i],pessoas[j]);

        }

    }
    
    i++;

    swap(pessoas[i],pessoas[fim]);

    return i;
}

void QuickSort(Pessoa pessoas[], int inicio, int fim){
    if(inicio < fim){
        int pivoPosicao = particao(pessoas, inicio, fim);

        QuickSort(pessoas, inicio, pivoPosicao-1);
        QuickSort(pessoas, pivoPosicao+1, fim);

    }
}

void IniciarQuickSort(Pessoa pessoas[], int tamanho){
    //Ajeitando antes de começar
    Pessoa* pessoasCopia = new Pessoa[tamanho];

    CopiarArranjo(pessoas, pessoasCopia, tamanho);

    //Começo de Insertion sort
    
    //Salva o tempo antes de começar
    clock_t tempo = clock();

    QuickSort(pessoasCopia, 0, tamanho-1);

    tempo = clock() - tempo;

    float tempoSegundos =   static_cast<float>(tempo)/CLOCKS_PER_SEC;

    cout << "Quick sort levou " << tempoSegundos  << " segundos).\n";

   // ExibirArranjo(pessoasCopia, tamanho);

}