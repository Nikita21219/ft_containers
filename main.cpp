#include "containers.h"
#include <algorithm> //TODO tmp line
#include <list> //TODO tmp line
#include <vector> //TODO tmp line
#include <map> //TODO tmp line
#include <iostream>
#include <iomanip>

int _ratio = 1;

template <class T, class V>
std::vector<int>    reverse_iterators_test_std(std::map<T, V> mp) {
    std::vector<int> v;

    mp.insert(std::make_pair(5, 5));
    mp.insert(std::make_pair(3, 3));
    mp.insert(std::make_pair(7, 7));
    typename std::map<T, V>::reverse_iterator rit = mp.rbegin();
    typename std::map<T, V>::reverse_iterator rit2 = mp.rend();
    v.push_back(rit->first);
    rit++;
    rit2--;
    v.push_back(rit->first);
    v.push_back(rit2->first);
    rit++;
    v.push_back(*rit == *rit2);
    rit2--;
    v.push_back(rit->first);
    v.push_back(rit2->first);
    v.push_back(*rit2 > *rit);
    v.push_back(*rit2 < *rit);
    v.push_back((--rit)->first);
    v.push_back((++rit2)->first);
    v.push_back((rit--)->first);
    v.push_back((rit2++)->first);
    return v;
}

template <class T, class V>
std::vector<int> reverse_iterators_test_ft(ft::map<T, V> mp) {

    std::vector<int> v;

    mp.insert(ft::make_pair(5, 5));
    mp.insert(ft::make_pair(3, 3));
    mp.insert(ft::make_pair(7, 7));
    typename ft::map<T, V>::reverse_iterator rit = mp.rbegin();
    typename ft::map<T, V>::reverse_iterator rit2 = mp.rend();
    v.push_back(rit->first);
    rit++;
    rit2--;
    v.push_back(rit->first);
    v.push_back(rit2->first);
    rit++;
    v.push_back(*rit == *rit2);
    rit2--;
    v.push_back(rit->first);
    v.push_back(rit2->first);
    v.push_back(*rit2 > *rit);
    v.push_back(*rit2 < *rit);
    v.push_back((--rit)->first);
    v.push_back((++rit2)->first);
    v.push_back((rit--)->first);
    v.push_back((rit2++)->first);
    return v;
}


int main() {

    {
        std::cout << "FT:  ";
        ft::map<int, int> m;
        std::vector<int> v = reverse_iterators_test_ft(m);
        (void) v;
        for (std::vector<int>::iterator i = v.begin(); i != v.end(); i++) std::cout << *i << " ";
        std::cout << "\n";
    }

    {
        std::cout << "STD: ";
        std::map<int, int> m;
        std::vector<int> v = reverse_iterators_test_std(m);
        (void) v;
        for (std::vector<int>::iterator i = v.begin(); i != v.end(); i++) std::cout << *i << " ";
        std::cout << "\n";
    }

    return 0;
}
