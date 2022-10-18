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
		m1.insert(std::pair<int, int>(17, 2));
		m1.insert(std::pair<int, int>(7, 2));
		m1.insert(std::pair<int, int>(5, 3));
		m1.insert(std::pair<int, int>(2, 4));
		m1.insert(std::pair<int, int>(1, 4));
		m1.insert(std::pair<int, int>(7, 5));
		m1.insert(std::pair<int, int>(6, 5));
		m1.insert(std::pair<int, int>(3, 6));
		m1.insert(std::pair<int, int>(-2, 6));
		m1.insert(std::pair<int, int>(99, 6));
		std::map<int, int>::iterator it = m1.begin();
		std::map<int, int>::iterator it_end = m1.begin();
		it++;
		it++;
		it++;
		it_end++;
		it_end++;
		it_end++;
		it_end++;
		it_end++;
		it_end++;
		it_end++;
		it_end++;
		it_end++;
		it_end++;
		m1.erase(it, it_end);
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
		m1.insert(ft::pair<int, int>(17, 2));
		m1.insert(ft::pair<int, int>(7, 2));
		m1.insert(ft::pair<int, int>(5, 3));
		m1.insert(ft::pair<int, int>(2, 4));
		m1.insert(ft::pair<int, int>(1, 4));
		m1.insert(ft::pair<int, int>(7, 5));
		m1.insert(ft::pair<int, int>(6, 5));
		m1.insert(ft::pair<int, int>(3, 6));
		m1.insert(ft::pair<int, int>(-2, 6));
		m1.insert(ft::pair<int, int>(99, 6));
		ft::map<int, int>::iterator it = m1.begin();
		ft::map<int, int>::iterator it_end = m1.begin();
		it++;
		it++;
		it++;
		it_end++;
		it_end++;
		it_end++;
		it_end++;
		it_end++;
		it_end++;
		it_end++;
		it_end++;
		it_end++;
		it_end++;
		m1.erase(it, it_end);
		for (ft::map<int, int>::iterator i = m1.begin(); i != m1.end(); i++) {
			std::cout << i->first << " ";
		}
		
		std::cout << "\n";
	}

	std::cout << "\n";
    return 0;
}
