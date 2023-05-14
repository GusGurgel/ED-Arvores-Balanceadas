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

// ---------{readFromFile(string)}---------
// > Pega todas a pessoas que definidas
// > um arquivo de texto e retorna em
// > formato de um vector.
// ---------------------------------------
vector<Person*>* readFromFile(string);

int main(){
	avl_tree<int> T;
	string read;
	int toFind = 0;
	
	for(int i = 0; i < 10; i++){
		T.add(i);
	}
	
	cout << boolalpha;
	
	T.bshow();
	
	while(true){
		cout << "Digite um nó a ser porcurado -> ";
		cin >> read;
		
		try{
			toFind = stoi(read);
			cout << "out -> ";
			cout << (T.searchNodeByKey(toFind) != nullptr) << endl; 
		}catch(exception e){
			toFind = 0;
			break;
		}
	}
	
	return 0;
}


//~ int main() {
	//~ vector<Person*>* persons = nullptr;
	//~ avl_tree<llint> TCPF;
	//~ avl_tree<string> TNome;
	//~ avl_tree<GDate>  TData;

	//~ persons = readFromFile("data(reduzida).csv");

	//~ for(const Person* p : *(persons)){
		//~ TCPF.add(p->getNumNationalID());
		//~ TNome.add(p->getGivenName());
		//~ TData.add(p->getBirthDay());
	//~ }
	
	//~ cout << "Ávore de CPFS: " << endl;
	//~ TCPF.bshow();
	//~ cout << "Ávore de Nomes: " << endl;
	//~ TNome.bshow();
	//~ cout << "Ávore de Datas: " << endl;
	//~ TData.bshow();

	//~ delete persons;
	
	//~ return 0;
//~ }

vector<Person*>* readFromFile(string fileName){
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
