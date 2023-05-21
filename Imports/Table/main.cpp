#include <iostream>
#include <fstream>
#include <fstream>

#include "gtable.h"
#include "sstream"
#include "person.h"

using namespace std;

vector<Person*>* readFromFile(string);

string toStringBrith(GDate date){
    stringstream ss;
    ss << date;
    return ss.str();
}

int main()
{
    vector<Person*>* person;
    GTable table(1);

    person = readFromFile("data(reduzida).csv");

    table.addRow(vector<string> {"CPF", "Primeiro Nome", "Segundo Nome", "Aniversário", "Cidade Natal"});

    for(Person* p : *(person)){
        table.addRow(vector<string> {p->getNationalID(), p->getGivenName(), p->getSurname(), toStringBrith(p->getBirthDay()), p->getCity()});
        // cout << *(p) << endl;
        delete p;
    }

    table.show();

    return 0;
}

// int main(){
//     GTable tabela(20);

//     tabela.addRow(vector<string> {"Animal", "Tamanho", "Idade"});
//     tabela.addRow(vector<string> {"Morcego", "Pequeno"});
//     tabela.addRow(vector<string> {"Cavalo", "Grande"});
//     tabela.addRow(vector<string> {"Formiga", "Minúscula"});
//     tabela.addRow(vector<string> {"Gustavo", "Foda"});

//     tabela.show();
// }

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