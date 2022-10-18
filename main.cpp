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
		m1.insert(ft::make_pair(15, 1));
		m1.insert(ft::make_pair(10, 2));
		m1.insert(ft::make_pair(17, 2));
		m1.insert(ft::make_pair(7, 2));
		m1.insert(ft::make_pair(5, 3));
		m1.insert(ft::make_pair(2, 4));
		m1.insert(ft::make_pair(1, 4));
		m1.insert(ft::make_pair(7, 5));
		m1.insert(ft::make_pair(6, 5));
		m1.insert(ft::make_pair(3, 6));
		m1.insert(ft::make_pair(-2, 6));
		m1.insert(ft::make_pair(99, 6));
		ft::map<int, int>::iterator it = m1.begin();
		it++;
		it++;
		it++;
		it++;
		m1.erase(it);
		for (ft::map<int, int>::iterator i = m1.begin(); i != m1.end(); i++) {
			std::cout << i->first << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
    return 0;
}
