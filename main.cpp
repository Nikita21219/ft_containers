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

template <class T>
void printVector(T v) {
    for (typename T::iterator i = v.begin(); i != v.end(); i++)
        std::cout << *i << " ";
    std::cout << "\nsize=" << v.size() << " cap=" << v.capacity() << "\n";
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


template <class T>
std::vector<int> constructor_test(std::stack<T> stk) {
	std::vector<int> v;
	std::deque<int> deque;
	for (int i = 0; i < 100 * _ratio; ++i)
		deque.push_back(i);
	for (int i = 100 * _ratio; i < 200 * _ratio; ++i)
		stk.push(i);
	std::stack<int> stack(deque);
	std::stack<int> stack2(stk);
	std::stack<int> stack3;
	stack3 = stack2;
	while (stack.size() > 0) {
		v.push_back(stack.top());
		stack.pop();
	}
	while (stack2.size() > 0) {
		v.push_back(stack2.top());
		stack2.pop();
	}
	return v;
}

template <class T>
std::vector<int> constructor_test(ft::stack<T> stk) {
	std::vector<int> v;
	ft::vector<int> deque;
	for (int i = 0; i < 100 * _ratio; ++i)
		deque.push_back(i);
	for (int i = 100 * _ratio; i < 200 * _ratio; ++i)
		stk.push(i);
	ft::stack<int> stack(deque);
	ft::stack<int> stack2(stk);
	ft::stack<int> stack3;
	stack3 = stack2;
	while (stack.size() > 0) {
		v.push_back(stack.top());
		stack.pop();
	}
	while (stack2.size() > 0) {
		v.push_back(stack2.top());
		stack2.pop();
	}
	return v;
}
int main() {

    {
        std::cout << "std: ";
        std::vector<int> v;
		for (size_t i = 0; i < 15; i++)
			v.insert(v.begin(), i);
		printVector(v);
    }

    {
        std::cout << "ft:  ";
        ft::vector<int> v;
		for (size_t i = 0; i < 15; i++)
			v.insert(v.begin(), i);
		printVector(v);
    }

    return 0;
}
