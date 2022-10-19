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
	int k = 20;
	{
		std::map<int, int> m;
		m.insert(std::make_pair<int, int>(10, 1));
		m.insert(std::make_pair<int, int>(20, 1));
		m.insert(std::make_pair<int, int>(30, 1));
		m.insert(std::make_pair<int, int>(40, 1));
		m.insert(std::make_pair<int, int>(50, 1));
		const std::map<int, int> m1(m);
		std::cout << "Upper bound STL: " << m.upper_bound(k)->first << "\n";
	}
	{
		ft::map<int, int> m;
		m.insert(ft::make_pair<int, int>(10, 1));
		m.insert(ft::make_pair<int, int>(20, 1));
		m.insert(ft::make_pair<int, int>(30, 1));
		m.insert(ft::make_pair<int, int>(40, 1));
		m.insert(ft::make_pair<int, int>(50, 1));
		const ft::map<int, int> m1(m);
		std::cout << "Upper bound FT: " << m1.upper_bound(k)->first << "\n";
	}
    return 0;
}
