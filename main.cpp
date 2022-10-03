#include "containers.h"
#include <algorithm> //TODO tmp line
#include <list> //TODO tmp line
#include <vector> //TODO tmp line
#include <iostream>
#include <iomanip>

template <typename vector_type>
void print_info(vector_type &v) {
    std::cout << "size = " << v.size() << std::endl;
    std::cout << "cap = " << v.capacity() << std::endl;
    std::cout << "vector: ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl << std::endl;
} //TODO delene func


template <typename T>
std::vector<int> erase_test_1(std::vector<T> vector) {
    std::vector<int> v;
    for (int i = 0; i < 9900; ++i)
        vector.push_back(i);
    v.push_back(*(vector.erase(vector.begin() + 8)));
    v.push_back(*(vector.begin() + 82));
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

template <typename T>
std::vector<int> erase_test_1(ft::vector<T> vector) {
    std::vector<int> v;
    for (int i = 0; i < 9900; ++i)
        vector.push_back(i);
    v.push_back(*(vector.erase(vector.begin() + 8)));
    v.push_back(*(vector.begin() + 82));
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

int main() {
    {
        ft::vector<int> v;
        std::vector<int> res = erase_test_1(v);
        print_info(res);
    }
    {
        std::vector<int> v;
        std::vector<int> res = erase_test_1(v);
        print_info(res);
    }
    return 0;
}

/*
{
    std::vector<int>::iterator iter;
    std::vector<int>::const_iterator const_iter;
    //должно работать
    const_iter.operator=(iter);
    const_iter = iter;
    //не должно работать
    // iter = const_iter;

    // std::vector<int>::reverse_iterator::

}
{
    ft::vector<int>::iterator iter;
    ft::vector<int>::const_iterator const_iter;
    // const_iter = iter;
}
*/
