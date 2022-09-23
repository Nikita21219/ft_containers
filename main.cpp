#include "containers.h"
#include <algorithm> //TODO tmp line
#include <list> //TODO tmp line
#include <vector> //TODO tmp line
#include <iostream>

// template <typename T>
// void print_info(std::vector<T> &v) {
//     std::cout << "size = " << v.size() << std::endl;
//     std::cout << "cap = " << v.capacity() << std::endl;
//     std::cout << "vector: ";
//     for (size_t i = 0; i < v.size(); i++)
//         std::cout << v[i] << " ";
//     std::cout << std::endl << std::endl;
// } //TODO delene func

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
};


template<typename T>
std::ostream& operator<<(std::ostream& os, const Test<T>& dt)
{
    os << dt.el;
    return os;
}

int main() {

    // Test<int> t(10);
    // Test<int> *test = &t;
    // test->~Test();

    // exit(0);

    // ---------------------------------------------------------------------------------------------------------
    // // Constructor and copy constructor
    // {
    //     // ------------------------FT----------------------------
    //     ft::vector<int> v1(10, 1);
    //     std::cout << "FT v1: " << v1.size() << std::endl;
    //     std::cout << "FT v1: " << v1.capacity() << std::endl;
    //     std::cout << "FT v1: ";
    //     for (int i = 0; i < 10; i++)
    //         std::cout << v1[i] << " ";
    //     std::cout << "\n";
    //     ft::vector<int> v1_copy(v1);
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
    // ---------------------------------------------------------------------------------------------------------

    // ---------------------------------------------------------------------------------------------------------
    // // Copy assigment
    // {
    //     std::vector<int> stl_v(10, 5);
    //     std::vector<int> stl_v_assigment = stl_v;
    //     std::cout << "STL: ";
    //     for (size_t i = 0; i < 10; i++)
    //         std::cout << stl_v_assigment[i];
    //     std::cout << "\n";

    //     ft::vector<int> ft_v(10, 5);
    //     ft::vector<int> ft_v_assigment = ft_v;
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
    // ---------------------------------------------------------------------------------------------------------
    // ---------------------------------------------------------------------------------------------------------
    // // ***************** Iterators *******************
    // {
    //     std::vector<int*> v1;
    //     v1.reserve(10);
    //     int *i = new int(10);
    //     v1.push_back(i);
    //     v1.clear();
    //     delete i;
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
    // ---------------------------------------------------------------------------------------------------------
    // ---------------------------------------------------------------------------------------------------------
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
    // ---------------------------------------------------------------------------------------------------------
    // ---------------------------------------------------------------------------------------------------------
    // // ******************** Reverse iterators ****************************
    // {
    //     std::vector<std::string> v1;
    //     for (size_t i = 0; i <= 10; i++) {v1.push_back("hello");}
    //     v1.pop_back();
    //     v1.pop_back();
    //     for (std::vector<std::string>::reverse_iterator it = v1.rbegin(); it != v1.rend(); it++) {std::cout << *it << " ";}
    //     std::cout << std::endl;
    // }
    // {
    //     ft::vector<std::string> v1;
    //     for (size_t i = 0; i <= 10; i++) {v1.push_back("hello");}
    //     v1.pop_back();
    //     v1.pop_back();
    //     for (ft::vector<std::string>::reverse_iterator it = v1.rbegin(); it != v1.rend(); it++) {std::cout << *it << " ";}
    //     std::cout << std::endl;
    // }
    // ---------------------------------------------------------------------------------------------------------
    // ---------------------------------------------------------------------------------------------------------
    // // ******************* Const reverse iterator ********************
    // {
    //     std::vector<int> v1;
    //     for (int i = 0; i < 10; i++) {v1.push_back(i);}
    //     for (std::vector<int>::const_reverse_iterator it = v1.crbegin(); it != v1.crend(); it++) {std::cout << *it << " ";}
    //     std::cout << "\n";
    // }
    // {
    //     ft::vector<int> v1;
    //     for (int i = 0; i < 10; i++) {v1.push_back(i);}
    //     for (ft::vector<int>::const_reverse_iterator it = v1.crbegin(); it != v1.crend(); it++) {std::cout << *it << " ";}
    //     std::cout << "\n";
    // }
    // ---------------------------------------------------------------------------------------------------------
    // ---------------------------------------------------------------------------------------------------------
    // // ******************* Test -> operator ********************
    // {
    //     std::vector<Test<int> > v1;
    //     for (size_t i = 0; i <= 10; i++) {v1.push_back(Test<int> (new int(10)));}
    //     std::vector<Test<int> >::reverse_iterator it = v1.rbegin();
    //     std::cout << *(it->arr) << std::endl;
    // }
    // {
    //     ft::vector<Test<int> > v1;
    //     for (size_t i = 0; i <= 10; i++) {v1.push_back(Test<int> (new int(10)));}
    //     ft::vector<Test<int> >::reverse_iterator it = v1.rbegin();
    //     std::cout << *(it->arr) << std::endl;
    // }
    // ---------------------------------------------------------------------------------------------------------
    // ---------------------------------------------------------------------------------------------------------
    // // ******************* Test >, <, >=, <= operators ********************
    // {
    //     std::cout << "STL:" << std::endl;
    //     std::vector<size_t> v1;
    //     for (size_t i = 0; i <= 10; i++) {v1.push_back(i);}
    //     std::vector<size_t>::iterator it_1 = v1.begin();
    //     std::vector<size_t>::iterator it_2 = v1.begin();
    //     if (it_1 == it_2) std::cout << "==" << std::endl;
    //     else std::cout << "FAIL" << std::endl;
    //     it_1++;
    //     if (it_1 > it_2) std::cout << ">" << std::endl;
    //     else std::cout << "FAIL" << std::endl;
    //     if (it_1 >= it_2) std::cout << ">=" << std::endl;
    //     else std::cout << "FAIL" << std::endl;
    //     it_2++;
    //     it_2++;
    //     if (it_1 < it_2) std::cout << "<" << std::endl;
    //     else std::cout << "FAIL" << std::endl;
    //     if (it_1 <= it_2) std::cout << "<=" << std::endl;
    //     else std::cout << "FAIL" << std::endl;
    // }
    // {
    //     std::cout << "FT:" << std::endl;
    //     ft::vector<size_t> v1;
    //     for (size_t i = 0; i <= 10; i++) {v1.push_back(i);}
    //     ft::vector<size_t>::iterator it_1 = v1.begin();
    //     ft::vector<size_t>::iterator it_2 = v1.begin();
    //     if (it_1 == it_2) std::cout << "==" << std::endl;
    //     else std::cout << "FAIL" << std::endl;
    //     it_1++;
    //     if (it_1 > it_2) std::cout << ">" << std::endl;
    //     else std::cout << "FAIL" << std::endl;
    //     if (it_1 >= it_2) std::cout << ">=" << std::endl;
    //     else std::cout << "FAIL" << std::endl;
    //     it_2++;
    //     it_2++;
    //     if (it_1 < it_2) std::cout << "<" << std::endl;
    //     else std::cout << "FAIL" << std::endl;
    //     if (it_1 <= it_2) std::cout << "<=" << std::endl;
    //     else std::cout << "FAIL" << std::endl;
    // }
    // ---------------------------------------------------------------------------------------------------------
    // ---------------------------------------------------------------------------------------------------------

    // {
    //     std::vector<int> v1(10, 5);
    //     std::vector<int>::iterator first = v1.begin();
    //     std::vector<int>::iterator last = v1.end();
    //     std::cout << std::distance(first, last) << "\n";
    //     std::vector<int> v2(first, last);
    //     for (int i = 0; i < 10; i++) std::cout << v2[i] << " ";
    //     std::cout << "\n";
    //     std::cout << "v2.capacity(): " << v2.capacity() << std::endl;
    // }

    {
        // ft::vector<int> v1(10, 5);
        // ft::vector<int>::iterator first = v1.begin();
        // ft::vector<int>::iterator last = v1.end();
        // std::cout << std::distance(first, last) << "\n";
        // ft::vector<int> v2(first, last);
        // for (int i = 0; i < 10; i++) std::cout << v2[i] << " ";
        // std::cout << "\n";
    }
    // ---------------------------------------------------------------------------------------------------------
    // ---------------------------------------------------------------------------------------------------------
    // // ******************** Test erase(pos) ***************************
    // {
    //     std::vector<int> v1(15, 1);
    //     std::vector<int>::iterator it = v1.begin();
    //     v1.erase(it);
    //     it = v1.begin();
    //     it++;
    //     it++;
    //     it++;
    //     v1.erase(it);
    //     it = v1.end();
    //     it--;
    //     it--;
    //     v1.erase(it);
    //     print_info(v1);
    // }
    // std::cout << std::endl;
    // {
    //     std::vector<int> v1(15, 1);
    //     std::vector<int>::iterator it = v1.begin();
    //     v1.erase(it);
    //     it = v1.begin();
    //     it++;
    //     it++;
    //     it++;
    //     v1.erase(it);
    //     it = v1.end();
    //     it--;
    //     it--;
    //     v1.erase(it);
    //     print_info(v1);
    // }
    // // ******************** Test erase(first, last) ***************************
    // {
    //     std::vector<int> v1;
    //     for (int i = 1; i <= 6; i++) v1.push_back(i);
    //     std::vector<int>::iterator first = v1.begin();
    //     std::vector<int>::iterator last = v1.end();
    //     first++;
    //     first++;
    //     last--;
    //     std::cout << "erase: " << *(v1.erase(first, last)) << "\n";
    //     print_info(v1);
    // }
    // {
    //     ft::vector<int> v1;
    //     for (int i = 1; i <= 6; i++) v1.push_back(i);
    //     ft::vector<int>::iterator first = v1.begin();
    //     ft::vector<int>::iterator last = v1.end();
    //     first++;
    //     first++;
    //     last--;
    //     std::cout << "erase: " << *(v1.erase(first, last)) << "\n";
    //     print_info(v1);
    // }
    // ---------------------------------------------------------------------------------------------------------
    // ---------------------------------------------------------------------------------------------------------
    // // ******************** Test assign(n, val) ***************************
    // {
    //     std::vector<int> v1;
    //     for (int i = 1; i <= 6; i++) v1.push_back(i);
    //     v1.assign(3, 999);
    //     print_info(v1);
    // }
    // {
    //     ft::vector<int> v1;
    //     for (int i = 1; i <= 6; i++) v1.push_back(i);
    //     v1.assign(3, 999);
    //     print_info(v1);
    // }
    // // ******************** Test assign(iter, iter) ***************************
    // {
    //     std::vector<int> v1;
    //     std::vector<int> v2;
    //     for (int i = 1; i <= 17; i++) v1.push_back(i);
    //     v2.assign(v1.begin(), v1.end());
    //     print_info(v2);
    // }
    
    // {
    //     ft::vector<int> v1;
    //     ft::vector<int> v2;
    //     for (int i = 1; i <= 17; i++) v1.push_back(i);
    //     v2.assign(v1.begin(), v1.end());
    //     print_info(v2);
    // }
    // ---------------------------------------------------------------------------------------------------------
    // // ******************** Test insert(pos, val) ***************************

    {
        std::vector<int> v1;
        for (int i = 1; i <= 17; i++) v1.push_back(i);
        std::vector<int>::iterator it = v1.begin();
        it++;
        it++;
        it++;
        v1.insert(v1.begin(), 999);
        v1.insert(it, 999);
        std::vector<int>::iterator it_end = v1.end();
        it_end--;
        std::cout << "🔰insert: " << *(v1.insert(it_end, 999)) << "\n";
        print_info(v1);
    }

    {
        ft::vector<int> v1;
        for (int i = 1; i <= 17; i++) v1.push_back(i);
        ft::vector<int>::iterator it = v1.begin();
        it++;
        it++;
        it++;
        v1.insert(v1.begin(), 999);
        v1.insert(it, 999);
        ft::vector<int>::iterator it_end = v1.end();
        it_end--;
        std::cout << "🔰insert: " << *(v1.insert(it_end, 999)) << "\n";
        print_info(v1);
    }


    // ---------------------------------------------------------------------------------------------------------
    // ---------------------------------------------------------------------------------------------------------
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

