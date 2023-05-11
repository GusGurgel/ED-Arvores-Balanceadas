/**************************************************
//
// Projeto 1 - Estrutura de Dados Avançada UFC
//
// AVL tree (Implementation file)
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

#include "avl.h"
#include "node.h"
#include <iostream>
using namespace std;

/*-------{heigth}---------
 > retorna a alura do nó.
 > se é vazio, então a
 > altura é zero
------------------------*/
template <typename T> int avl_tree<T>::height(Node<T> *node) {
  return (node == nullptr) ? 0 : node->height;
}

/*--------{balance}----------
 > retorna o balanço do nó
 > baseado nas alturas direta
 > e esquerda.
 ----------------------------*/
template <typename T> int avl_tree<T>::balance(Node<T> *node) {
  return height(node->right) - height(node->left);
}

/*-------{rightRotation}---------
 > efetura rotação a direita no
 > nó p.
 --------------------------------*/
template <typename T> Node<T> *avl_tree<T>::rightRotation(Node<T> *p) {
  Node<T> *u = p->left;
  p->left = u->right;
  u->right = p;
  // recalcular as alturas de p e de u
  p->height = 1 + max(height(p->left), height(p->right));
  u->height = 1 + max(height(u->left), height(u->right));
  return u;
}

/*-------{leftRotation}---------
 > efetura rotação a esquerda no
 > nó p.
 --------------------------------*/
template <typename T> Node<T> *avl_tree<T>::leftRotation(Node<T> *p) {
  Node<T> *u = p->right;
  p->right = u->left;
  u->left = p;
  // recalcular as alturas de p e de u
  p->height = 1 + max(height(p->right), height(p->left));
  u->height = 1 + max(height(u->left), height(u->right));
  return u;
}

/*--------------{add}----------------
 > Chamada recursiva do método pri-
 > vado recursivo add.
 -----------------------------------*/
template <typename T> void avl_tree<T>::add(T key) { root = add(root, key); }

/*--------------{add}----------------
 > método que recebe uma chave (key)
 > e adiciona (de forma recursiva)
 > na árvore. Se a chave já estiver,
 > então não faz nada.
 -----------------------------------*/
template <typename T> Node<T> *avl_tree<T>::add(Node<T> *p, T key) {
  if (p == nullptr)
    return new Node<T>(key);
  if (key == p->key)
    return p;
  if (key < p->key)
    p->left = add(p->left, key);
  else
    p->right = add(p->right, key);

  p = fixup_node(p, key);

  return p;
}

/*---------{fixup_node}-----------
 > Calcula altura e balanço e re-
 > solve problemas de balancea-
 > mento do nó p.
 ---------------------------------*/
template <typename T> Node<T> *avl_tree<T>::fixup_node(Node<T> *p, T key) {
  // recalcula a altura de p
  p->height = 1 + max(height(p->left), height(p->right));

  // calcula o balanço do p
  int bal = balance(p);

  if (bal >= -1 && bal <= 1) {
    return p;
  }

  if (bal < -1 && key < p->left->key) {
    p = rightRotation(p);
  } else if (bal < -1 && key > p->left->key) {
    p->left = leftRotation(p->left);
    p = rightRotation(p);
  } else if (bal > 1 && key > p->right->key) {
    p = leftRotation(p);
  } else if (bal > 1 && key < p->right->key) {
    p->right = rightRotation(p->right);
    p = leftRotation(p);
  }
  return p;
}

/*---------{clear}-----------
 > chamada do método recursi-
 > vo privado que limpa a
 > árvore
 ----------------------------*/
template <typename T> void avl_tree<T>::clear() { root = clear(root); }

/*---------{clear}-----------
 > método recursivo que limpa
 > a árvore.
 ----------------------------*/
template <typename T> Node<T> *avl_tree<T>::clear(Node<T> *node) {
  if (node != nullptr) {
    node->left = clear(node->left);
    node->right = clear(node->right);
    delete node;
  }
  return nullptr;
}

/*-----{~avl_tree}------
 > destrutor de classe
 -----------------------*/
template <typename T> avl_tree<T>::~avl_tree() { clear(); }

template <typename T> void avl_tree<T>::bshow() const { bshow(root, ""); }

template <typename T>
void avl_tree<T>::bshow(Node<T> *node, std::string heranca) const {
  if (node != nullptr && (node->left != nullptr || node->right != nullptr))
    bshow(node->right, heranca + "r");
  for (int i = 0; i < (int)heranca.size() - 1; i++)
    std::cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");
  if (heranca != "")
    std::cout << (heranca.back() == 'r' ? "┌───" : "└───");
  if (node == nullptr) {
    std::cout << "#" << std::endl;
    return;
  }
  std::cout << node->key << std::endl;
  if (node != nullptr && (node->left != nullptr || node->right != nullptr))
    bshow(node->left, heranca + "l");
}

/* ------------------------
Instanciação dos templates
que vão ser usados pelo pro-
grama principal.
--------------------------- */
template class avl_tree<int>;