//
// Created by den on 11.04.17.
//

#ifndef NewMap_MAPA_HPP
#define NewMap_MAPA_HPP

#include <iostream>
#include <cstring>

template<typename T, typename U>
class Map {
private:
    T key;
    U data;
    Map *right;
    Map *left;
    Map *parent;

    Map<T, U> *create_node(T key_, U data_);

    Map<T, U> *get_node_by_value(T key_) const;

    Map *find_max_node(Map<T, U> *target);

    void remove();

public:

    void delete_node(T key_);

    Map<T, U>();

    Map<T, U>(T key_, U data_);

    Map<T, U>(Map &target);

    ~Map<T, U>();

    void insert(T key_, U data_);

    void show(T key_) const;

    Map &operator=(Map &elem);

    U operator[](T key_);
};

template<typename T, typename U>
Map<T, U>::Map():
        key(NULL),
        data(NULL),
        right(NULL),
        left(NULL),
        parent(NULL) {
    std::cout << "CTR\n";
}

template<typename T, typename U>
Map<T, U>::Map(T key_, U data_):
        key(key_),
        data(data_),
        right(NULL),
        left(NULL),
        parent(nullptr) {
    std::cout << "Create new node with data = " << data << std::endl;
}

template<typename T, typename U>
Map<T, U>::Map(Map &target) {
    std::cout << "ctr_cp";
    key = target.key;
    data = target.data;
    right = target.right;
    left = target.left;
    parent = target.parent;
}

template<typename T, typename U>
Map<T, U>::~Map() {
    std::cout << "DESTR\n";

    try {
        if (right)
            delete right;
        if (left)
            delete left;
    } catch (std::exception) {
        std::cout << "Op, null el";
    }
}

template<typename T, typename U>
void Map<T, U>::insert(T key_, U data_) {
    if (key_ == key) {
        std::cout << key_ << " уже присутствует в дереве\n";
    } else if (key < key_) {
        if (right) {
            right->insert(key_, data_);
        } else {
            right = create_node(key_, data_);
        }
    } else {
        if (left) {
            left->insert(key_, data_);
        } else {
            left = create_node(key_, data_);
        }
    }
}

template<typename T, typename U>
Map<T, U> *Map<T, U>::create_node(T key_, U data_) {
    Map<T, U> *NewNode = new Map<T, U>(key_, data_);
    NewNode->parent = this;
    return NewNode;
}

template<typename T, typename U>
Map<T, U> &Map<T, U>::operator=(Map &elem) {
    std::cout << "op\n";
    delete right;
    delete left;
    try {
        if (this != &elem) {
            key = elem.key;
            data = elem.data;
            right = new Map<T, U>;
            right = elem.right;
            left = new Map<T, U>;
            left = elem.left;
            parent = elem.parent;
        }
    } catch (std::exception) {
        std::cout << "Бессмысленно присваивать самого себя\n";
    }
}

template<typename T, typename U>
void Map<T, U>::show(T key_) const {
    if (get_node_by_value(key_))
        std::cout << get_node_by_value(key_)->data << std::endl;
}

template<typename T, typename U>
Map<T, U> *Map<T, U>::get_node_by_value(T key_) const {
    if (this) {
        if (key > key_ && left) {
            return left->get_node_by_value(key_);
        } else if (key < key_ && right) {
            return right->get_node_by_value(key_);
        } else if (key == key_) {
            return (Map<T, U> *) this;
        } else if (key_) {
            std::cout << "Элемента Map[" << key_ << "] не существует\n";
            return NULL;
        }
    }
}

template<typename T, typename U>
void Map<T, U>::delete_node(T key_) {
    Map<T, U> *target = get_node_by_value(key_);
    if (target) {
        target->remove();
    }
    delete target;
}

template<typename T, typename U>
void Map<T, U>::remove() {
    if (!parent) {
        std::cout << "Нельзя удалить root элемент!\n";
    }
    if (left && right) {
        Map<T, U> *localMax = find_max_node(left);
        localMax->remove();
    } else if (left) {
        if (this == parent->left) {
            parent->left = left;
        } else {
            parent->right = left;
        }
    } else if (right) {
        if (this == parent->right) {
            parent->right = right;
        } else {
            parent->left = right;
        }
    } else {
        if (this == parent->left) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
    }
}

template<typename T, typename U>
Map<T, U> *Map<T, U>::find_max_node(Map<T, U> *target) {
    while (target->right) {
        target = target->right;
    }
    return target;
}

template<typename T, typename U>
U Map<T, U>::operator[](T key_) {
    return get_node_by_value(key_)->data;
}


#endif //NewMap_MAPA_HPP
