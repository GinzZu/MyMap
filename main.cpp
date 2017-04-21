#include <iostream>
#include <cstring>
#include "MAPA.hpp"
#include "String.hpp"

int main() {


    Map<int, int> tree(10, 2);
    Map<int, int> bush(13, 3);
    bush = tree;
    bush.show(10);

    std::cout << tree[10] << std::endl;

    tree.insert(8, 5);
    tree.insert(12, 6);

    bush.insert(8, 4);

    tree.delete_node(12);
    tree.show(12);
    bush.show(8);

    return 0;
}