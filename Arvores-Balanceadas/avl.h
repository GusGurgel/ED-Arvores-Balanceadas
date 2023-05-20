/**************************************************
//
// Projeto 1 - Estrutura de Dados Avançada UFC
//
// AVL tree (Header file)
//
// Criação:     08 Mai 2023
// Atualização: 19 Mai 2023
//
// Criado Por:
// Nome: Atílio Gomes Luiz
//
// Arquivo Adaptado por:
// Gustavo Gurgel Medeiros
// Número de Matrícula [UFC]: 539226
************************************************/

#ifndef _AVL_H_
#define _AVL_H_
#include "node.h"
#include "gdate.h"
#include "person.h"
#include <string> //palavras
#include <vector> //retorna com múltiplos nós
#include <stack>  //funções interativas

// template <typename T>
// int defaultCompare(T, T);

template <typename T> 
class avl_tree {
public:

  // ---{Construtor Padrão}---
  avl_tree() = default;
  
  // --------------{add}----------------
  // > Chamada recursiva do método pri-
  // > vado recursivo add.
  // >
  // > key = "chave a adicionar"
  // > per = "pessoa ligada a chave"
  // -----------------------------------
  void add(T key, Person* per = nullptr);
  void bshow() const;

  // /---------{clear}-----------
  // > chamada do método recursi-
  // > vo privado que limpa a
  // > árvore
  // ----------------------------
  void clear();

  // -----{~avl_tree}------
  // > destrutor de classe
  // -----------------------
  ~avl_tree();

  // Se não for usadas, remover essas
  // declarações
  // avl_tree(const avl_tree& t) = delete;
  // avl_tree& operator=(const avl_tree& t) = delete;
	
  // ----------{clear}------------
  // > Método público que printa 
  // > a árvora em ordem.
  // >
  // > node = "raiz da árvore" 
  // -----------------------------
  void inorderPrint();

  // -----------{searchKey}-----------
  // > Método públic que pocura um nó 
  // > com uma chave específica. 
  // >
  // > key = "chave a procurar" 
  // ---------------------------------
  Node<T>* searchNodeByKey(T key);

  // -----------{searchNodeByInterval}-----------
  // > Método públic que pocura os nós que estão 
  // > no intervalo entre keyMin e keyMax. Retorna 
  // > os ponteiros dos nós em um vector
  // >
  // > keyMin = "chave mínima"
  // > keyMax = "chave máxima" 
  // --------------------------------------------
  std::vector<Node<T>*> searchNodeByInterval(T keyMin, T keyMax);

   // -----------{searchNodeByPrefix}-----------
  // > Método públic que pocura os nós que estão 
  // > que tem um prefíxo específico. Como essa
  // > função não é possível implementar apenas
  // > com os comparadores padrões. É necessário
  // > passar uma função que compara dois valores
  // > do tipo T e diz se eles são prefíxos.
  // >
  // > prefix = "prefíxo procurado"
  // > keyMax = "função que diz se é prefíxo" 
  // --------------------------------------------
  std::vector<Node<T>*> searchNodeByPrefix(T prefix, bool (*isPrefix) (T, T));
	
private:

  Node<T> *root{nullptr};

  // ---------{heigth}---------
  // > retorna a alura do nó.
  // > se é vazio, então a
  // > altura é zero.
  // -------------------------
  int height(Node<T> *node);

  // --------{balance}----------
  // > retorna o balanço do nó
  // > baseado nas alturas direta
  // > e esquerda.
  // ----------------------------
  int balance(Node<T> *node);

  // -------{rightRotation}---------
  // > efetura rotação a direita no
  // > nó p.
  // --------------------------------
  Node<T> *rightRotation(Node<T> *p);
  
  // ---------{leftRotation}---------
  // > efetua rotação a esquerda no
  // > nó p.
  // --------------------------------
  Node<T> *leftRotation(Node<T> *p);
  
  // --------------{add}----------------
  // > método que recebe uma chave (key)
  // > e adiciona (de forma recursiva)
  // > na árvore.
  // >
  // > p   = "raiz da árvore"
  // > key = "chave a adicionar"
  // > per = "pessoa ligada a chave"
  // -----------------------------------
  Node<T> *add(Node<T> *p, T key, Person* per = nullptr);


  // ---------{fixup_node}-----------
  // > Calcula altura e balanço e re-
  // > solve problemas de balancea-
  // > mento do nó p.
  // > 
  // > p = "nó a consertar"
  // > key = "chave a adicionar"
  // ---------------------------------
  Node<T> *fixup_node(Node<T> *p, T key);

  void bshow(Node<T> *node, std::string heranca) const;

  // ---------{clear}-----------
  // > método recursivo que limpa
  // > a árvore.
  // >
  // > node = "raiz da árvore" 
  // ----------------------------
  Node<T> *clear(Node<T> *node);
  
  // -------{inorderPrint}--------
  // > Método privado recursivo que 
  // > printa a árvora em ordem.
  // >
  // > node = "raiz da árvore" 
  // -----------------------------
  void inorderPrint(Node<T>* node);
};

#endif
