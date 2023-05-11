/**************************************************
//
// Projeto 1 - Estrutura de Dados Avançada UFC
//
// GDate (Header file)
//
// Criação:     09 Mai 2023
// Atualização: 09 Mai 2023
//
// Criado Por:
// Gustavo Gurgel Medeiros
// Número de Matrícula [UFC]: 539226
************************************************/

#ifndef _GDATE_
#define _GDATE_
#include "gtypes.h"
#include <iomanip>  //manipulação de entrada e saida
#include <iostream> //operações de entrada e saida
#include <regex>    //expressões regulares
#include <stdexcept>//exceções

using std::ostream;

class GDate {
public:
	// --- Atributos Públicos Státicos---
	static std::regex regexDate; //Expressão regular de data

	// --- Construtores ---
	//{Construtor Padrão}
	GDate() = default;
	//{Construtor por passagem de string}
	GDate(std::string);

	// --- Métodos Públicos---
	void setDate(std::string);

	// --- Métodos Públicos Státicos---
	static int compareDate(const GDate&, const GDate&);

	// ---- Overloading de operadores ----
	friend ostream &operator<<(ostream &, const GDate &);

private : 
	uint day{0};  // Dia
	uint month{0};// Mês
	uint year{0}; // Ano
};

#endif
