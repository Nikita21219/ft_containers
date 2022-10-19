#include "containers.h"
#include <algorithm> //TODO tmp line
#include <list> //TODO tmp line
#include <vector> //TODO tmp line
#include <map> //TODO tmp line
#include <iostream>
#include <iomanip>


template <class T, class V>
std::vector<int> copy_constructor_test(std::map<T, V> mp) {

    std::vector<int> v;

    for (int i = 0, j = 10; i < 30 * 100000; ++i, ++j) {
        mp.insert(std::make_pair(i, j));
    }
    std::map<int, int> mp2(mp.begin(), mp.end());
    std::map<int, int>::iterator it = mp2.begin();
    for (int i = 0; i < 30 * 100000; ++i, it++) {
        v.push_back(it->first);
        v.push_back(it->second);
    }
    return v;
}

template <class T, class V>
std::vector<int> copy_constructor_test(ft::map<T, V> mp) {
	(void)mp;

    std::vector<int> v;

    // for (int i = 0, j = 10; i < 30 * 100000; ++i, ++j) {
    //     mp.insert(ft::make_pair(i, j));
    // }
    // ft::map<int, int> mp2(mp.begin(), mp.end());
    // ft::map<int, int>::iterator it = mp2.begin();
    // for (int i = 0; i < 30 * 100000; ++i, it++) {
    //     v.push_back(it->first);
    //     v.push_back(it->second);
    // }
    return v;
}

int main() {
	std::cout << "\n";
	{
		ft::map<int, int> m;
		m.insert(ft::make_pair<int, int>(1, 1));
		m.insert(ft::make_pair<int, int>(413, 1));
		m.insert(ft::make_pair<int, int>(12, 1));
		m.insert(ft::make_pair<int, int>(13, 1));
		m.insert(ft::make_pair<int, int>(19, 1));
		m.insert(ft::make_pair<int, int>(4, 1));
		m.insert(ft::make_pair<int, int>(2, 1));
		std::cout << "Before size: " << m.size() << "\n";
		std::cout << "Before map: ";
		for (ft::map<int, int>::iterator i = m.begin(); i != m.end(); i++)
			std::cout << i->first << " ";
		std::cout << "\n";
		std::cout << "Clear\n";
		m.clear();
		std::cout << "After size: " << m.size() << "\n";
		std::cout << "After map: ";
		for (ft::map<int, int>::iterator i = m.begin(); i != m.end(); i++)
			std::cout << i->first << " ";
	}

	std::cout << "\n";
    return 0;
}
