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

#ifndef _AVL_H_
#define _AVL_H_
#include "node.h"
#include "gdate.h"
#include <string>

// template <typename T>
// int defaultCompare(T, T);

template <typename T> class avl_tree {
public:

  // ---{Construtor Padrão}---
  avl_tree() = default;
  
  // --------------{add}----------------
  // > Chamada recursiva do método pri-
  // > vado recursivo add.
  // >
  // > key = "chave a adicionar"
  // -----------------------------------
  void add(T key);
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
  // > p = "raiz da árvore"
  // > key = "chave a adicionar"
  // -----------------------------------
  Node<T> *add(Node<T> *p, T key);


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
  
  // ---------{clear}-----------
  // > Método privado recursivo
  // > que printa a árvora em 
  // > ordem.
  // >
  // > node = "raiz da árvore" 
  // ----------------------------
  void inorderPrint(Node<T>* node);
};

#endif
