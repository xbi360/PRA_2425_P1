#ifndef LISTARRAY_H
#define LISTARRAY_H
#include <ostream>
#include "List.h"


template <typename T>
class ListArray: public List <T>{
	private: 
		T *arr;//puntero al inicio del array que almacenará los elementos de la lista
		int max;//tamaño actual del array
		int n;//número de elementos del array
		static const int MINSIZE;//tamaño mínimo del array (inicializado a 2)
		void resize(int new_size);//método privado que nos ayudará a redimensionar el array
	public:
		
		void insert(int pos, T e) override;
		ListArray();//constructor 
                void append( T e) override;
                void prepend(T e) override;
                T remove(int pos) override;
                T get(int pos) override;
		int search(T e) override;
                bool empty() override;
                int size() override;
                	
		T operator [] (int pos);
		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list);
		~ListArray();//destructor 
};
#endif LISTARRAY_H
