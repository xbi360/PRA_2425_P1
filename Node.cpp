#include "Node.h" 
#include <iostream>

// Constructor que inicializa data
template <typename T>
Node<T>::Node(T d, Node<T> *nextNode){
	data=d;
	next = nextNode;
}

// Destructor
template <typename T>
Node<T>::~Node() {

}

// Sobrecarga del operador <<
template <typename T>
std::ostream& operator<<(std::ostream &out, const Node<T> &node) {
    out << node.data; // Imprime el atributo data
    return out; // Retorna el flujo para permitir encadenar
}

