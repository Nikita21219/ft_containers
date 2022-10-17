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


// class Test {
// public:
// 	Test() {}
// 	int *test1() {
// 		std::cout << "not const\n";
// 	}

// 	const int *test1() const {
// 		std::cout << "const\n";
// 	}
// };


int main() {
	// const Test t = Test();
	// const int *a = t.test1();
	// (void) a;



	std::cout << "\n";
	{
		ft::map<int, int> m1;
		m1.insert(ft::pair<int, int>(15, 99));
		m1.insert(ft::pair<int, int>(10, 99));
		m1.insert(ft::pair<int, int>(5, 99));
		m1.insert(ft::pair<int, int>(2, 99));
		m1.insert(ft::pair<int, int>(7, 99));
		m1.insert(ft::pair<int, int>(20, 99));
		m1.insert(ft::pair<int, int>(3, 99));
		// ft::map<int, int>::reverse_iterator it = m1.rbegin();
		// (void) it;

		for (ft::map<int, int>::reverse_iterator it = m1.rbegin(); it != m1.rend(); it++) {
			// it->second = 5;
			std::cout << it->first << " ";
		}
		std::cout << "\n";
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
	// for (std::map<int, int>::const_iterator i = m.begin(); i != m.end(); i++) {
	// 	std::cout << i->first << std::endl;
	// }





    return 0;
}
