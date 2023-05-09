#include <iostream>
#include "node.h"
#include "avl.h"
using namespace std;

// retorna a altura do nó.
// se a arvore for vazia ela tem altura 0
// caso contrario, retorna o valor que está no campo height
template <typename T>
int avl_tree<T>::height(Node<T> *node) {
    return (node == nullptr) ? 0 : node->height;
}

template <typename T>
int avl_tree<T>::balance(Node<T> *node) {
    return height(node->right) - height(node->left);
}

template <typename T>
Node<T>* avl_tree<T>::rightRotation(Node<T> *p) {
    Node<T> *u = p->left;
    p->left = u->right;
    u->right = p;
    // recalcular as alturas de p e de u
    p->height = 1 + max(height(p->left),height(p->right));
    u->height = 1 + max(height(u->left),height(u->right));
    return u;
}

template <typename T>
Node<T>* avl_tree<T>::leftRotation(Node<T> *p) {
    Node<T> *u = p->right;
    p->right = u->left;
    u->left = p;
    // recalcular as alturas de p e de u
    p->height = 1 + max(height(p->right),height(p->left));
    u->height = 1 + max(height(u->left),height(u->right));
    return u;
}

// função pública que recebe uma chave e a insere
// somente se ela não for repetida
template <typename T>
void avl_tree<T>::add(T key) {
    root = add(root, key);
}

// função recursiva privada que recebe uma raiz de arvore
// e uma chave e insere a chave na tree se e somente se 
// ela nao for repetida. Claro, tem que deixar AVL novamente
template <typename T>
Node<T>* avl_tree<T>::add(Node<T> *p, T key) {
    if(p == nullptr)
        return new Node<T>(key);
    if(key == p->key) 
        return p;
    if(key < p->key)
        p->left = add(p->left, key);
    else 
        p->right = add(p->right, key);
    
    p = fixup_node(p, key);

    return p;
}

template <typename T>
Node<T>* avl_tree<T>::fixup_node(Node<T> *p, T key) {
    // recalcula a altura de p
    p->height = 1 + max(height(p->left),height(p->right));

    // calcula o balanço do p
    int bal = balance(p);

    if(bal >= -1 && bal <= 1) {
        return p;
    }

    if(bal < -1 && key < p->left->key) {
        p = rightRotation(p);
    }
    else if(bal < -1 && key > p->left->key) {
        p->left = leftRotation(p->left);
        p = rightRotation(p);
    }
    else if(bal > 1 && key > p->right->key) {
        p = leftRotation(p);
    }
    else if(bal > 1 && key < p->right->key) {
        p->right = rightRotation(p->right);
        p = leftRotation(p);
    }
    return p;
}

template <typename T>
void avl_tree<T>::clear() {
    root = clear(root);
}

template <typename T>
Node<T> *avl_tree<T>::clear(Node<T> *node) {
    if(node != nullptr) {
        node->left = clear(node->left);
        node->right = clear(node->right);
        delete node;
    }
    return nullptr;
}

template <typename T>
avl_tree<T>::~avl_tree() {
    clear();
}

template <typename T>
void avl_tree<T>::bshow() const {
    bshow(root, "");
}

template <typename T>
void avl_tree<T>::bshow(Node<T> *node, std::string heranca) const {
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        bshow(node->right , heranca + "r");
    for(int i = 0; i < (int) heranca.size() - 1; i++)
        std::cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");
    if(heranca != "")
        std::cout << (heranca.back() == 'r' ? "┌───" : "└───");
    if(node == nullptr){
        std::cout << "#" << std::endl;
        return;
    }
    std::cout << node->key << std::endl;
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        bshow(node->left, heranca + "l");
}



/* ---------------------- 
Intanciação dos templates 
que vão ser usados pelo
programa principal 
------------------------ */
//template class avl_tree<int>;
