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
    ListLinked(); // Constructor
    ~ListLinked(); // Destructor
    T operator[](int pos); // Acceso a elementos
    friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list); // Sobrecarga de operador <<
    void insert(int pos, T e) override; // Insertar elemento
    void append(T e) override; // Añadir elemento al final
    void prepend(T e) override; // Añadir elemento al principio
    T remove(int pos) override; // Eliminar elemento
    T get(int pos) override; // Obtener elemento
    int search(T e) override; // Buscar elemento
    bool empty() override; // Verificar si está vacía
    int size() override; // Obtener el tamaño
};

#endif // LISTLINKED_H

