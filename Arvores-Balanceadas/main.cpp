/**************************************************
//
// Projeto 1 - Estrutura de Dados Avançada UFC
//
// Árvores Balanceadas (main file)
//
// Criação:     08 Mai 2023
// Atualização: 26 Mai 2023
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

// -----------------{readCSVFile}---------------
// > Pega todas a pessoas definidas em um arquivo
// > .csv e adiciona por referência em um vector.
// > 
// > No arquivo de texto cada pessoa é representada 
// > por uma linha que segue o seguinte modelo:
// > 
// > NationalID,GivenName,Surname,Birthday,City
// > 
// > Importate: Essa função considera a primeira
// > linha como uma cabeçalho. Portanto essa li-
// > nha é sempre desconsiderada.
// > 
// > filePath = "path do arquivo"
// > ref      = "referência para vetor de pessoas"
// -----------------------------------------------
void readCSVFile(const string& filePath, vector<Person>& ref);

// -----------------{readTextFile}---------------
// > Lé um arquivo de texto e coloca tudo em uma
// > string.
// >
// > path = "caminho do arquivo"
// > str  = "string de saida"
// -----------------------------------------------
string readTextFile(const string& path);

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
// > Mostra um nó genêrico em uma tabela
// > e seus valores duplicados caso existir.
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

// -----------{showNullNode}-----------
// > menssagem padrão para nós vazios
// ------------------------------------
void showNullNode();


int main()
{
	int command_idx; 		     //Índice de comando
	uint mainMenuOpcCount = 5;   //Número de opções do menu principal
	
	vector<Person> persons;      //Vetor com todas as pessoas
	
	avl_tree<llint> cpfTree;     //Árvore de CPFs
	avl_tree<string> nameTree;   //Árvore de nomes
	avl_tree<GDate> dateTree;    //Ávores de datas
	
	//Diz se a última leitura do termianl teve sucesso
	bool lastReadSucess = true;  

	//Esse divisor aparece no começo do terminal
	//para simbolizar a espera de uma entrada
	const string terminalDiv = ">>> ";

	//Lé arquivos de menu
	const string mainMenuPath = "menu-files/main-menu.txt";
	const string mainMenuText = readTextFile(mainMenuPath);

	//Lé pessoas do arquivo csv
	readCSVFile("data(reduzida).csv", persons);

	//Construindo as árvores
	for(Person& p : persons){
		cpfTree.add(p.getNumNationalID(), &p);
		nameTree.add(p.getFullName(), &p);
		dateTree.add(p.getBirthDay(), &p);

		cout << p << endl;
	}

	//----- { Main interativa } -----

	while(true){
		string line;	             //Linha lida do console	
		string command;				 //Commando passado para main
	    stringstream command_stream; //Stream de comandos

		//Mostra menu
		clear_terminal();
		cout << mainMenuText;

		if(!lastReadSucess){
			cout << "[digite um valor válido]" << endl;
		}

		cout << terminalDiv;

		//Lé commando passado pelo usuário
		getline(cin, line);
		command_stream << line;
		command_stream >> command;

		//Tenta conversão com stoi e faz tratamento de exceção
		try{
			command_idx = stoi(command);
			if(command_idx <= 0 || command_idx > mainMenuOpcCount){
				throw invalid_argument("Opção fora de alcance");
			}
			lastReadSucess = true;
		}catch(invalid_argument excp){
			lastReadSucess = false;
			continue;
		}
		
		cout << command_idx << endl;

		break;
	}

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

void readCSVFile(const string& path, vector<Person>& vet){
	ifstream in_stream; //Buffer de leitura
	string line;        //linha lida do arquivo

	//Limpa string
	line = "";

	in_stream.open(path);

	getline(in_stream, line); //linha de cabeçalho

	//Cheka se o arquivo abriu
	if(in_stream){
		//Adiciona todas as pessoas ao vetor
		while(getline(in_stream, line)){
			vet.push_back(Person(line));
		}
	}else{
		//Exceção ao tentar abrir o arquivo
		throw invalid_argument("Problem trying to reda file or " + path + " not exists");
	}
	

	//Fechando o arquivo
	in_stream.close();
}

string readTextFile(const string& path){
	ifstream in_stream; //Buffer de leitura
	string line;        //Linha lida do buffer
	string ret; 		//string de retorno

	//Limpa strings
	line = ret = "";

	in_stream.open(path);

	if(in_stream){
		//Adiciona todas as linhas na string
		while(getline(in_stream, line)){
			//Adiciona linha e pulo de linha
			ret += (line + "\n");
		}
	}else{
		//Exceção ao tentar abrir o arquivo
		throw invalid_argument("Problem trying to reda file or " + path + " not exists");
	}

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
