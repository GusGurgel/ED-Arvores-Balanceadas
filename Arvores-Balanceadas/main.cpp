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
// > Função que retorna se uma
// > string tem um certo prefíxo.
// >
// > prefix = "prefíxo"
// > str    = "string verificada"
// -------------------------------
bool isPrefix(const string& prefix, const string& str);

// -----------{addNodeOnTable}--------------
// > Adiciona os dados de uma pessoa que
// > estão dentro de um nó em uma tabela.
// >
// > node = "nó que vai ser adicionado"
// > table = "referência a tabela"
// -----------------------------------------
template<typename T>
void addNodeOnTable(Node<T>* node, GTable& table);

// -----------{showNodeWhitTable}----------
// > Mostra uma tabela com um nó genérico
// > e seus valores duplicados caso exis-
// > tir.
// >
// > vec = "ponteiro para o nó"
// -----------------------------------------
template<typename T>
void showNodeWhitTable(Node<T>* node);

// ---------{showVecNodeWhitTable}---------
// > mostra um vetor de nós genéricos no 
// > formato de uma tabela.
// >
// > vec = "ponteiro para o vetor de nós"
// -----------------------------------------
template<typename T>
void showVecNodeWhitTable(vector<Node<T>*>* vec);

// ---------{showVecNodeWhitTable}---------
// > menssagem padrão para nós vazios
// ----------------------------------------
void showNullNode();

int main()
{
    //Vetor com todas as pessoas
	vector<Person*>* persons = readFromFile("data(reduzida).csv");

	//Árvore de CPFs
	avl_tree<llint> cpfTree;
	//Árvore de nomes
	avl_tree<string> nameTree;
	//Ávores de datas
	avl_tree<GDate> dateTree;
	
	//Adicionando as informações das
	//pessoas na árvore
	for(Person* p : (*persons)){
		cpfTree.add(p->getNumNationalID(), p);
		nameTree.add(p->getFullName(), p);
		dateTree.add(p->getBirthDay(), p);

		cout << (*p) << endl;
	}

	makeLine(80);

	cpfTree.bshow();
	
	for(int i = 0; i < 5; i++){
		cout << endl;
	}

	nameTree.bshow();

	for(int i = 0; i < 5; i++){
		cout << endl;
	}

	dateTree.bshow();

	//--Limpando vetor de Pessoas--
	for(Person* p : (*persons)){
		delete p;
	}
	persons->clear();
	delete persons;
	//-----------------------------

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
	//vetor de retorno
	vector<Person*>* ret = new vector<Person*>(); 
	ifstream in_stream; //Buffer de leitura
	string line; //linha lida do arquivo

	in_stream.open(fileName);

	getline(in_stream, line); //linha de cabeçalho

	//Adiciona todas as pessoas ao vetor
	while(getline(in_stream, line)){
		ret->push_back(new Person(line));
	}

	//Fechando o arquivo
	in_stream.close();	

	return ret;
}

template<typename T>
void addNodeOnTable(Node<T>* node, GTable& table){
	Person* p = node->toPerson;
	
	//Adicionando pessoa do nó na tabela
	table.addRow(vector<string> {p->getNationalID(), p->getGivenName(), p->getSurname(), p->getCity(), p->getBirthDayString()});

	//Adicionando valores duplicados
	if(node->dupes != nullptr){
		for(Node<T>* dupe : (*node->dupes)){
			Person* pd = dupe->toPerson;
			table.addRow(vector<string> {pd->getNationalID(), pd->getGivenName(), pd->getSurname(), pd->getCity(), pd->getBirthDayString()});
		}
	}
}

template<typename T>
void showNodeWhitTable(Node<T>* node){
	//Caso vetor null ou vazio
	if(node == nullptr){
		showNullNode();
		return;
	}

	//Cria uma tabela
	GTable table(1);

	//Cabeçalho
	table.addRow(vector<string> {"CPF", "Primeiro Nome", "Sobrenome", "Aniversário", "Cidade Natal"});

	//Adiciona nó na tabela
	addNodeOnTable(node, table);

	table.show();
}

template<typename T>
void showVecNodeWhitTable(vector<Node<T>*>* vec){
	//Caso vetor null ou vazio
	if(vec == nullptr || vec->size() == 0){
		showNullNode();
		return;
	}

	//Cria um tabela
	GTable table(1);

	//Cabeçalho
	table.addRow(vector<string> {"CPF", "Primeiro Nome", "Sobrenome", "Aniversário", "Cidade Natal"});

	int test = 0;

	//Adiciona todos os nós
	for(Node<T>* node : (*vec)){
		addNodeOnTable(node, table);
	}

	table.show();
}

void showNullNode(){
	GTable table(1);
	const string text = "nenhum valor encontrado";

	table.addRow(vector<string> {text});
	table.show();
}
