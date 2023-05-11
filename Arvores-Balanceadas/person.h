#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>   //palavras
#include <regex>    //expressões regulares
#include <iomanip>  //manipulação de entrada e saida
#include <iostream> //operações de entrada e saida
#include "gdate.h"  //datas

using std::string;

void makeLine(uint = 30);

class Person{
public:
    // --- Atributos Públicos Státicos ---

    // --- Construtores ---
    // construtor padrão
    Person() = default;

    // por passagem de string (utiliza regex)
    Person(string);

    // --- Métodos Públicos ---
    void setPerson(string);
    void show() const;

    // ---- Overloading de operadores ----
	friend ostream &operator<<(ostream &, const Person &);

    // --- Gets e Sets ----
    string getNotionalID() const;
    string getGivenName() const;
    string getSurname() const;
    GDate getBirthDay() const;
    string getCity() const;

private:
    string nationalID;
    string givenName;
    string surname;
    GDate birthday;
    string city;

    const static std::regex regexPerson;
};

#endif
