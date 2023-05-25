/**************************************************
//
// Projeto 1 - Estrutura de Dados Avançada UFC
//
// AVL tree (Header file)
//
// Criação:     08 Mai 2023
// Atualização: 08 Mai 2023
//
// Criado Por:
// Nome: Atílio Gomes Luiz
//
// Arquivo Adaptado por:
// Gustavo Gurgel Medeiros
// Número de Matrícula [UFC]: 539226
************************************************/

#ifndef _NODE_H_
#define _NODE_H_

#include <vector>  //tratar nós duplicados
#include <string>  //método toString
#include <sstream> //stringstream
#include "person.h"//nó para pessoa

template <typename T> 
struct Node {
	// Atributos
	T key;
	int height;
	//Filhos direitos e esquerdo
	Node<T> *left;
	Node<T> *right;

	//Nó para pessoa
	Person* toPerson;

	//Vetor que armazena versões duplicadas
	//deste nó
	std::vector<Node<T>*>* dupes {nullptr};
	
	//Métodos
	void addDupe(Node<T>* toAdd){
		if(dupes == nullptr){
			dupes = new std::vector<Node<T>*>();
		}
		dupes->push_back(toAdd);
	}
	
	std::string toString(){
		std::stringstream ret;
		//adiciona a chave do nó
		ret << this->key;
		
		if(dupes != nullptr){
			ret << "(" << (dupes->size()+1) << "x)";
		}
		
		return ret.str();
	}
	
	// Destrutor
	~Node(){
		if(dupes != nullptr){
			for(Node<T>* node : *(dupes)){
				delete node;
			}
			dupes->clear();
			delete dupes;
		}
	}
	
	// Construtor
	Node(T key, Person* toPerson = nullptr, Node *left = nullptr, Node *right = nullptr, int height = 1)
	  : key(key), toPerson(toPerson), height(height), left(left), right(right) {}
};

#endif
