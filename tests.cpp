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

    // {
    //     ft::vector<int> v1(10, 5);
    //     ft::vector<int>::iterator first = v1.begin();
    //     ft::vector<int>::iterator last = v1.end();
    //     std::cout << std::distance(first, last) << "\n";
    //     ft::vector<int> v2(first, last);
    //     for (int i = 0; i < 10; i++) std::cout << v2[i] << " ";
    //     std::cout << "\n";
    // }
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
    // {
    //     std::vector<int> v1;
    //     for (int i = 1; i <= 17; i++) v1.push_back(i);
    //     std::vector<int>::iterator it = v1.begin();
    //     it++;
    //     it++;
    //     it++;
    //     v1.insert(v1.begin(), 999);
    //     v1.insert(it, 999);
    //     std::vector<int>::iterator it_end = v1.end();
    //     it_end--;
    //     std::cout << "🔰insert: " << *(v1.insert(it_end, 999)) << "\n";
    //     print_info(v1);
    // }

    // {
    //     ft::vector<int> v1;
    //     for (int i = 1; i <= 17; i++) v1.push_back(i);
    //     ft::vector<int>::iterator it = v1.begin();
    //     it++;
    //     it++;
    //     it++;
    //     v1.insert(v1.begin(), 999);
    //     v1.insert(it, 999);
    //     ft::vector<int>::iterator it_end = v1.end();
    //     it_end--;
    //     std::cout << "🔰insert: " << *(v1.insert(it_end, 999)) << "\n";
    //     print_info(v1);
    // }
    // // ******************** Test insert(pos, n, val) ***************************
    // {
    //     std::vector<int> v1;
    //     for (int i = 1; i <= 6; i++) v1.push_back(i);
    //     v1.reserve(100);
    //     std::vector<int>::iterator res = v1.insert(v1.begin(), 4, 999);
    //     std::cout << "🔰insert: " << *(res) << "\n";
    //     res++;
    //     res++;
    //     res++;
    //     res++;
    //     std::cout << "🔰insert: " << *(res) << "\n";
    //     print_info(v1);
    // }
    // {
    //     ft::vector<int> v1;
    //     for (int i = 1; i <= 6; i++) v1.push_back(i);
    //     v1.reserve(100);
    //     ft::vector<int>::iterator res = v1.insert(v1.begin(), 4, 999);
    //     std::cout << "🔰insert: " << *(res) << "\n";
    //     res++;
    //     res++;
    //     res++;
    //     res++;
    //     std::cout << "🔰insert: " << *(res) << "\n";
    //     print_info(v1);
    // }

    // // ******************** Test insert(pos, count, val) ***************************
    // {
    //     std::vector<int> v1;
    //     for (int i = 1; i <= 7; i++) v1.push_back(i);
    //     std::vector<int>::iterator it = v1.begin();
    //     it++;
    //     it++;
    //     it++;
    //     std::vector<int>::iterator res = v1.insert(++it, 1, 999);
    //     std::cout << "🔰insert: " << *(res) << "\n";
    //     std::vector<int>::iterator it2 = v1.end();
    //     std::vector<int>::iterator res2 = v1.insert(it2, 1, 999);
    //     std::cout << "🔰insert: " << *(res2) << "\n";
    //     std::vector<int>::iterator it3 = v1.begin();
    //     it3++;
    //     it3++;
    //     it3++;
    //     std::vector<int>::iterator res3 = v1.insert(it3, 3, 999);
    //     std::cout << "🔰insert: " << *(res3) << "\n";
    //     std::vector<int>::iterator res4 = v1.insert(v1.begin(), 3, 999);
    //     std::cout << "🔰insert: " << *(res4) << "\n";
    //     print_info(v1);
    // }
    // {
    //     ft::vector<int> v1;
    //     for (int i = 1; i <= 7; i++) v1.push_back(i);
    //     ft::vector<int>::iterator it = v1.begin();
    //     it++;
    //     it++;
    //     it++;
    //     ft::vector<int>::iterator res = v1.insert(++it, 1, 999);
    //     std::cout << "🔰insert: " << *(res) << "\n";
    //     ft::vector<int>::iterator it2 = v1.end();
    //     ft::vector<int>::iterator res2 = v1.insert(it2, 1, 999);
    //     std::cout << "🔰insert: " << *(res2) << "\n";
    //     ft::vector<int>::iterator it3 = v1.begin();
    //     it3++;
    //     it3++;
    //     it3++;
    //     ft::vector<int>::iterator res3 = v1.insert(it3, 3, 999);
    //     std::cout << "🔰insert: " << *(res3) << "\n";
    //     ft::vector<int>::iterator res4 = v1.insert(v1.begin(), 3, 999);
    //     std::cout << "🔰insert: " << *(res4) << "\n";
    //     print_info(v1);
    // }
    // // ******************** Test insert(pos, first, last) ***************************
    // {
    //     std::vector<int> v1;
    //     std::vector<int> v2(3, 5);
    //     for (int i = 1; i <= 7; i++) v1.push_back(i);
    //     std::cout << "Capacity before: " << v2.capacity() << std::endl;
    //     std::vector<int>::iterator it = v1.begin();
    //     std::vector<int>::iterator it_end = v1.end();
    //     v2.insert(v2.begin(), it, it_end);
    //     print_info(v2);
    // }
    // {
    //     ft::vector<int> v1;
    //     ft::vector<int> v2(3, 5);
    //     for (int i = 1; i <= 7; i++) v1.push_back(i);
    //     std::cout << "Capacity before: " << v2.capacity() << std::endl;
    //     ft::vector<int>::iterator it = v1.begin();
    //     ft::vector<int>::iterator it_end = v1.end();
    //     v2.insert(v2.begin(), it, it_end);
    //     print_info(v2);
    // }

    // {
    //     std::vector<int> v1;
    //     std::vector<int> v2(25, 5);
    //     for (int i = 1; i <= 15; i++) v1.push_back(i);
    //     std::cout << "Cap: " << v2.capacity() << "\n";
    //     std::vector<int>::iterator it = v1.begin();
    //     std::vector<int>::iterator it_end = v1.end();
    //     v2.insert(v2.begin(), it, it_end);
    //     print_info(v2);
    // }

    // {
    //     ft::vector<int> v1;
    //     ft::vector<int> v2(25, 5);
    //     for (int i = 1; i <= 15; i++) v1.push_back(i);
    //     std::cout << "Cap: " << v2.capacity() << "\n";
    //     ft::vector<int>::iterator it = v1.begin();
    //     ft::vector<int>::iterator it_end = v1.end();
    //     v2.insert(v2.begin(), it, it_end);
    //     print_info(v2);
    // }

    // {
    //     std::vector<int> v1;
    //     std::vector<int> v2(23, 5);
    //     for (int i = 1; i <= 15; i++) v1.push_back(i);
    //     std::cout << "Cap: " << v2.capacity() << "\n";
    //     std::vector<int>::iterator it = v1.begin();
    //     std::vector<int>::iterator it_end = v1.end();
    //     v2.insert(v2.begin(), it, it_end);
    //     print_info(v2);
    // }

    // {
    //     ft::vector<int> v1;
    //     ft::vector<int> v2(23, 5);
    //     for (int i = 1; i <= 15; i++) v1.push_back(i);
    //     std::cout << "Cap: " << v2.capacity() << "\n";
    //     ft::vector<int>::iterator it = v1.begin();
    //     ft::vector<int>::iterator it_end = v1.end();
    //     v2.insert(v2.begin(), it, it_end);
    //     print_info(v2);
    // }
    // ---------------------------------------------------------------------------------------------------------
    // ---------------------------------------------------------------------------------------------------------
    // // ******************** Test relational operators ***************************
    // std::cout << "STL:\n";
    // {
    //     std::vector<int> v1;
    //     for (int i = 1; i <= 15; i++) v1.push_back(i);
    //     std::vector<int> v2;
    //     for (int i = 1; i <= 15; i++) v2.push_back(i);
    //     if (v1 == v2)
    //         std::cout << "✅Equal\n";
    //     else
    //         std::cout << "❌Not equal\n";
    //     v1.push_back(1);
    //     if (v1 > v2)
    //         std::cout << "✅Bigger\n";
    //     else
    //         std::cout << "❌Not bigger\n";
    //     v1.push_back(999);
    //     if (v1 >= v2)
    //         std::cout << "✅Bigger or equal\n";
    //     else
    //         std::cout << "❌Not bigger\n";
    //     v2.push_back(999);
    //     v1.push_back(10);
    //     if (v1 < v2)
    //         std::cout << "✅Less\n";
    //     else
    //         std::cout << "❌Not less\n";
    //     v1.push_back(999);
    //     if (v1 <= v2)
    //         std::cout << "✅Less or equal\n";
    //     else
    //         std::cout << "❌Not less\n";
    // }
    // std::cout << "\nFT:\n";
    // {
    //     ft::vector<int> v1;
    //     for (int i = 1; i <= 15; i++) v1.push_back(i);
    //     ft::vector<int> v2;
    //     for (int i = 1; i <= 15; i++) v2.push_back(i);
    //     if (v1 == v2)
    //         std::cout << "✅Equal\n";
    //     else
    //         std::cout << "❌Not equal\n";
    //     v1.push_back(1);
    //     if (v1 > v2)
    //         std::cout << "✅Bigger\n";
    //     else
    //         std::cout << "❌Not bigger\n";
    //     v1.push_back(999);
    //     if (v1 >= v2)
    //         std::cout << "✅Bigger or equal\n";
    //     else
    //         std::cout << "❌Not bigger\n";
    //     v2.push_back(999);
    //     v1.push_back(10);
    //     if (v1 < v2)
    //         std::cout << "✅Less\n";
    //     else
    //         std::cout << "❌Not less\n";
    //     v1.push_back(999);
    //     if (v1 <= v2)
    //         std::cout << "✅Less or equal\n";
    //     else
    //         std::cout << "❌Not less\n";
    // }
    // ---------------------------------------------------------------------------------------------------------
    // ---------------------------------------------------------------------------------------------------------
    // // ******************** Test resize() ***************************
    // std::cout << "STL:\n";
    // {
    //     std::vector<int> v1;
    //     for (int i = 1; i <= 5; i++) v1.push_back(i);
    //     v1.resize(3, 99);
    //     print_info(v1);
    // }
    // std::cout << "FT:\n";
    // {
    //     ft::vector<int> v1;
    //     for (int i = 1; i <= 5; i++) v1.push_back(i);
    //     v1.resize(3, 99);
    //     print_info(v1);
    // }

    // std::cout << "STL:\n";
    // {
    //     std::vector<int> v1;
    //     for (int i = 1; i <= 5; i++) v1.push_back(i);
    //     v1.resize(10, 999);
    //     print_info(v1);
    // }
    // std::cout << "FT:\n";
    // {
    //     ft::vector<int> v1;
    //     for (int i = 1; i <= 5; i++) v1.push_back(i);
    //     v1.resize(10, 999);
    //     print_info(v1);
    // }


    // {
    //     std::vector<int> v1(10, 5);
    //     std::vector<int> v2;
    //     v2.assign(v1.begin(), v1.end());
    //     // print_info(v2);
    //     std::vector<int> v3(v1.begin(), v1.end());
    //     print_info(v3);
    // }

    // {
    //     ft::vector<int> v1(10, 5);
    //     ft::vector<int> v2;
    //     v2.assign(v1.begin(), v1.end());
    //     // print_info(v2);
    // }


// // FT::MAP!
	// {
	// 	ft::map<int, int> m1;
	// 	m1.insert(ft::pair<int, int>(15, 999));
	// 	m1.insert(ft::pair<int, int>(20, 999));
	// 	m1.insert(ft::pair<int, int>(25, 999));
	// 	ft::map<int, int> m(m1.begin(), m1.end());
	// 	ft::map<int, int>::iterator it = m.begin();
	// 	it->second = 150;
	// 	std::cout << m1.begin()->second << "\n";
	// }
	// {
	// 	std::map<int, int> m1;
	// 	m1.insert(std::pair<int, int>(15, 999));
	// 	m1.insert(std::pair<int, int>(20, 999));
	// 	m1.insert(std::pair<int, int>(25, 999));
	// 	std::map<int, int> m(m1.begin(), m1.end());
	// 	std::map<int, int>::iterator it = m.begin();
	// 	it->second = 150;
	// 	std::cout << m1.begin()->second << "\n";
	// }



// MAP INSERT(val)
	// std::cout << "\n";
	// {
	// 	ft::map<int, int> m1;
	// 	m1.insert(ft::pair<int, int>(15, 1));
	// 	m1.insert(ft::pair<int, int>(10, 2));
	// 	m1.insert(ft::pair<int, int>(5, 3));
	// 	m1.insert(ft::pair<int, int>(2, 4));
	// 	m1.insert(ft::pair<int, int>(7, 5));
	// 	m1.insert(ft::pair<int, int>(3, 6));
	// 	m1.insert(ft::pair<int, int>(3, 7));
	// 	m1.insert(ft::pair<int, int>(3, 8));
	// 	m1.insert(ft::pair<int, int>(3, 9));
	// 	ft::pair<ft::map<int, int>::iterator, bool> it = m1.insert(ft::pair<int, int>(10, 99));

	// 	std::cout << "ITER FT:" << "\nit.second = " << it.second << std::endl;
	// 	std::cout << "it.first->first = " << it.first->first << std::endl;
	// 	std::cout << "it.first->second = " << it.first->second << std::endl;
	// 	for (ft::map<int, int>::reverse_iterator it = m1.rbegin(); it != m1.rend(); it++) {
	// 		std::cout << it->first << " ";
	// 	}
	// 	std::cout << "\n";
	// }
	// std::cout << "\n";
	// {
	// 	std::map<int, int> m1;
	// 	m1.insert(std::pair<int, int>(15, 1));
	// 	m1.insert(std::pair<int, int>(10, 2));
	// 	m1.insert(std::pair<int, int>(5, 3));
	// 	m1.insert(std::pair<int, int>(2, 4));
	// 	m1.insert(std::pair<int, int>(7, 5));
	// 	m1.insert(std::pair<int, int>(3, 6));
	// 	m1.insert(std::pair<int, int>(3, 7));
	// 	m1.insert(std::pair<int, int>(3, 8));
	// 	m1.insert(std::pair<int, int>(3, 9));
	// 	std::pair<std::map<int, int>::iterator, bool> it = m1.insert(std::pair<int, int>(10, 99));

	// 	std::cout << "ITER STL:" << "\nit.second = " << it.second << std::endl;
	// 	std::cout << "it.first->first = " << it.first->first << std::endl;
	// 	std::cout << "it.first->second = " << it.first->second << std::endl;
	// 	for (std::map<int, int>::reverse_iterator it = m1.rbegin(); it != m1.rend(); it++) {
	// 		std::cout << it->first << " ";
	// 	}
	// 	std::cout << "\n";
	// }

// MAP INSERT(pos, val)
    // std::cout << "\n";
	// {
	// 	std::map<int, int> m1;
	// 	m1.insert(std::pair<int, int>(15, 1));
	// 	m1.insert(std::pair<int, int>(10, 2));
	// 	m1.insert(std::pair<int, int>(17, 2));
	// 	m1.insert(std::pair<int, int>(7, 2));
	// 	m1.insert(std::pair<int, int>(5, 3));
	// 	m1.insert(std::pair<int, int>(2, 4));
	// 	m1.insert(std::pair<int, int>(1, 4));
	// 	m1.insert(std::pair<int, int>(7, 5));
	// 	m1.insert(std::pair<int, int>(6, 5));
	// 	m1.insert(std::pair<int, int>(3, 6));
	// 	m1.insert(std::pair<int, int>(-2, 6));
	// 	m1.insert(std::pair<int, int>(99, 6));
	// 	std::pair<std::map<int, int>::iterator, bool> it = m1.insert(std::pair<int, int>(0, 99));
	// 	(void)it;
	// 	m1.insert(m1.begin(), std::pair<int, int>(3, 99));
	// 	std::cout << "\n";
	// 	for (std::map<int, int>::iterator i = m1.begin(); i != m1.end(); i++) {
	// 		std::cout << i->first << " ";
	// 	}
	// 	std::cout << "\n";
	// }
	// std::cout << "\n";
	// std::cout << "\n";
	// {
	// 	ft::map<int, int> m1;
	// 	m1.insert(ft::pair<int, int>(15, 1));
	// 	m1.insert(ft::pair<int, int>(10, 2));
	// 	m1.insert(ft::pair<int, int>(17, 2));
	// 	m1.insert(ft::pair<int, int>(7, 2));
	// 	m1.insert(ft::pair<int, int>(5, 3));
	// 	m1.insert(ft::pair<int, int>(2, 4));
	// 	m1.insert(ft::pair<int, int>(1, 4));
	// 	m1.insert(ft::pair<int, int>(7, 5));
	// 	m1.insert(ft::pair<int, int>(6, 5));
	// 	m1.insert(ft::pair<int, int>(3, 6));
	// 	m1.insert(ft::pair<int, int>(-2, 6));
	// 	m1.insert(ft::pair<int, int>(99, 6));
	// 	ft::pair<ft::map<int, int>::iterator, bool> it = m1.insert(ft::pair<int, int>(0, 99));
	// 	(void)it;
	// 	m1.insert(m1.begin(), ft::pair<int, int>(3, 99));
	// 	std::cout << "\n";
	// 	for (ft::map<int, int>::iterator i = m1.begin(); i != m1.end(); i++) {
	// 		std::cout << i->first << " ";
	// 	}
	// 	std::cout << "\n";
	// }
	// std::cout << "\n";



// MAP erase(position)
	// std::cout << "\n";
	// {
	// 	std::map<int, int> m1;
	// 	m1.insert(std::pair<int, int>(15, 1));
	// 	m1.insert(std::pair<int, int>(10, 2));
	// 	m1.insert(std::pair<int, int>(17, 2));
	// 	m1.insert(std::pair<int, int>(7, 2));
	// 	m1.insert(std::pair<int, int>(5, 3));
	// 	m1.insert(std::pair<int, int>(2, 4));
	// 	m1.insert(std::pair<int, int>(1, 4));
	// 	m1.insert(std::pair<int, int>(7, 5));
	// 	m1.insert(std::pair<int, int>(6, 5));
	// 	m1.insert(std::pair<int, int>(3, 6));
	// 	m1.insert(std::pair<int, int>(-2, 6));
	// 	m1.insert(std::pair<int, int>(99, 6));
	// 	std::map<int, int>::iterator it = m1.begin();
	// 	it++;
	// 	it++;
	// 	it++;
	// 	m1.erase(it);
	// 	for (std::map<int, int>::iterator i = m1.begin(); i != m1.end(); i++) {
	// 		std::cout << i->first << " ";
	// 	}
	// 	std::cout << "\n";
	// }
	// std::cout << "\n";
	// {
	// 	ft::map<int, int> m1;
	// 	m1.insert(ft::pair<int, int>(15, 1));
	// 	m1.insert(ft::pair<int, int>(10, 2));
	// 	m1.insert(ft::pair<int, int>(17, 2));
	// 	m1.insert(ft::pair<int, int>(7, 2));
	// 	m1.insert(ft::pair<int, int>(5, 3));
	// 	m1.insert(ft::pair<int, int>(2, 4));
	// 	m1.insert(ft::pair<int, int>(1, 4));
	// 	m1.insert(ft::pair<int, int>(7, 5));
	// 	m1.insert(ft::pair<int, int>(6, 5));
	// 	m1.insert(ft::pair<int, int>(3, 6));
	// 	m1.insert(ft::pair<int, int>(-2, 6));
	// 	m1.insert(ft::pair<int, int>(99, 6));
	// 	ft::map<int, int>::iterator it = m1.begin();
	// 	it++;
	// 	it++;
	// 	it++;
	// 	m1.erase(it);
	// 	for (ft::map<int, int>::iterator i = m1.begin(); i != m1.end(); i++) {
	// 		std::cout << i->first << " ";
	// 	}
	// 	std::cout << "\n";
	// }

// MAP erase(first, last) - range
	// std::cout << "\n";
	// {
	// 	std::map<int, int> m1;
	// 	m1.insert(std::pair<int, int>(15, 1));
	// 	m1.insert(std::pair<int, int>(10, 2));
	// 	m1.insert(std::pair<int, int>(17, 2));
	// 	m1.insert(std::pair<int, int>(7, 2));
	// 	m1.insert(std::pair<int, int>(5, 3));
	// 	m1.insert(std::pair<int, int>(2, 4));
	// 	m1.insert(std::pair<int, int>(1, 4));
	// 	m1.insert(std::pair<int, int>(7, 5));
	// 	m1.insert(std::pair<int, int>(6, 5));
	// 	m1.insert(std::pair<int, int>(3, 6));
	// 	m1.insert(std::pair<int, int>(-2, 6));
	// 	m1.insert(std::pair<int, int>(99, 6));
	// 	std::map<int, int>::iterator it = m1.begin();
	// 	std::map<int, int>::iterator it_end = m1.begin();
	// 	it++;
	// 	it++;
	// 	it++;
	// 	it_end++;
	// 	it_end++;
	// 	it_end++;
	// 	it_end++;
	// 	it_end++;
	// 	it_end++;
	// 	it_end++;
	// 	it_end++;
	// 	it_end++;
	// 	it_end++;
	// 	m1.erase(it, it_end);
	// 	for (std::map<int, int>::iterator i = m1.begin(); i != m1.end(); i++) {
	// 		std::cout << i->first << " ";
	// 	}
		
	// 	std::cout << "\n";
	// }
	// std::cout << "\n";
	// {
	// 	ft::map<int, int> m1;
	// 	m1.insert(ft::pair<int, int>(15, 1));
	// 	m1.insert(ft::pair<int, int>(10, 2));
	// 	m1.insert(ft::pair<int, int>(17, 2));
	// 	m1.insert(ft::pair<int, int>(7, 2));
	// 	m1.insert(ft::pair<int, int>(5, 3));
	// 	m1.insert(ft::pair<int, int>(2, 4));
	// 	m1.insert(ft::pair<int, int>(1, 4));
	// 	m1.insert(ft::pair<int, int>(7, 5));
	// 	m1.insert(ft::pair<int, int>(6, 5));
	// 	m1.insert(ft::pair<int, int>(3, 6));
	// 	m1.insert(ft::pair<int, int>(-2, 6));
	// 	m1.insert(ft::pair<int, int>(99, 6));
	// 	ft::map<int, int>::iterator it = m1.begin();
	// 	ft::map<int, int>::iterator it_end = m1.begin();
	// 	it++;
	// 	it++;
	// 	it++;
	// 	it_end++;
	// 	it_end++;
	// 	it_end++;
	// 	it_end++;
	// 	it_end++;
	// 	it_end++;
	// 	it_end++;
	// 	it_end++;
	// 	it_end++;
	// 	it_end++;
	// 	m1.erase(it, it_end);
	// 	for (ft::map<int, int>::iterator i = m1.begin(); i != m1.end(); i++) {
	// 		std::cout << i->first << " ";
	// 	}
		
	// 	std::cout << "\n";
	// }

// FIND
	// {
	// 	ft::map<int, int> m1;
	// 	m1.insert(ft::pair<int, int>(15, 1));
	// 	m1.insert(ft::pair<int, int>(10, 2));
	// 	m1.insert(ft::pair<int, int>(17, 2));
	// 	m1.insert(ft::pair<int, int>(7, 2));
	// 	m1.insert(ft::pair<int, int>(5, 3));
	// 	m1.insert(ft::pair<int, int>(2, 4));
	// 	m1.insert(ft::pair<int, int>(1, 4));
	// 	m1.insert(ft::pair<int, int>(7, 5));
	// 	m1.insert(ft::pair<int, int>(6, 5));
	// 	m1.insert(ft::pair<int, int>(3, 6));
	// 	m1.insert(ft::pair<int, int>(-2, 6));
	// 	m1.insert(ft::pair<int, int>(99, 6));
	// 	ft::map<int, int>::iterator it = m1.find(-99);
	// 	if (it != m1.end())
	// 		std::cout << it->first << " : " << it->second << "\n";
	// 	else
	// 		std::cout << "Not found\n";
	// }


// SWAP
	// {
	// 	ft::map<char,int> foo,bar;
	// 	foo['x']=100;
	// 	foo['y']=200;
	// 	bar['a']=11;
	// 	bar['b']=22;
	// 	bar['c']=33;
	// 	ft::map<char,int>::iterator test_it = bar.begin();
	// 	foo.swap(bar);
	// 	std::cout << "it = " << test_it->first << test_it->second << "\n";
	// }
	// std::cout << "\n";
	// {
	// 	std::map<char,int> foo,bar;
	// 	foo['x']=100;
	// 	foo['y']=200;
	// 	bar['a']=11;
	// 	bar['b']=22;
	// 	bar['c']=33;
	// 	std::map<char,int>::iterator test_it = bar.begin();
	// 	foo.swap(bar);
	// 	std::cout << "it = " << test_it->first << test_it->second << "\n";
	// }

// CLEAR
	// {
	// 	ft::map<int, int> m;
	// 	m.insert(ft::make_pair<int, int>(1, 1));
	// 	m.insert(ft::make_pair<int, int>(413, 1));
	// 	m.insert(ft::make_pair<int, int>(12, 1));
	// 	m.insert(ft::make_pair<int, int>(13, 1));
	// 	m.insert(ft::make_pair<int, int>(19, 1));
	// 	m.insert(ft::make_pair<int, int>(4, 1));
	// 	m.insert(ft::make_pair<int, int>(2, 1));
	// 	std::cout << "Before size: " << m.size() << "\n";
	// 	std::cout << "Before map: ";
	// 	for (ft::map<int, int>::iterator i = m.begin(); i != m.end(); i++)
	// 		std::cout << i->first << " ";
	// 	std::cout << "\n";
	// 	std::cout << "Clear\n";
	// 	m.clear();
	// 	std::cout << "After size: " << m.size() << "\n";
	// 	std::cout << "After map: ";
	// 	for (ft::map<int, int>::iterator i = m.begin(); i != m.end(); i++)
	// 		std::cout << i->first << " ";
	// }

// value_compare
	// std::cout << "\n";
	// {
	// 	std::map<char,int> mymap;
	// 	mymap['x']=1001;
	// 	mymap['y']=2002;
	// 	mymap['z']=3003;
	// 	std::cout << "mymap contains:\n";
	// 	std::pair<char,int> highest = *mymap.rbegin();
	// 	std::map<char,int>::iterator it = mymap.begin();
	// 	do {
	// 	std::cout << it->first << " => " << it->second << '\n';
	// 	} while ( mymap.value_comp()(*it++, highest) );
	// }
	// std::cout << "\n";
	// std::cout << "\n";
	// {
	// 	ft::map<char,int> mymap;
	// 	mymap['x']=1001;
	// 	mymap['y']=2002;
	// 	mymap['z']=3003;
	// 	std::cout << "mymap contains:\n";
	// 	ft::pair<char,int> highest = *mymap.rbegin();
	// 	(void)highest;
	// 	ft::map<char,int>::iterator it = mymap.begin();
	// 	do {
	// 	std::cout << it->first << " => " << it->second << '\n';
	// 	} while ( mymap.value_comp()(*it++, highest) );
	// }
	// std::cout << "\n";


// COUNT
	// {
	// 	ft::map<int, int> m;
	// 	m.insert(ft::make_pair<int, int>(1, 1));
	// 	m.insert(ft::make_pair<int, int>(413, 1));
	// 	m.insert(ft::make_pair<int, int>(12, 1));
	// 	m.insert(ft::make_pair<int, int>(13, 1));
	// 	m.insert(ft::make_pair<int, int>(19, 1));
	// 	m.insert(ft::make_pair<int, int>(4, 1));
	// 	m.insert(ft::make_pair<int, int>(2, 1));
	// 	std::cout << "count: " << m.count(413) << "\n";
	// }

// LOWER_BOUND
	// int k = 11;
	// {
	// 	std::map<int, int> m;
	// 	m.insert(std::make_pair<int, int>(10, 1));
	// 	m.insert(std::make_pair<int, int>(20, 1));
	// 	m.insert(std::make_pair<int, int>(30, 1));
	// 	m.insert(std::make_pair<int, int>(40, 1));
	// 	m.insert(std::make_pair<int, int>(50, 1));
	// 	std::cout << "count: " << m.lower_bound(k)->first << "\n";
	// }
	// std::cout << "\n";
	// {
	// 	ft::map<int, int> m;
	// 	m.insert(ft::make_pair<int, int>(10, 1));
	// 	m.insert(ft::make_pair<int, int>(20, 1));
	// 	m.insert(ft::make_pair<int, int>(30, 1));
	// 	m.insert(ft::make_pair<int, int>(40, 1));
	// 	m.insert(ft::make_pair<int, int>(50, 1));
	// 	std::cout << "count: " << m.lower_bound(k)->first << "\n";
	// }
	// std::cout << "\n";

// UPPER_BOUND
	// int k = 20;
	// {
	// 	std::map<int, int> m;
	// 	m.insert(std::make_pair<int, int>(10, 1));
	// 	m.insert(std::make_pair<int, int>(20, 1));
	// 	m.insert(std::make_pair<int, int>(30, 1));
	// 	m.insert(std::make_pair<int, int>(40, 1));
	// 	m.insert(std::make_pair<int, int>(50, 1));
	// 	const std::map<int, int> m1(m);
	// 	std::cout << "Upper bound STL: " << m.upper_bound(k)->first << "\n";
	// }
	// {
	// 	ft::map<int, int> m;
	// 	m.insert(ft::make_pair<int, int>(10, 1));
	// 	m.insert(ft::make_pair<int, int>(20, 1));
	// 	m.insert(ft::make_pair<int, int>(30, 1));
	// 	m.insert(ft::make_pair<int, int>(40, 1));
	// 	m.insert(ft::make_pair<int, int>(50, 1));
	// 	const ft::map<int, int> m1(m);
	// 	std::cout << "Upper bound FT: " << m1.upper_bound(k)->first << "\n";
	// }