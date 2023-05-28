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
// > retona a quantidade de linhas da tabe-
// > la.
// >
// > vec = "ponteiro para o nó"
// -----------------------------------------
template<typename T>
uint showNodeWhitTable(Node<T>* node);

// ---------{showVecNodeWhitTable}---------
// > mostra um vetor de nós genéricos no 
// > formato de uma tabela. Retorna quanti-
// > dade de linhas da tabela.
// >
// > vec = "ponteiro para o vetor de nós"
// -----------------------------------------
template<typename T>
uint showVecNodeWhitTable(vector<Node<T>*>* vec);

// -----------{showNullNode}-----------
// > menssagem padrão para nós vazios
// ------------------------------------
void showNullNode();

// ------- { Funções Main Interativa } ---------

// ---------------{getLineFtsString}---------------
// > Lé uma linha completa do terminal e retorna
// > apenas a primeira string
// ----------------------------------------------
string getLineFtsString();

// ---------------{stringToIntMax}---------------
// > Converte uma string em inteiro positivo se 
// > não ultrapassar o valor máximo passado. 
// > Depois coloca o resultado em ref. Caso
// > a leitura seja bem sucedida retorna true.
// > 
// > str = "string a converter"
// > ref = "referência para receber conversão"
// > max = "Valor máximo de conversão"
// ----------------------------------------------
bool stringToIntMax(string str, uint& ref, const uint max);

// ---------------{idStringToLLINT}---------------
// > Converte uma string em formata de cpf em
// > um long long int
// -----------------------------------------------
llint idStringToLLINT(string str);

// ---------------{showSearchInfo}---------------
// > Mostra as informações de busca em uma cé-
// > lula de tabela.
// >
// > info = "String com informção de pesquisa"
// > cont = "Quantidades de encontros da pesquisa"
// ----------------------------------------------
void showSearchInfo(const string& info, uint cont);

// ---------------{idStringToLLINT}---------------
// > De uma efetua uma pausa, esperando que uma
// > tecla seja acionada.
// ----------------------------------------------
void menuPause();

int main()
{
	vector<Person> persons;      //Vetor com todas as pessoas
	
	avl_tree<llint> cpfTree;     //Árvore de CPFs
	avl_tree<string> nameTree;   //Árvore de nomes
	avl_tree<GDate> dateTree;    //Ávores de datas

	//Expreção regular de cpf
	regex idRegex ("\\d{3}.\\d{3}.\\d{3}-\\d{2}");

	//------ {Definição de Variáveis de Menu} -------

	//Informações de busca
	string serachInfo;

	//Número de opções do menu principal
	const uint mainMenuLen = 5;  

	//Diz se a última leitura do terminal teve sucesso
	bool readResult = true;  
	
	//Esse divisor aparece no começo do terminal
	//para simbolizar a espera de uma entrada
	const string terminalDiv = ">>> ";

	//Menssagem de valor inválido
	const string invalid_menssage = terminalDiv + "[Write a valid value!]";

	//Pasta com arquivos de menu
	const string menuFolder = "menu-files/";

	//Paths
	const string mainMenuPath = menuFolder + "main-menu.txt";
	const string mainIDPath =  menuFolder + "main-id.txt";
	const string mainBirthPath =  menuFolder + "main-birthday.txt";
	const string mainNamePath =  menuFolder + "main-name.txt";

	//Leituras dos arquivos de menu
	const string mainMenuText = readTextFile(mainMenuPath);
	const string mainIDText = readTextFile(mainIDPath);
	const string mainBirthText = readTextFile(mainBirthPath);
	const string mainNameText = readTextFile(mainNamePath);
	
	//------ {Construção da Árvore de Pessoas} -------

	//Lé pessoas do arquivo csv
	readCSVFile("data.csv", persons);

	//Construindo as árvores
	for(Person& p : persons){
		cpfTree.add(p.getNumNationalID(), &p);
		nameTree.add(p.getFullName(), &p);
		dateTree.add(p.getBirthDay(), &p);
	}

	//----- { Main interativa } -----

	while(true){
		uint command_idx;  //Índice de comando
		string command;	  //Commando			

		//Mostra menu
		clear_terminal();
		cout << mainMenuText;

		//A última leitura deu problema
		if(!readResult){
			cout << invalid_menssage << endl;
		}

		cout << terminalDiv;

		//Lé commando passado pelo usuário
		command = getLineFtsString();

		//Tenta conversão com stoi e faz tratamento de exceção
		readResult = stringToIntMax(command, command_idx, mainMenuLen);

		//Leitura não foi bem sucedida
		if(!readResult){
			continue;
		}
		
		/*Procura por NationalID*/
		if(command_idx == 1){
			smatch regexMatch;        //Procura expressões regulares
			string idToFind;          //ID que vai ser procurado
			llint  idNumToFind;		  //Valor numérico do ID	
			bool idReadSucess = true; //Sucesso de leitura

			//Loop para pegar valor correto
			while(true){
				clear_terminal();
				//Mostra o menu
				cout << mainIDText;

				//Passagem de valor inválida
				if(!idReadSucess){
					cout << invalid_menssage << endl;
				}

				//Coloca divisória no terminal
				cout << terminalDiv;
				//Pega primeira string passada pelo usuário
				idToFind = getLineFtsString();

				//Ver se opção de sair foi selecionada
				try{
					if(stoi(idToFind) == 1){
						break;
					}
				}catch(exception e){}

				//Procura pelo ID
				regex_search(idToFind, regexMatch, idRegex);

				if(regexMatch.empty()){
					idReadSucess = false;
					continue;
				}
				
				//Pega ID na forma de número
				idNumToFind = idStringToLLINT(idToFind);

				//Limpa terminal
				clear_terminal();

				//Mostra a tabela
				Node<llint>* res = cpfTree.searchNodeByKey(idNumToFind);

				//Mostra tabela e pega quantidade de
				//elementos
				uint cont = showNodeWhitTable(res);
				cout << endl;

				//Mostra informações de busca
				serachInfo = "ID searched: " + idToFind;
				showSearchInfo(serachInfo, cont);

				menuPause();
			}
		/*Intervalo de data*/
		}else if(command_idx == 2){
			//Infroma se a última leitura teve sucesso
			bool birthReadSucess = true;

			string dateStr1;
			string dateStr2;
			GDate date1;
			GDate date2;

			//loop para pegar o valor correto
			while(true){
				//Limpa terminal
				clear_terminal();

				stringstream input_stream; //Stream de input
				string line;               //Linha lida

				//Mostra menu de data de nascimento
				cout << mainBirthText << endl;
				
				if(!birthReadSucess){
					cout << invalid_menssage << endl;
				}

				//Mostra divisória do terminal
				cout << terminalDiv;

				//Lé linha digitada pelo usuário
				getline(cin, line); 

				//Pega os valores da primeira e segunda data
				input_stream << line;
				input_stream >> dateStr1;
				input_stream >> dateStr2;

				//Ver se opção de sair foi selecionada
				try{
					//O tamanho tem que ser igual a 
					//1 para não entrar em conflito
					//com datas do mês de janeiro
					//tipo 1/1/2023
					if(dateStr1.size() == 1 && stoi(dateStr1) == 1){
						break;
					}
				}catch(exception e){}

				try{
					date1 = GDate(dateStr1);
					date2 = GDate(dateStr2);
					//O mínimo é maior que o máximo
					if(date1 > date2){
						throw invalid_argument("Min date > Max date");
					}
				}catch(exception e){
					birthReadSucess = false;
					continue;
				}
				
				//Limpa o terminal
				clear_terminal();

				//Pega vetor com as datas no intervalo
				vector<Node<GDate>*> res = dateTree.searchNodeByInterval(date1, date2);

				//Mostra em formato de tabela
				uint cont = showVecNodeWhitTable(&res);
				cout << endl;

				//Mostra informações de busca
				serachInfo = "Date interval: [" + dateStr1 + "] - [" + dateStr2 + "]"; 
				showSearchInfo(serachInfo, cont);

				//Pausa menu
				menuPause();
			}
		/*Prefixo de nome*/
		}else if(command_idx == 3){
			string prefix;
			
			//Loop de leitura
			while(true){
				//Limpa terminal
				clear_terminal();

				//Mostra menu de busca de nome
				cout << mainNameText << endl;

				//Mostra divisão de terminal
				cout << terminalDiv;

				//Pega o prefixo
				getline(cin, prefix);

				try{
					if(stoi(prefix) == 1){
						break;
					}
				}catch(exception e){}

				vector<Node<string>*> res = nameTree.searchNodeByPrefix(prefix, isPrefix);

				//limpa terminal
				clear_terminal();

				uint cont = showVecNodeWhitTable(&res);
				cout << endl;

				//Mostra informações de busca
				serachInfo = "Prefix: \"" + prefix + "\""; 
				showSearchInfo(serachInfo, cont);

				menuPause();
			}
		/*Mostrar todas as pessoas*/
		}else if(command_idx == 4){
			//limpa o terminal
			clear_terminal();

			//Todo nome tem vazio como prefíxo
			vector<Node<string>*> all = nameTree.searchNodeByPrefix("", isPrefix);

			reverse(all.begin(), all.end());

			//Mostra a tabel
			uint cont = showVecNodeWhitTable(&all);
			cout << endl;
			
			serachInfo = "All persons registered";
			
			showSearchInfo(serachInfo, cont);

			menuPause();
		}else if(command_idx == 5 /*exit*/){
			cout << "Exiting..." << endl;
			break;
		}
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

	for(uint i = 0; i < prefix.size(); i++){
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
	table.addRow(vector<string> {p->getNationalID(), p->getGivenName(), p->getSurname(), p->getBirthDayString(), p->getCity()});

	//Adicionando valores duplicados
	if(node->dupes != nullptr){
		for(Node<T>* dupe : (*node->dupes)){
			Person* pd = dupe->toPerson;
			table.addRow(vector<string> {pd->getNationalID(), pd->getGivenName(), pd->getSurname(), pd->getBirthDayString(), pd->getCity()});
		}
	}
}

template<typename T>
uint showNodeWhitTable(Node<T>* node){
	//Caso vetor null ou vazio
	if(node == nullptr){
		showNullNode();
		return 0;
	}

	//Cria uma tabela
	GTable table(1);
	//Cabeçalho
	table.addRow(vector<string> {"National ID", "Given Name", "Surname", "Birthday", "City"});

	//Adiciona nó na tabela
	addNodeOnTable(node, table);

	table.show();

	//-1 pois desconsidera o cabeçalho
	return table.getRowSize()-1;
}

template<typename T>
uint showVecNodeWhitTable(vector<Node<T>*>* vec){
	//Caso vetor null ou vazio
	if(vec == nullptr || vec->size() == 0){
		showNullNode();
		return 0;
	}

	//Cria um tabela
	GTable table(1);

	//Cabeçalho
	table.addRow(vector<string> {"National ID", "Given Name", "Surname", "Birthday", "City"});

	//Adiciona todos os nós
	for(Node<T>* node : (*vec)){
		addNodeOnTable(node, table);
	}

	table.show();

	//-1 pois desconsidera o cabeçalho
	return table.getRowSize()-1;
}

void showNullNode(){
	GTable table(1);

	const string text = "nenhum valor encontrado";
	table.addRow(vector<string> {text});

	table.show();
}

// ------- { Funções Main Interativa } ---------

string getLineFtsString(){
	stringstream ss; //Stream de strings
	string line;     //Linha lida do terminal
	string ret;      //String de retorno

	getline(cin, line);

	ss << line;
	ss >> ret;

	return ret;
}

bool stringToIntMax(string str, uint& ref, const uint max){	
	try{
		//tentar converter
		ref = stoi(str);
		//conversão bem sucedida
		if(ref > 0 && ref <= max){
			return true;
		//valor fora do limite
		}else{
			throw invalid_argument("Opção fora de alcance");
			return false;
		}
	}catch(exception excp){
		//Valor de string inválido
		return false;
	}
}

llint idStringToLLINT(string str){
	return stoll(getStringWithout(str, "-."));
}

void menuPause(){
	cout << " (Press ENTER) >>> ";
	cin.get();
}

void showSearchInfo(const string& str, uint cont){
	GTable table(1);
	string matchesInfo = "Number of Matches: " + to_string(cont);
	table.addRow(vector<string>{str, matchesInfo});
	table.show();
	cout << endl;
}