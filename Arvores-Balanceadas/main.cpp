#include <iostream>
#include "avl.h"
using namespace std;

int main() {
    avl_tree<int> *t = new avl_tree<int>();

    for(int i = 1; i <= 50; i++) {
        t->add(i);
    }

    t->bshow();
}