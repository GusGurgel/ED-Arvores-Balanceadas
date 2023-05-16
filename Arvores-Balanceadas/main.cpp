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


#include <algorithm>//delete depois
using namespace std;

// ---------{readFromFile(string)}---------
// > Pega todas a pessoas que definidas
// > um arquivo de texto e retorna em
// > formato de um vector.
// ---------------------------------------
vector<Person*>* readFromFile(string);

bool isPrefix(string prefix, string str);

void clear();

int main(){
	avl_tree<string> T;
	vector<Node<string>*> vet;
	vector<string> keys;

	ifstream in_stream; //Buffer de leitura
	string str; //linha lida do arquivo

	in_stream.open("lero.txt");

	//Adiciona todas as pessoas ao vetor
	while(in_stream >> str){
		T.add(getStringWithout(str, ",."));
	}	

	

	while(true){
		vector<string> keys;
		
		clear();

		makeLine(50);

		T.bshow();
		string prefix;
		makeLine(50);
		cout << endl << "Digite um prefixo a ser procurado: ";
		cin >> prefix;	

		vet = T.searchNodeByPrefix(prefix, isPrefix);

		for(Node<string>* ref : vet){
			keys.push_back(ref->key);
		}

		sort(keys.begin(), keys.end());

		cout << "Os prefíxos encontrados foram: (";

		for(string s : keys){
			cout << "\"" << s << "\" ";
		}

		cout << ")" << endl;

		cin >> prefix;

		cout << endl;
	}

	return 0;
}

void clear(){
	try{
		system("clear");
	}catch(exception e){

	}
}

bool isPrefix(string prefix, string str){
	if(prefix > str){
		return false;
	}

	for(int i = 0; i < prefix.size(); i++){
		if(prefix[i] != str[i]){
			return false;
		}
	}

	return true;
}

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

	in_stream.close();	

	return ret;
}
