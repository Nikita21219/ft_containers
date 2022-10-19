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
		std::map<char,int> mymap;
		mymap['x']=1001;
		mymap['y']=2002;
		mymap['z']=3003;
		std::cout << "mymap contains:\n";
		std::pair<char,int> highest = *mymap.rbegin();
		std::map<char,int>::iterator it = mymap.begin();
		do {
		std::cout << it->first << " => " << it->second << '\n';
		} while ( mymap.value_comp()(*it++, highest) );
	}
	std::cout << "\n";
	std::cout << "\n";
	{
		ft::map<char,int> mymap;
		mymap['x']=1001;
		mymap['y']=2002;
		mymap['z']=3003;
		std::cout << "mymap contains:\n";
		ft::pair<char,int> highest = *mymap.rbegin();
		(void)highest;
		ft::map<char,int>::iterator it = mymap.begin();
		do {
		std::cout << it->first << " => " << it->second << '\n';
		} while ( mymap.value_comp()(*it++, highest) );
	}
	std::cout << "\n";
    return 0;
}
