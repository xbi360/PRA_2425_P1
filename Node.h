#include "List.h"
#include <ostream>
template <typename T>
class Node {
	public: 
		T data;
		Node<T> * next;
		Node(T d, Node<T> *next=nullptr);
		~Node();
		friend std::ostream& operator<<(std::ostream &out, const Node<T> &node); 
};
