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

    {
        // std::vector<int> v;
        // for (size_t i = 0; i < 10; i++) {
        //     v.push_back(i);
        //     std::cout << "Capacity: " << v.capacity();
        //     std::cout << " Size: " << v.size();
        //     std::cout << " Element: " << v[i];
        //     std::cout << std::endl;
        // }
        // std::cout << std::endl;

        vector<int> ft_v;
        for (size_t i = 0; i < 10; i++) {
            ft_v.push_back(i);
            std::cout << "Capacity: " << ft_v.capacity();
            std::cout << " Size: " << ft_v.size();
            std::cout << " Element: " << ft_v[i];
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
