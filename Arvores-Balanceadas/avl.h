#ifndef AVL_H
#define AVL_H
#include <string>
#include "node.h"

template <typename T>
class avl_tree {
public:
    avl_tree() = default;
    void add(T key);
    void bshow() const; 
    void clear();
    ~avl_tree();

    //Se não for usadas, remover essas
    //declarações
    //avl_tree(const avl_tree& t) = delete;
    //avl_tree& operator=(const avl_tree& t) = delete;
    
private:
    Node<T> *root {nullptr};

    int height(Node<T> *node);
    int balance(Node<T> *node);
    Node<T>* rightRotation(Node<T> *p);
    Node<T>* leftRotation(Node<T> *p);
    Node<T>* add(Node<T> *p, T key);
    Node<T>* fixup_node(Node<T> *p, T key);
    void bshow(Node<T> *node, std::string heranca) const;
    Node<T>* clear(Node<T> *node);
};

#endif