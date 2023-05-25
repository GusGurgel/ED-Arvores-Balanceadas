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

#ifndef _GDATE_H_
#define _GDATE_H_

#include <iomanip>  //manipulação de entrada e saida
#include <iostream> //operações de entrada e saida
#include <regex>    //expressões regulares
#include <stdexcept>//exceções
#include <sstream>  //método toString

using std::ostream;

// -----{ Typedefs }-----
typedef unsigned int uint;
typedef long long int llint;

class GDate {
public:
	// ---{ Construtor Padrão }---
	GDate() = default;

	// ------{ Construtor Por String }------
	// > Constroi uma data a partir de uma
	// > string.
	// >
    // > str = "string no formato esperado"
	// > 
	// > !Valida os valores passados!
    // -------------------------------------
	GDate(std::string str);

	// ------------{ setDate }--------------
	// > Define os atributos da data a
	// > partir de um string.
	// >
    // > str = "string no formato esperado"
	// > 
	// > !Valida os valores passados!
    // -------------------------------------
	void setDate(std::string);

	// ----------{ compareDate }------------
	// > Compara duas datas retornando 0 sé
	// > as duas são iguas, 1 se a primeira
	// > é maior que a segunda e (-1) se a
	// > primeira é menor que a segunda.
	// > 
	// > 
    // > date1 = "primeira data"
	// > data2 = "segunda data"
    // -------------------------------------
	static int compareDate(const GDate& date1, const GDate& date2);

	// --------{ &operator<< }----------
	// > Overload do operador (<<)
    // ---------------------------------
	friend ostream &operator<<(ostream &, const GDate &);

	// --------{ toString() }----------
	// > Retorna a data em string
    // ---------------------------------
	std::string toString() const;

	// --------{ &operator<< }----------
	// > Overload dos operadores de
	// > comparação entre datas.
	// > 
	// > usa a função stática publica 
	// > compareDate da classe GDate 
    // ---------------------------------
    bool operator==(const GDate&) const;
    bool operator!=(const GDate&) const;
	bool operator<(const GDate&) const;
	bool operator>(const GDate&) const;
	bool operator<=(const GDate&) const;
	bool operator>=(const GDate&) const;

private : 
	// ---{ Atributos Privados }---
	uint day{0};  // Dia
	uint month{0};// Mês
	uint year{0}; // Ano
	
	// --------{ regexDate }----------
	// > Expressão regular que re-
	// > presenta uma data no seguin-
	// > te formato:
	// > 
	// > MM/DD/YYYY
    // -------------------------------
	const static std::regex regexDate; 
};

#endif
