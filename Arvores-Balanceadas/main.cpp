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
#include "gtable.h"

#include <iostream>//entrada e saida
#include <vector>  //vetores
#include <fstream> //leitura de arquivos

using namespace std;

// -----------{clear}-----------
// > Limpa o terminal. 
// > Testado e funcionando em:
// > 1. bash
// > 2. git-bash
// > 3. windows cmd
// -----------------------------
void clear_terminal();

// -----------------{readFromFile}---------------
// > Pega todas a pessoas definidas em um arquivo 
// > de texto e retorna em formato de um vector. 
// > No arquivo de texto cada pessoa é representada 
// > por uma linha que segue o seguinte modelo:
// > 
// > NationalID,GivenName,Surname,Birthday,City
// > 
// > Importate: Essa função considera a primeira
// > linha como uma cabeçalho. Portanto essa li-
// > nha é sempre desconsiderada.
// >
// > filePath = "endereço do arquivo"
// -----------------------------------------------
vector<Person*>* readFromFile(string filePath);

// ----------{isPrefix}----------
// > Função que retorna true sé
// > prefix é prefíxo da string
// > str
// >
// > prefix = "prefíxo"
// > str    = "string verificada"
// -------------------------------
bool isPrefix(const string& prefix, const string& str);

// ---------{showVecNodeWhitTable}---------
// > mostra um vetor de nós genéricos no 
// > formato de uma tabela.
// >
// > vec = "ponteiro para o vetor de nós"
// -----------------------------------------
template<typename T>
void showVecNodeWhitTable(vector<Node<T>*>* vec);

int main()
{
    vector<Person*>* persons = readFromFile("data(reduzida).csv");
	avl_tree<string> T;
	char resp;
	string prefix;
	vector<Node<string>*> res;

	for(Person* p : (*persons)){
		string name = p->getGivenName()+" "+p->getSurname();
		T.add(name, p);
	}
	
	do{
		clear_terminal();
		cout << "Digite um prefixo para procurar: ";
		cin >> prefix;

		res = T.searchNodeByPrefix(prefix, isPrefix);
		showVecNodeWhitTable(&res);
		cout << endl;
		cout << "Continuar(S/N)?: ";
		cin >> resp;

	}while(resp == 'S' | resp == 's');

	for(Person* p : (*persons)){
		delete p;
	}
	persons->clear();
	delete persons;

    return 0;
}

void clear_terminal(){
    printf("\033c");
}

bool isPrefix(const string& prefix, const string& str){
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

template<typename T>
void showVecNodeWhitTable(vector<Node<T>*>* vec){
	GTable table(1);
	//Caso vetor null ou vazio
	if(vec == nullptr || vec->size() == 0){
		string text = "nenhum valor encontrado";
		table.addRow(vector<string> {text});
		table.show();
		return;
	}

	//Cabeçalho
	table.addRow(vector<string> {"CPF", "Nome", "Sobrenome", "Aniversário", "Cidade Natal"});


	//Gustavo, faça a função adicionar os dupes
	for(Node<T>* node : (*vec)){
		Person* p = node->toPerson;
		table.addRow(vector<string> {p->getNationalID(), p->getGivenName(), p->getSurname(), p->getCity(), p->getBirthDayString()});
	}

	table.show();
}

