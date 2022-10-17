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
		std::map<int, int> m1;
		m1.insert(std::pair<int, int>(15, 1));
		m1.insert(std::pair<int, int>(10, 2));
		m1.insert(std::pair<int, int>(5, 3));
		m1.insert(std::pair<int, int>(2, 4));
		m1.insert(std::pair<int, int>(7, 5));
		m1.insert(std::pair<int, int>(3, 6));
		std::pair<std::map<int, int>::iterator, bool> it = m1.insert(std::pair<int, int>(0, 99));
		(void)it;
		m1.insert(m1.begin(), std::pair<int, int>(3, 99));
		std::cout << "\n";
		for (std::map<int, int>::iterator i = m1.begin(); i != m1.end(); i++) {
			std::cout << i->first << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	{
		ft::map<int, int> m1;
		m1.insert(ft::pair<int, int>(15, 1));
		m1.insert(ft::pair<int, int>(10, 2));
		m1.insert(ft::pair<int, int>(5, 3));
		m1.insert(ft::pair<int, int>(2, 4));
		m1.insert(ft::pair<int, int>(7, 5));
		m1.insert(ft::pair<int, int>(3, 6));
		ft::pair<ft::map<int, int>::iterator, bool> it = m1.insert(ft::pair<int, int>(0, 99));
		(void)it;
		m1.insert(m1.begin(), ft::pair<int, int>(3, 99));
		std::cout << "\n";
		for (ft::map<int, int>::iterator i = m1.begin(); i != m1.end(); i++) {
			std::cout << i->first << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";

    return 0;
}
