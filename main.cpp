#include "containers.h"
#include <algorithm> //TODO tmp line
#include <list> //TODO tmp line
#include <vector> //TODO tmp line
#include <map> //TODO tmp line
#include <iostream>
#include <iomanip>

int main() {
	std::cout << "\n";
	{
		ft::map<int, int> m1;
		m1.insert(ft::pair<int, int>(15, 1));
		m1.insert(ft::pair<int, int>(10, 2));
		m1.insert(ft::pair<int, int>(5, 3));
		m1.insert(ft::pair<int, int>(2, 4));
		m1.insert(ft::pair<int, int>(7, 5));
		m1.insert(ft::pair<int, int>(3, 6));
		m1.insert(ft::pair<int, int>(3, 7));
		m1.insert(ft::pair<int, int>(3, 8));
		m1.insert(ft::pair<int, int>(3, 9));
		ft::pair<ft::map<int, int>::iterator, bool> it = m1.insert(ft::pair<int, int>(10, 99));

		std::cout << "ITER FT:" << "\nit.second = " << it.second << std::endl;
		std::cout << "it.first->first = " << it.first->first << std::endl;
		std::cout << "it.first->second = " << it.first->second << std::endl;
		for (ft::map<int, int>::reverse_iterator it = m1.rbegin(); it != m1.rend(); it++) {
			std::cout << it->first << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	{
		std::map<int, int> m1;
		m1.insert(std::pair<int, int>(15, 1));
		m1.insert(std::pair<int, int>(10, 2));
		m1.insert(std::pair<int, int>(5, 3));
		m1.insert(std::pair<int, int>(2, 4));
		m1.insert(std::pair<int, int>(7, 5));
		m1.insert(std::pair<int, int>(3, 6));
		m1.insert(std::pair<int, int>(3, 7));
		m1.insert(std::pair<int, int>(3, 8));
		m1.insert(std::pair<int, int>(3, 9));
		std::pair<std::map<int, int>::iterator, bool> it = m1.insert(std::pair<int, int>(10, 99));

		std::cout << "ITER STL:" << "\nit.second = " << it.second << std::endl;
		std::cout << "it.first->first = " << it.first->first << std::endl;
		std::cout << "it.first->second = " << it.first->second << std::endl;
		for (std::map<int, int>::reverse_iterator it = m1.rbegin(); it != m1.rend(); it++) {
			std::cout << it->first << " ";
		}
		std::cout << "\n";
	}


    return 0;
}
