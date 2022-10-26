#include "containers.h"
#include <algorithm> //TODO tmp line
#include <list> //TODO tmp line
#include <vector> //TODO tmp line
#include <map> //TODO tmp line
#include <iostream>
#include <iomanip>

int _ratio = 1;

template <class T>
void printMap(T m) {
    for (typename T::iterator i = m.begin(); i != m.end(); i++)
        std::cout << i->first << " ";
    std::cout << "\n";
}

template <class T, class V, class C>
void fillMap(std::map<T, V, C> &mp) {
	mp.insert(std::make_pair(16, 3));
	mp.insert(std::make_pair(8, 3));
	mp.insert(std::make_pair(23, 3));
	mp.insert(std::make_pair(7, 3));
	mp.insert(std::make_pair(19, 3));
	mp.insert(std::make_pair(29, 3));
	mp.insert(std::make_pair(41, 3));
	mp.insert(std::make_pair(4, 3));
	mp.insert(std::make_pair(11, 3));
}

template <class T, class V, class C>
void fillMap(ft::map<T, V, C> &mp) {
	mp.insert(ft::make_pair(16, 3));
	mp.insert(ft::make_pair(8, 3));
	mp.insert(ft::make_pair(23, 3));
	mp.insert(ft::make_pair(7, 3));
	mp.insert(ft::make_pair(19, 3));
	mp.insert(ft::make_pair(29, 3));
	mp.insert(ft::make_pair(41, 3));
	mp.insert(ft::make_pair(4, 3));
	mp.insert(ft::make_pair(11, 3));
}

template <class T, class V>
std::vector<int> insert_test(std::map<T, V> mp) {
    std::vector<int> v;
    std::pair<std::map<int, int>::iterator , bool> pair = mp.insert(std::make_pair(7, 7));
    std::map<int, int>::iterator it = mp.begin();
    v.push_back(it->first);
    v.push_back(it->second);
    v.push_back(pair.first->first);
    v.push_back(pair.first->second);
    v.push_back(pair.second);
    mp.insert(std::make_pair(9, 9));
    std::pair<std::map<int, int>::iterator , bool> pair2 = mp.insert(std::make_pair(9, 9));
    std::map<int, int>::iterator it2 = pair.first;
    v.push_back(it2->first);
    v.push_back(it2->second);
    v.push_back(pair2.first->first);
    v.push_back(pair2.first->second);
    v.push_back(pair2.second);
    for (int i = 0, j = 0; i < 50 * _ratio; ++i, ++j) {
        mp.insert(std::make_pair(i, j));
    }
    typename std::map<T, V>::iterator it3 = mp.begin();
    for (; it3 != mp.end(); ++it3) {
        v.push_back(it3->first);
        v.push_back(it3->second);
    }
    v.push_back(mp.size());
    return v;
}

template <class T, class V>
std::vector<int> insert_test(ft::map<T, V> mp) {
    std::vector<int> v;
    ft::pair<ft::map<int, int>::iterator , bool> pair = mp.insert(ft::make_pair(7, 7));
    ft::map<int, int>::iterator it = mp.begin();
    v.push_back(it->first);
    v.push_back(it->second);
    v.push_back(pair.first->first);
    v.push_back(pair.first->second);
    v.push_back(pair.second);
    mp.insert(ft::make_pair(9, 9));
    ft::pair<ft::map<int, int>::iterator , bool> pair2 = mp.insert(ft::make_pair(9, 9));
    ft::map<int, int>::iterator it2 = pair.first;
    v.push_back(it2->first);
    v.push_back(it2->second);
    v.push_back(pair2.first->first);
    v.push_back(pair2.first->second);
    v.push_back(pair2.second);
    for (int i = 0, j = 0; i < 50 * _ratio; ++i, ++j) {
        mp.insert(ft::make_pair(i, j));
    }
    typename ft::map<T, V>::iterator it3 = mp.begin();
    for (; it3 != mp.end(); ++it3) {
        v.push_back(it3->first);
        v.push_back(it3->second);
    }
    v.push_back(mp.size());
    return v;
}

int main() {
    {
        std::cout << "ft:  ";
        ft::map<int, int> m;
        fillMap(m);
        ft::map<int, int> m2;
        fillMap(m2);
        // printMap(m);
        m2.erase(7);
        std::cout << (m <= m2) << "\n";
        std::cout << "\n";
    }
    {
        std::cout << "std: ";
        std::map<int, int> m;
        fillMap(m);
        std::map<int, int> m2;
        fillMap(m2);
        m2.erase(7);
        // printMap(m);
        std::cout << (m <= m2) << "\n";
        std::cout << "\n";
    }

    return 0;
}
