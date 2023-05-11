/**************************************************
//
// Projeto 1 - Estrutura de Dados Avançada UFC
//
// Person Class (Implementation file)
//
// Criação:     11 Mai 2023
// Atualização: 11 Mai 2023
//
// Criado Por:
// Nome: Gustavo Gurgel Medeiros
// Número de Matrícula [UFC]: 539226
//
************************************************/
#include "person.h"

void makeLine(uint length){
    for(uint i = 0; i < length; i++){
        std::cout << "-";
    }
    std::cout << std::endl;
}

//------------------------------------
//   { Destrutores e Construtores }
//------------------------------------

Person::Person(string str){
    this->setPerson(str);
}

//----------------------------
//   { Métodos Públicos }
//----------------------------

void Person::setPerson(string str){
    std::smatch regexMatch;

    std::regex_search(str, regexMatch, Person::regexPerson);

    if(regexMatch.empty()){
        throw std::invalid_argument("Invalid person string \"" + str + "\"");
    }else{
        this->nationalID = regexMatch.str(1);
        this->givenName  = regexMatch.str(2);
        this->surname    = regexMatch.str(3);
        this->city       = regexMatch.str(5);
        this->birthday.setDate(regexMatch.str(4));
    }
}

void Person::show() const{
    makeLine();
    std::cout << "NationalID: " << nationalID << std::endl;
    std::cout << "Full name: "  << (givenName + " " + surname) << std::endl;
    std::cout << "Birthday: "   << birthday << std::endl;
    std::cout << "City: "       << city << std::endl;
    makeLine();
}

ostream &operator<<(ostream &os, const Person &person) {
	os << "NationalID: " << person.nationalID << "; Name: " << (person.givenName + " " + person.surname) << " ; Birthday: " << person.birthday << " ; City: " << person.city << ";";
	return os;
}

//----------------------------
//   { Métodos Privados }
//----------------------------

const std::regex Person::regexPerson("(\\d{3}\\.\\d{3}.\\d{3}-\\d{2}),(.*),(.*),(\\d{1,2}\\/\\d{1,2}\\/\\d{4}),(.*)");


//----------------------------
//      { Gets e Sets }
//----------------------------

string Person::getNotionalID() const{
    return this->nationalID;
}

string Person::getGivenName() const{ 
    return this->givenName;
}

string Person::getSurname() const{
    return this->surname;
}

GDate Person::getBirthDay() const{
    return this->birthday;
}

string Person::getCity() const{
    return this->city;
}