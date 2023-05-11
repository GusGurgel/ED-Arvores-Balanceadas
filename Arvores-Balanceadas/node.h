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

template <typename T> struct Node {
  // atributos
  T key;
  int height;
  Node<T> *left;
  Node<T> *right;

  // Construtor
  Node(T key, Node *left = nullptr, Node *right = nullptr, int height = 1)
      : key(key), height(height), left(left), right(right) {}
};

#endif