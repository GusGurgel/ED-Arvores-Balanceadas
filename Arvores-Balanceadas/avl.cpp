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


//------------------------------------
//   { Destrutores e Construtores }
//------------------------------------

template <typename T> avl_tree<T>::~avl_tree() { 
  clear(); 
}

//----------------------------
//   { Métodos Públicos }
//----------------------------

template <typename T> void avl_tree<T>::add(T key, Person* per) {
  //std::cout << "Adicionando: " << key << " pessoa: " << (*per);
  root = add(root, key, per); 
}

template <typename T> void avl_tree<T>::bshow() const { 
  bshow(root, ""); 
}

template <typename T> void avl_tree<T>::clear() { 
  root = clear(root); 
}

template <typename T>
void avl_tree<T>::inorderPrint(){
	inorderPrint(this->root);
}

template <typename T>
Node<T>* avl_tree<T>::searchNodeByKey(T key){
	Node<T>* current = this->root;
	
	while(current != nullptr && key != current->key){
		if(key > current->key){
			current = current->right;
		}else if(key < current->key){
			current = current->left;
		}
	}
	return current;
}

template <typename T>
std::vector<Node<T>*> avl_tree<T>::searchNodeByInterval(T keyMin, T keyMax){

  std::vector<Node<T>*> ret;
  std::stack<Node<T>*> st;

  st.push(root);

  if(keyMin > keyMax){
    return ret; 
  }

  while(!st.empty()){
    Node<T>* current = st.top();
    st.pop();

    if(current != nullptr){
      //maior que o máximo (só pode estar na esquerda)
      if(current->key > keyMax){
        st.push(current->left);
      //menor que o mínimo (só pode estar na direita)
      }else if(current->key < keyMin){
        st.push(current->right);
      }else{
        //exatamente igual ao máximo
        if(current->key == keyMax){
          ret.push_back(current);
          st.push(current->left);
        //exatamente igual ao mínimo
        }else if(current->key == keyMin){
          ret.push_back(current);
          st.push(current->right);
        //entre o mínimo e o máximo
        }else{
          ret.push_back(current);
          st.push(current->right);
          st.push(current->left);
        }
      }
    }
  }

  return ret;
}

template <typename T>
std::vector<Node<T>*> avl_tree<T>::searchNodeByPrefix(T prefix, bool (*isPrefix) (const T&, const T&)){
  std::vector<Node<T>*> ret;
  std::stack<Node<T>*> st;

  st.push(root);

  while(!st.empty()){
    Node<T>* current = st.top();
    st.pop();

    if(current != nullptr){
      //maior que o máximo (só pode estar na esquerda)
      if(isPrefix(prefix, current->key)){
        ret.push_back(current);
        st.push(current->left);
        st.push(current->right);
      }else if(current->key > prefix){
        if(isPrefix(prefix, current->key)){
          ret.push_back(current);
        }
        st.push(current->left);
      }else if(current->key < prefix){
        if(isPrefix(prefix, current->key)){
          ret.push_back(current);
        }
        st.push(current->right);
      }
    }
  }

  return ret;
}

//----------------------------
//   { Métodos Privados }
//----------------------------

template <typename T>
void avl_tree<T>::inorderPrint(Node<T>* node){
	if(node == nullptr){
		return;	
	}
	inorderPrint(node->left);
	std::cout << node->key << std::endl;
	inorderPrint(node->right);
}

template <typename T> int avl_tree<T>::height(Node<T> *node) {
  return (node == nullptr) ? 0 : node->height;
}

template <typename T> int avl_tree<T>::balance(Node<T> *node) {
  return height(node->right) - height(node->left);
}

template <typename T> Node<T> *avl_tree<T>::rightRotation(Node<T> *p) {
  Node<T> *u = p->left;
  p->left = u->right;
  u->right = p;
  // recalcular as alturas de p e de u
  p->height = 1 + max(height(p->left), height(p->right));
  u->height = 1 + max(height(u->left), height(u->right));
  return u;
}

template <typename T> Node<T> *avl_tree<T>::leftRotation(Node<T> *p) {
  Node<T> *u = p->right;
  p->right = u->left;
  u->left = p;
  // recalcular as alturas de p e de u
  p->height = 1 + max(height(p->right), height(p->left));
  u->height = 1 + max(height(u->left), height(u->right));
  return u;
}

template <typename T> Node<T> *avl_tree<T>::add(Node<T> *p, T key, Person* per) {
	if (p == nullptr){
    std::cout << "nome: " << key << "pessoa: " << per << std::endl;
		return new Node<T>(key, per);
	}
	if (key == p->key){
    std::cout << "penis" << std::endl;
		p->addDupe(new Node<T>(key, per));
		return p;
	}
	if (key < p->key){
		p->left = add(p->left, key, per);
	}
	else{
		p->right = add(p->right, key, per);
	}

	p = fixup_node(p, key);

	return p;
}

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

template <typename T> Node<T> *avl_tree<T>::clear(Node<T> *node) {
  if (node != nullptr) {
    node->left = clear(node->left);
    node->right = clear(node->right);
    delete node;
  }
  return nullptr;
}

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
  std::cout << node->toString() << std::endl;
  if (node != nullptr && (node->left != nullptr || node->right != nullptr))
    bshow(node->left, heranca + "l");
}

// ----------------------------
// Instanciação dos templates
// que vão ser usados pelo pro-
// grama principal.
// ----------------------------
template class avl_tree<llint>;
template class avl_tree<string>;
template class avl_tree<GDate>;

//temporário
template class avl_tree<int>;
