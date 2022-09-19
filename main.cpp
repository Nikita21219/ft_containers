#include "containers.h"
#include <algorithm> //TODO tmp line
#include <list> //TODO tmp line
#include <vector> //TODO tmp line

template <typename T>
void print_info(std::vector<T> &v) {
    std::cout << "size = " << v.size() << std::endl;
    std::cout << "cap = " << v.capacity() << std::endl;
    std::cout << "vector: ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl << std::endl;
} //TODO delene func

template <typename T>
void print_info(ft::vector<T> &v) {
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

    Test(T *arr): arr(arr) {}
    ~Test() {}
// private:
    T *arr;
};


int main() {


    // Test<true, int> test = Test<true, int>(new int(10));
    // std::cout << *(test.arr) << std::endl;
    // *(test.arr) = 99;
    // std::cout << *(test.arr) << std::endl;
    // return 0;

    // Constructor and copy constructor
    // {
    //     // ------------------------FT----------------------------
    //     vector<int> v1(10, 1);
    //     std::cout << "FT v1: " << v1.size() << std::endl;
    //     std::cout << "FT v1: " << v1.capacity() << std::endl;
    //     std::cout << "FT v1: ";
    //     for (int i = 0; i < 10; i++)
    //         std::cout << v1[i] << " ";
    //     std::cout << "\n";
    //     vector<int> v1_copy(v1);
    //     std::cout << "FT v1_copy: " << v1.size() << std::endl;
    //     std::cout << "FT v1_copy: " << v1.capacity() << std::endl;
    //     std::cout << "FT v1_copy: ";
    //     for (int i = 0; i < 10; i++)
    //         std::cout << v1_copy[i] << " ";

    //     std::cout << "\n\n\n";
        
    //     // ------------------------STL---------------------------
    //     std::vector<int> v2(10, 1);
    //     std::cout << "STL v2: " << v2.size() << std::endl;
    //     std::cout << "STL v2: " << v2.capacity() << std::endl;
    //     std::cout << "STL v2: ";
    //     for (int i = 0; i < 10; i++)
    //         std::cout << v2[i] << " ";
    //     std::cout << "\n";
    //     std::vector<int> v2_copy(v2);
    //     std::cout << "STL v2_copy: " << v2.size() << std::endl;
    //     std::cout << "STL v2_copy: " << v2.capacity() << std::endl;
    //     std::cout << "STL v2_copy: ";
    //     for (int i = 0; i < 10; i++)
    //         std::cout << v2_copy[i] << " ";
    //     std::cout << "\n";
    // }

    // // Copy assigment
    // {
    //     std::vector<int> stl_v(10, 5);
    //     std::vector<int> stl_v_assigment = stl_v;
    //     std::cout << "STL: ";
    //     for (size_t i = 0; i < 10; i++)
    //         std::cout << stl_v_assigment[i];
    //     std::cout << "\n";

    //     vector<int> ft_v(10, 5);
    //     vector<int> ft_v_assigment = ft_v;
    //     std::cout << "FT:  ";
    //     for (size_t i = 0; i < 10; i++)
    //         std::cout << ft_v_assigment[i];
    //     std::cout << "\n";
    // }

    // {
    //     std::vector<int> v1;
    //     std::vector<int> v2(5, 5);
    //     v1.push_back(10);
    //     v1.push_back(10);
    //     v1.push_back(10);
    //     v1.push_back(10);
    //     v1.push_back(10);
    //     v1.swap(v2);
    //     std::cout << "v1.size() = " << v1.size() << std::endl;
    //     std::cout << "v1.capacity() = " << v1.capacity() << std::endl;
    //     for (size_t i = 0; i < v1.size(); i++)   
    //         std::cout << "v1: " << v1[i] << std::endl;
    // }

    // {
    //     std::vector<int*> v1;
    //     v1.reserve(10);
    //     v1.push_back(new int(10));
    //     v1.clear();
    // }

    // {
    //     ft::vector<int> v1;
    //     for (size_t i = 2; i < 40; i *= 2)
    //         v1.push_back(i);
    //     for (ft::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
    //         std::cout << *it << " ";
    //     std::cout << std::endl;
    // }
    // std::cout << "\n";
    // {
    //     std::vector<int> v1;
    //     for (size_t i = 2; i < 40; i *= 2)
    //         v1.push_back(i);
    //     for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
    //         std::cout << *it << " ";
    //     std::cout << std::endl;
    // }

    // // ***************** Const iterators *******************
    // {
    //     ft::vector<int> v1;
    //     v1.push_back(10);
    //     v1.push_back(11);
    //     v1.push_back(12);
    //     v1.push_back(13);
    //     v1.push_back(14);
    //     for (ft::vector<int>::const_iterator it = v1.cbegin(); it != v1.cend(); it++) {std::cout << *it << " ";}
    //     std::cout << std::endl;
    // }
    // {
    //     std::vector<int> v1;
    //     v1.push_back(10);
    //     v1.push_back(11);
    //     v1.push_back(12);
    //     v1.push_back(13);
    //     v1.push_back(14);
    //     for (std::vector<int>::const_iterator it = v1.cbegin(); it != v1.cend(); it++) {std::cout << *it << " ";}
    //     std::cout << std::endl;
    // }
    

    // Test<int> test = Test<int>(new int(10));
    // ft::vector<Test<int> > v1;
    // v1.push_back(test);
    // ft::vector<Test<int> >::iterator it = v1.begin();
    // std::cout << *it << std::endl;

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


    ft::vector<int> v1;
    v1.push_back(10);
    v1.push_back(11);
    v1.push_back(12);
    v1.push_back(13);
    ft::vector<int>::reverse_iterator it = v1.rbegin();
    std::cout << *it << std::endl;

    return 0;
}
