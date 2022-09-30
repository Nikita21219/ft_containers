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


template<typename T>
class Test {
public:
    // typedef typename std::conditional<isConst, const T*, T*>::type conditional_ptr;

    Test(T i) {el = i;}
    ~Test() {std::cout << "Destructor called\n";}
// private:
    T el;
}; //TODO delene class

template<typename T>
std::ostream& operator<<(std::ostream& os, const Test<T>& dt)
{
    os << dt.el;
    return os;
} //TODO delene func

template <typename T>
std::vector<int> assign_test(std::vector<T> vector) {
    std::vector<int> v;
    std::vector<int> tmp, tmp2;
    // vector.assign(3, 3);
    tmp.assign(20, 1);
    tmp2.assign(4, 1);
    vector.assign(tmp.begin(), tmp.end());
    // v.push_back(vector[1]);
    // v.push_back(vector.size());
    // v.push_back(vector.capacity());
    vector.assign(tmp2.begin(), tmp2.end()); // TODO
    print_info(vector);
    // v.push_back(vector[444]);
    // v.push_back(vector.size());
    // v.push_back(vector.capacity());
    return v;
}

template <typename T>
std::vector<int> assign_test(ft::vector<T> vector) {
    std::vector<int> v;
    ft::vector<int> tmp, tmp2;
    // vector.assign(3, 3);
    tmp.assign(20, 1);
    tmp2.assign(4, 1);
    vector.assign(tmp.begin(), tmp.end());
    // v.push_back(vector[1]);
    // v.push_back(vector.size());
    // v.push_back(vector.capacity());
    vector.assign(tmp2.begin(), tmp2.end()); // TODO
    print_info(vector);
    // v.push_back(vector[444]);
    // v.push_back(vector.size());
    // v.push_back(vector.capacity());
    return v;
}

int main() {
    {
        std::vector<int> v;
        assign_test(v);
    }
    {
        ft::vector<int> v;
        assign_test(v);
    }
    return 0;
}

 // {
    //     std::vector<int>::iterator iter;
    //     std::vector<int>::const_iterator const_iter;
    //     //должно работать
    //     const_iter.operator=(iter);
    //     const_iter = iter;
    //     //не должно работать
    //     // iter = const_iter;

    //     // std::vector<int>::reverse_iterator::

    // }
    // {
    //     ft::vector<int>::iterator iter;
    //     ft::vector<int>::const_iterator const_iter;
    //     // const_iter = iter;
    // }

