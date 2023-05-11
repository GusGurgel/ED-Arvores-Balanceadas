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
#include "gtypes.h"

#include <iostream>
using namespace std;

int main() {
	GDate d1, d2;
	string str1, str2;

	cout << "Digite a primeira data: ";
	cin >> str1;
	d1.setDate(str1);

	cout << "Digite a segunda data: ";
	cin >> str2;
	d2.setDate(str2);

	if(GDate::compareDate(d1,d2) == 0){
		cout << "as datas " << d1 << " e " << d2 << "são iguais" << endl;
	}else{
		if(GDate::compareDate(d1,d2) == 1){
			cout << "a data " << d1 << " é maior que " << d2 << endl;  
		}else{
			cout << "a data " << d1 << " é menor que " << d2 << endl;
		}
	}
	
	return 0;
}
