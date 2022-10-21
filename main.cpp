#include "containers.h"
#include <algorithm> //TODO tmp line
#include <list> //TODO tmp line
#include <vector> //TODO tmp line
#include <map> //TODO tmp line
#include <iostream>
#include <iomanip>

int _ratio = 1;

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
std::vector<int>    iterators_test(std::map<T, V> mp) {
    std::vector<int> v;
    std::map<T, V> mpp;
    fillMap(mpp);
    for (typename std::map<T, V>::iterator it = mpp.begin(); it != mpp.end(); it++) { v.push_back(it->first); }
    for (typename std::map<T, V>::iterator it = --mpp.end(); it != mpp.begin(); it--) { v.push_back(it->first); }
    std::map<int, int> mp0;
    std::map<int, int>::iterator ii = mp0.insert(std::make_pair(3, 3)).first;
    ii++;
    v.push_back((--ii)->first);
    for (int i = 0, j = 10; i < 5; ++i, ++j)
        mp.insert(std::make_pair(i, j));
    typename std::map<T, V>::iterator it = mp.begin();
    typename std::map<T, V>::iterator it2 = mp.end();
    v.push_back(it->first);
    it++;
    it++;
    it++;
    it++;
    v.push_back(it->first);
    it++;
    it--;
    v.push_back(it->first);
    it2--;
    v.push_back(it2->first);
    v.push_back(it2 == it);
    v.push_back((--it2)->first);
    v.push_back((it2--)->first);
    v.push_back((it2++)->first);
    v.push_back((++it2)->first);
    return v;
}

template <class T, class V>
std::vector<int> iterators_test(ft::map<T, V> mp) {
    (void)mp;
    std::vector<int> v;
    ft::map<T, V> mpp;
    fillMap(mpp);
    for (typename ft::map<T, V>::iterator it = mpp.begin(); it != mpp.end(); it++) { v.push_back(it->first); }
    for (typename ft::map<T, V>::iterator it = --mpp.end(); it != mpp.begin(); it--) { v.push_back(it->first); }
    // ft::map<int, int> mp0;
    // ft::map<int, int>::iterator ii = mp0.insert(ft::make_pair(3, 3)).first;
    // ii++;
    // v.push_back((--ii)->first);
    // for (int i = 0, j = 10; i < 5; ++i, ++j)
    //     mp.insert(ft::make_pair(i, j));
    // typename ft::map<T, V>::iterator it = mp.begin();
    // typename ft::map<T, V>::iterator it2 = mp.end();
    // v.push_back(it->first);
    // it++;
    // it++;
    // it++;
    // it++;
    // v.push_back(it->first);
    // it++;
    // it--;
    // v.push_back(it->first);
    // it2--;
    // v.push_back(it2->first);
    // v.push_back(it2 == it);
    // v.push_back((--it2)->first);
    // v.push_back((it2--)->first);
    // v.push_back((it2++)->first);
    // v.push_back((++it2)->first);
    return v;
}

int main() {
    // {
    //     ft::map<int, int> m;
    //     iterators_test(m);
    // }

    {
        std::map<int, int> m;
        for (size_t i = 0; i < 10; i++) {
            std::pair<std::map<int, int>::iterator, bool> p = m.insert(std::make_pair(i, 0));
            std::cout << p.first->first << " ";
        }
        std::cout << "\n";
        // for (std::map<int, int>::iterator i = --m.end(); i != m.begin(); i--)
        //     std::cout << i->first << " ";
        std::cout << "\n";
    }

    {
        ft::map<int, int> m;
        for (size_t i = 0; i < 10; i++) {
            ft::pair<ft::map<int, int>::iterator, bool> p = m.insert(ft::make_pair(i, 0));
            std::cout << p.first->first << " ";
        }
        std::cout << "\n";
        // for (std::map<int, int>::iterator i = --m.end(); i != m.begin(); i--)
        //     std::cout << i->first << " ";
        std::cout << "\n";
    }

    return 0;
}
