

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

int CalcularIdade(string dataNascimento) {

	//Cria um variavel de stringstreams para separar a data de nascimento  de uma string
	istringstream ss(dataNascimento);

	//Variaveis para cada um
	int dia, mes, ano;

	//Variavel de delimitador
	char delimitador;

	// Adiciona cada parte da data de nascimento em cada variavel separando pelo delimitador
	ss >> dia >> delimitador >> mes >> delimitador >> ano;

	//Cria uma variavel de um ponto no tempo que representa hoje
	auto hoje = chrono::system_clock::now();

	//Converte o ponto para quantos segundos desde 1970
	time_t TempoHoje = chrono::system_clock::to_time_t(hoje);

	//Converte o tempo para representar o tempo local
	tm* hojeLocal = localtime(&TempoHoje);

	// Calcula a idade
	//Soma 1900 por causa que ele calcula os anos a partir de 1900 então falta 1900 anos se não fazer a soma
	int idade = hojeLocal->tm_year + 1900 - ano;

	//Verifica se a pessoa já fez aniversario no ano
	//Atravez do mês atual mais 1 ou do mes atual e o dia atual
	if (mes > hojeLocal->tm_mon + 1 || (mes == hojeLocal->tm_mon + 1 && dia > hojeLocal->tm_mday)) {
		idade--;
	}

	
	return idade;
}



class Pessoa {

	private:
		string nome, dataNascimento;
		int idade;
		float peso, altura;

		
	;

	public:


		//Construtor
		Pessoa(string nome, string dataNascimento, float peso, float altura) {
			this->nome = nome;
			this-> dataNascimento = dataNascimento;
			this->idade = CalcularIdade(dataNascimento);
			this->peso = peso;
			this->altura = altura;

		}

		string GetNome() {
			return nome;
		}

		int GetIdade() {
			return idade;
		}

		float GetPeso() {
			return peso;
		}

		float GetAltura() {
			return altura;
		}

	;



};