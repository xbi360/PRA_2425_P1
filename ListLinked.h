// ListLinked.h
#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first; // Puntero al primer nodo
    int n; // Número de elementos en la lista

public:
    ListLinked():first(nullptr), n(0) {}
    // Constructor
	

    T operator[](int pos){
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
    //Metodo para obtener el primer nodo
    Node <T>* get_first()const{
	    return first;
    }

    void remove_first(){
	    if(first!=nullptr){
		    Node<T> *temp = first;
		    first=first->next;
		    delete temp;
	    }
   }


    friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list){
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

    void insert(int pos, T e) override{
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

    void append(T e) override{
        insert(n, e);
    }

    void prepend(T e) override{
        insert(0, e); // Insertar al principio
    }

    T remove(int pos) override{
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

    T get(int pos) override{
         if (pos < 0 || pos >= n) {
        throw std::out_of_range("introduce una posicion valida");
    }
    Node<T>* current = first;
    for (int i = 0; i < pos; ++i) {
        current = current->next;
    }
    return current->data;
    }

    int search(T e) override{
         Node<T>* current = first;
    for (int i = 0; current != nullptr; i++) {
        if (current->data == e) {
            return i; // Retorna la posición
        }
        current = current->next;
    }
    return -1; // No encontrado
    }
    bool empty() override{
           return n == 0; // Retorna true si la lista está vacía
    }
    int size() override{
          return n; // Retorna el tamaño de la lista
    }
     ~ListLinked(){}// Destructor
};

#endif // LISTLINKED_H

