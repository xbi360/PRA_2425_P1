#ifndef NODE_H
#define NODE_H

#include <ostream>

template <typename T>
class Node {
public: 
    T data;          
    Node<T>* next;        
    Node(T d, Node<T>* nextNode = nullptr) : data(d), next(nextNode) {}

    // Destructor (no necesita hacer nada en este caso)
    ~Node() {}

    // Sobrecarga del operador de salida para imprimir el nodo
    friend std::ostream& operator<<(std::ostream& out, const Node<T>& node) {
        out << node.data;
        return out; 
    }
};

#endif
