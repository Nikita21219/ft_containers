#include "containers.h"
#include <algorithm> //TODO tmp line
#include <list> //TODO tmp line
#include <vector> //TODO tmp line


int main() {

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
    //     std::vector<int> v1;
    //     std::vector<int> v2(5, 5);
    //     v1.push_back(10);
    //     v1.push_back(10);
    //     v1.push_back(10);
    //     v1.push_back(10);
    //     v1.push_back(10);
    //     v1.push_back(10);
    //     v1.push_back(15);
    //     v1.swap(v2);
    //     std::cout << "v2.size() = " << v2.size() << std::endl;
    //     std::cout << "v2.capacity() = " << v2.capacity() << std::endl;
    //     for (size_t i = 0; i < v2.size(); i++)
    //         std::cout << "v2: " << v2[i] << std::endl;
    // }
    // std::cout << std::endl;
    // {
    //     vector<int> v1;
    //     vector<int> v2(5, 5);
    //     v1.push_back(10);
    //     v1.push_back(10);
    //     v1.push_back(10);
    //     v1.push_back(10);
    //     v1.push_back(10);
    //     v1.push_back(10);
    //     v1.push_back(15);
    //     v1.swap(v2);
    //     std::cout << "v2.size() = " << v2.size() << std::endl;
    //     std::cout << "v2.capacity() = " << v2.capacity() << std::endl;
    //     for (size_t i = 0; i < v2.size(); i++)
    //         std::cout << "v2: " << v2[i] << std::endl;
    // }



    return 0;
}
