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
		ft::BTree<int, int> tree;
		tree.treeInsert(ft::pair<int, int>(15, 99));
		tree.treeInsert(ft::pair<int, int>(10, 99));
		tree.treeInsert(ft::pair<int, int>(5, 99));
		tree.treeInsert(ft::pair<int, int>(2, 99));
		tree.treeInsert(ft::pair<int, int>(7, 99));
		tree.treeInsert(ft::pair<int, int>(20, 99));
		tree.treeInsert(ft::pair<int, int>(3, 99));

		// tree.treeWalk(tree.getRoot());
		// std::cout << "\n";

		for (ft::BTree<int, int>::iterator it = tree.begin(); it != tree.end(); it++) {
			std::cout << it->first << " ";
			it->first = 99;
		}
		std::cout << "\n";
	}
	{
		std::map<int, int> tree;
		tree.insert(std::pair<int, int>(15, 99));
		tree.insert(std::pair<int, int>(10, 99));
		tree.insert(std::pair<int, int>(5, 99));
		tree.insert(std::pair<int, int>(2, 99));
		tree.insert(std::pair<int, int>(7, 99));
		tree.insert(std::pair<int, int>(20, 99));
		tree.insert(std::pair<int, int>(3, 99));

		// tree.treeWalk(tree.getRoot());
		// std::cout << "\n";

		for (std::map<int, int>::iterator it = tree.begin(); it != tree.end(); it++) {
			std::cout << it->first << " ";
			it->second = 99;
		}
		std::cout << "\n";
	}

	// std::map<int, int> m;
	// m.insert(std::pair<int, int>(11, 10));
	// m.insert(std::pair<int, int>(10, 10));
	// m.insert(std::pair<int, int>(10, 10));
	// m.insert(std::pair<int, int>(15, 10));
	// m.erase(10);
	// // std::map<int, int>::iterator i = m.begin();
	// for (std::map<int, int>::iterator i = m.begin(); i != m.end(); i++) {
	// 	std::cout << i->first << std::endl;
	// }
	
	
    return 0;
}
