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

int main(){
	string read;
	avl_tree<GDate> T;
	vector<Node<GDate>*> interval;
	GDate min, max;

	T.add(GDate("1/5/2023"));
	T.add(GDate("2/5/2023"));
	T.add(GDate("3/5/2023"));
	T.add(GDate("4/5/2023"));
	T.add(GDate("5/5/2023"));
	T.add(GDate("6/5/2023"));
	T.add(GDate("7/5/2023"));
	T.add(GDate("8/5/2023"));
	T.add(GDate("9/5/2023"));
	T.add(GDate("10/5/2023"));

	T.bshow();

	try{
		while(true){
			vector<string> keys;
			cout << "Digite a data mínima: ";	
			cin >> read;
			try{
				min = GDate(read);
			}catch(invalid_argument e){
				cout << "Tipo da data inválida" << endl;
				continue;
			}
			cout << "Digite a data máxima: ";
			cin >> read;
			try{
				max = GDate(read);
			}catch(invalid_argument e){
				cout << "Tipo da data inválida" << endl;
				continue;
			}

			interval = T.searchNodeByInterval(min, max);

			for(Node<GDate>* ref : interval){
				keys.push_back(ref->key.toString());
			}

			sort(keys.begin(), keys.end());

			cout << "As chaves no intervalo são: ";

			if(keys.empty()){
				cout << "nenhuma";
			}

			for(string ref : keys){
				cout << ref << " ";
			}

			cout << endl;
		}
	}catch(exception e){

	}

	T.bshow();
	

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
