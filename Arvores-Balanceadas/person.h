/**************************************************
//
// Projeto 1 - Estrutura de Dados Avançada UFC
//
// Person Class (Header file)
//
// Criação:     11 Mai 2023
// Atualização: 11 Mai 2023
//
// Criado Por:
// Nome: Gustavo Gurgel Medeiros
// Número de Matrícula [UFC]: 539226
//
************************************************/

#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>   //palavras
#include <regex>    //expressões regulares
#include <iomanip>  //manipulação de entrada e saida
#include <iostream> //operações de entrada e saida
#include "gdate.h"  //datas

using std::string;

string getStringWithout(const string&, const string&);

// ----------{ makeLine }----------
// > Método privado que desenha uma 
// > linha no terminal.
// >
// > length = "comprimento da linha"
// ---------------------------------
void makeLine(uint length = 30);

class Person{
public:
    // ---{ Construtor Padrão }---
    Person() = default;

    // ------{ Construtor Por String }------
	// > Constroi uma pessoa a partir de uma
	// > string.
	// >
    // > str = "string no formato esperado"
	// > 
	// > !Valida os valores passados!
    // -------------------------------------
    Person(string);

    // -----------{ setPerson }-------------
	// > Define os atributos de uma pessoa a
	// > partir de um string.
	// >
    // > str = "string no formato esperado"
	// > 
	// > !Valida os valores passados!
    // -------------------------------------
    void setPerson(string);

    // -------------{ show }-------------
	// > Mostra uma pessoa de uma maneira
    // > mais legível
    // ----------------------------------
    void show() const;

    // --------{ &operator<< }----------
	// > Overload do operador (<<)
    // ---------------------------------
	friend ostream &operator<<(ostream &, const Person &);

    // -------{ Gets e Sets }-------
    llint getNumNationalID() const;
    string getNationalID() const;
    string getGivenName() const;
    string getSurname() const;
    GDate getBirthDay() const;
    string getCity() const;

private:
    // ---{ Atributos Privados }---
    string nationalID;
    string givenName;
    string surname;
    GDate birthday;
    string city;

    // ----------------{ regexPerson  }----------------
	// > Expressão regular que representa uma data no 
    // > seguinte formato:
	// > 
	// > "NationalID,GivenName,Surname,Birthday,City"
    // ------------------------------------------------
    const static std::regex regexPerson;
};

#endif
