/**************************************************
//
// Projeto 1 - Estrutura de Dados Avançada UFC
//
// GDate (Implementation file)
//
// Criação:     09 Mai 2023
// Atualização: 09 Mai 2023
//
// Criado Por:
// Gustavo Gurgel Medeiros
// Número de Matrícula [UFC]: 539226
************************************************/

#include "gdate.h"


//Essa é a expressão regular referente a uma
//data no formato DD/MM/YYYY
std::regex GDate::regexDate ("(\\d{1,2})\\/(\\d{1,2})\\/(\\d{4})");

GDate::GDate(std::string str){
	setDate(str);
}

ostream &operator<<(ostream &os, const GDate &date) {
	os << std::setfill('0') << std::setw(2) << date.month << "/";
	os << std::setw(2) << date.day << "/";
	os << std::setw(4) << date.year;
	return os;
}

void GDate::setDate(std::string str){
	std::smatch rexMatch; //recebe os resulados da procura

	//procura a expressão regular na string
	std::regex_search(str, rexMatch, GDate::regexDate);

	//trata passagem de data inválida
	if(rexMatch.empty()){
		throw std::invalid_argument("Invalid date string \"" + str + "\"");
	}else{
		this->month = stoi(rexMatch.str(1)); //grupo 1 é o mês
		this->day   = stoi(rexMatch.str(2)); //grupo 2 é o dia
		this->year  = stoi(rexMatch.str(3)); //grupo 3 é o ano
	}
}

int GDate::compareDate(const GDate& date1, const GDate& date2){
	if (date1.year != date2.year) {
    	return (date1.year < date2.year) ? -1 : 1;
	} else if (date1.month != date2.month) {
		return (date1.month < date2.month) ? -1 : 1;
	} else if (date1.day != date2.day) {
		return (date1.day < date2.day) ? -1 : 1;
	} else {
		//se não passou em nenhum, então é porque
		//as datas são iguais
		return 0;
	}
}