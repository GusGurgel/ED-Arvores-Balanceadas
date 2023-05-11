/**************************************************
//
// Projeto 1 - Estrutura de Dados Avançada UFC
//
// Árvores Balanceadas (main file)
//
// Criação:     08 Mai 2023
// Atualização: 08 Mai 2023
//
// Criado Por:
// Nome: Gustavo Gurgel Medeiros
// Número de Matrícula [UFC]: 539226
//
************************************************/

#include "avl.h"
#include "gdate.h"
#include "person.h"

#include <iostream>//entrada e saida
#include <vector>  //vetores
#include <fstream> //leitura de arquivos
using namespace std;

//Pega todas a pessoas do arquivo
vector<Person*>* getFromFile(string);

int main() {
	vector<Person*>* persons = nullptr;

	persons = getFromFile("data(reduzida).csv");

	for(const Person* p : *(persons)){
		p->show();
	}

	delete persons;
	
	return 0;
}

vector<Person*>* getFromFile(string fileName){
	vector<Person*>* ret = new vector<Person*>(); //vetor de retorno
	ifstream in_stream; //Buffer de leitura
	string line; //linha lida do arquivo

	in_stream.open(fileName);

	getline(in_stream, line); //linha de cabeçalho

	//Adiciona todas as pessoas ao vetor
	while(getline(in_stream, line)){
		ret->push_back(new Person(line));
	}	

	return ret;
}