#include "containers.h"
#include <algorithm> //TODO tmp line
#include <list> //TODO tmp line
#include <vector> //TODO tmp line
#include <map> //TODO tmp line
#include <iostream>
#include <iomanip>

template <typename vector_type>
void print_info(vector_type &v) {
    std::cout << "size = " << v.size() << std::endl;
    std::cout << "cap = " << v.capacity() << std::endl;
    std::cout << "vector: ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i].i << " ";
    std::cout << std::endl << std::endl;
} //TODO delene func


int main() {
	std::cout << "\n";
	{
		ft::map<int, int> m1;
		m1.insert(ft::pair<int, int>(15, 999));
		m1.insert(ft::pair<int, int>(20, 999));
		m1.insert(ft::pair<int, int>(25, 999));
		ft::map<int, int> m(m1.begin(), m1.end());
		ft::map<int, int>::const_iterator it = m.cbegin();
		(void) it;
		// it->second = 150;
		// std::cout << m1.begin()->second << "\n";
	}


	// {
	// 	ft::BTree<ft::pair<int, int> > tree;
	// 	tree.treeInsert(ft::pair<int, int>(10, 5));
	// 	tree.treeInsert(ft::pair<int, int>(11, 6));
	// 	ft::BTree<ft::pair<int, int> >::const_iterator it = tree.begin();
	// 	(void) it;
	// }

	std::map<int, int> m;
	m.insert(std::pair<int, int>(11, 10));
	m.insert(std::pair<int, int>(10, 10));
	m.insert(std::pair<int, int>(10, 10));
	m.insert(std::pair<int, int>(15, 10));
	m.erase(10);
	// std::map<int, int>::iterator i = m.begin();
	for (std::map<int, int>::const_iterator i = m.begin(); i != m.end(); i++) {
		std::cout << i->first << std::endl;
	}


    return 0;
}
