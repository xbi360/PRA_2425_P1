#include "List.h"
#include <ostream>
template <typename T>
class Node {
	public: 
		T data;
		Node<T> * next;
		Node();
		~Node();
		friend std::ostream& operator<<(std::ostream &out, const Node<T> &node); 
};
