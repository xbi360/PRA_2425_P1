
#include "ListLinked.h"
#include <iostream>
#include <stdexcept> // Para manejar excepciones

template <typename T>
ListLinked<T>::ListLinked() : first(nullptr), n(0) {}

template <typename T>
ListLinked<T>::~ListLinked() {
    Node<T>* aux = first; // Puntero auxiliar que apunta al primer nodo

    while (aux != nullptr) { // Mientras haya nodos
        Node<T>* temp = aux; // Guardamos el nodo actual
        aux = aux->next; // Avanzamos al siguiente nodo
        delete temp; // Liberamos la memoria del nodo actual
    }

    first = nullptr; // Opcional: restablecemos first a nullptr
    n = 0; // Opcional: restablecemos el tamaño a 0
}

template <typename T>
T ListLinked<T>::operator[](int pos) {
    // Verificamos si la posición es válida
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Introduce una posicion valida"); // Lanzamos excepción si está fuera de rango
    }

    Node<T>* current = first; // Inicializamos un puntero para recorrer la lista

    // Recorremos la lista hasta llegar a la posición deseada
    for (int i = 0; i < pos; ++i) {
        current = current->next; // Avanzamos al siguiente nodo
    }

    return current->data; // Devolvemos el dato del nodo en la posición 'pos'
}


template <typename T>
std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
    Node<T>* current = list.first;
    out << "[";
    while (current != nullptr) {
        out << current->data;
        if (current->next != nullptr) {
            out << ", ";
        }
        current = current->next;
    }
    out << "]";
    return out;
}

template <typename T>
void ListLinked<T>::insert(int pos, T e) {
    if (pos < 0 || pos > n) {
        throw std::out_of_range("Introduce una posicion valida");
    }
    Node<T>* newNode = new Node<T>(e);
    if (pos == 0) { // Insertar al principio
        newNode->next = first;
        first = newNode;
    } else { // Insertar en otras posiciones
        Node<T>* current = first;
        for (int i = 0; i < pos - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    n++;
}

template <typename T>
void ListLinked<T>::append(T e) {
    insert(n, e); // Insertar al final
}

template <typename T>
void ListLinked<T>::prepend(T e) {
    insert(0, e); // Insertar al principio
}

template <typename T>
T ListLinked<T>::remove(int pos) {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Introduce una posicion valida");
    }
    Node<T>* toDelete;
    T data;
    if (pos == 0) { // Eliminar el primer nodo
        toDelete = first;
        first = first->next;
    } else { // Eliminar en otras posiciones
        Node<T>* current = first;
        for (int i = 0; i < pos - 1; ++i) {
            current = current->next;
        }
        toDelete = current->next;
        current->next = toDelete->next;
    }
    data = toDelete->data;
    delete toDelete;
    n--;
    return data;
}

template <typename T>
T ListLinked<T>::get(int pos) {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("introduce una posicion valida");
    }
    Node<T>* current = first;
    for (int i = 0; i < pos; ++i) {
        current = current->next;
    }
    return current->data;
}

template <typename T>
int ListLinked<T>::search(T e) {
    Node<T>* current = first;
    for (int i = 0; current != nullptr; i++) {
        if (current->data == e) {
            return i; // Retorna la posición
        }
        current = current->next;
    }
    return -1; // No encontrado
}

template <typename T>
bool ListLinked<T>::empty() {
    return n == 0; // Retorna true si la lista está vacía
}

template <typename T>
int ListLinked<T>::size() {
    return n; // Retorna el tamaño de la lista
}
