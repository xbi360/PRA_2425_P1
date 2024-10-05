#include "ListArray.h"


template <typename T>
const int ListArray<T>::MINSIZE = 2; // Inicialización de MINSIZE


//constructor
template <typename T>
ListArray<T>::ListArray() : max(MINSIZE), n(0) {
	arr = new T[max]; // Reserva memoria para el arreglo
	
}
template <typename T>
ListArray<T>::~ListArray(){
	delete [] arr;//libera la memoria ocupada
}

//sobrecarga de []
template <typename T>
T ListArray<T>::operator[](int pos){
	if(pos <0 || pos >=n){
		throw std::out_of_range("Introduce una posicion valida");
	}
	return arr[pos];
}
//redimensionar el array
template <typename T>
void ListArray<T>::resize(int new_size) {
	T *new_arr = new T[new_size]; 
    		for (int i = 0; i < n; ++i) {
        		new_arr[i] = arr[i]; 
   	 	}
    	delete[] arr;
    	arr = new_arr;
    	max = new_size; 
}
//sobrecarga de <<
template <typename T>
std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
	out<<"[";
	for (int i=0;i<list.n;i++){
		out<<list.arr[i];
		if(i<list.a-1){
			out<<",";
		}
	}
	out<<"]";
	return out;
}
//verificar si la lista está vacía
template <typename T>
bool ListArray<T>::empty(){
	return n==0;
}
//obtener el numero de elementos de la lista
template <typename T>
int ListArray<T>::size(){
	return n;
}
//devuelve la posicion del elemento buscado
template <typename T>
int ListArray<T>::search(T e){
	int i=0;
	while(i<n && arr[i]!=e){
		i++;
	}
	if (arr[i]==e){
		return i;
	}

	return -1;
}
template <typename T>
T ListArray<T>::get(int pos){
	if(pos<0 || pos>=n){
		std::out_of_range("Introduce una posicion valida \n");
	}
	return arr[pos];
}
//elimina el elemento situado en la posicion pos y lo devuelve
template <typename T>
T ListArray<T>::remove(int pos){
	if(pos<0 || pos>=n){
		std::out_of_range("Introduce una posicion valida \n");
	}
	T Elemento_e =arr[pos];
	for(int i=pos;i<n-1;i++){//desplazamos los elementos que estan a la derecha del elemento a eliminar 
		arr[i]=arr[i+1];
	}
	n--; //decrementamos el numero de elementos
	return Elemento_e;
}
//inserta elemento a la lista
template <typename T>
void ListArray<T>::insert(int pos,T e){
	if(pos<0 || pos>n){
		std::out_of_range("Introduce una posicion valida \n");
	}
	//comprobamos que hay espacio para añadir el elemento, y si no pues lo redimensionamos 
	if(n>=max){
		resize(max*2);//doblamos la capacidad de la lista 
	}
	
	for(int i=n;i>pos;i--){
		arr[i]=arr[i-1];
	}
	arr[pos]=e;
	n++;

}
//insertar al inicio de la lista
template <typename T>
void ListArray<T>::prepend(T e){
	if(n>=max){
		resize(max*2);
	}
	insert(0,e);
}
//insertar al final de la lista 
template <typename T>
void ListArray<T>::append(T e){
	if (n>max){
		resize(max*2);
	}
	arr[n]=e;
	n++;
}


