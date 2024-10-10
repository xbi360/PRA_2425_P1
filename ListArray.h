#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <iostream>
#include <stdexcept> // Para std::out_of_range
#include "List.h"

template <typename T>
class ListArray : public List<T> {
private:
    T *arr;
    int max;
    int n;
    static const int MINSIZE;

    void resize(int new_size) {
        T *new_arr = new T[new_size];
        for (int i = 0; i < n; ++i) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        max = new_size;
    }

public:
    ListArray() : max(MINSIZE), n(0) {
        arr = new T[max]; // Reserva memoria para el arreglo
    }

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Introduce una posicion valida");
        }
        if (n >= max) {
            resize(max * 2); // Doblamos la capacidad de la lista
        }
        for (int i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = e;
        n++;
    }

    void append(T e) override {
        if (n >= max) { // Cambiado a '>=', para añadir correctamente el último elemento
            resize(max * 2);
        }
        arr[n] = e;
        n++;
    }

    void prepend(T e) override {
        insert(0, e);
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Introduce una posicion valida");
        }
        T Elemento_e = arr[pos];
        for (int i = pos; i < n - 1; i++) { // Desplazamos los elementos
            arr[i] = arr[i + 1];
        }
        n--;
        return Elemento_e;
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Introduce una posicion valida");
        }
        return arr[pos];
    }

    int search(T e) override {
        for (int i = 0; i < n; i++) {
            if (arr[i] == e) {
                return i;
            }
        }
        return -1; // Retorna -1 si no se encuentra
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }

    T operator[](int pos) {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Introduce una posicion valida");
        }
        return arr[pos];
    }

    friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
        out << "[";
        for (int i = 0; i < list.n; ++i) {
            out << list.arr[i];
            if (i < list.n - 1) {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }

    ~ListArray() {
        delete[] arr;
    }
};

template <typename T>
const int ListArray<T>::MINSIZE = 2;

#endif
