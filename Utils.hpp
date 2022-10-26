#include "containers.h"

#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft {
    template<class InputIt1, class InputIt2>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
    {
        for (; (first1 != last1) && (first2 != last2); ++first1, ++first2) {
            if (*first1 < *first2)
                return true;
            if (*first2 < *first1)
                return false;
        }
        return (first1 == last1) && (first2 != last2);
    }

    template<class InputIt1, class InputIt2, class Comp>
    bool lexicographical_compare_three_way(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Comp comp)
    {
        for (; (first1 != last1) && (first2 != last2); ++first1, ++first2) {
            if (comp(first1->first, first2->first) || comp(first1->second, first2->second))
                return true;
            if (comp(first2->first, first1->first) || comp(first2->second, first1->second))
                return false;
        }
        return (first1 == last1) && (first2 != last2);
    }

    // template<class I1, class I2, class Cmp>
    // bool lexicographical_compare_three_way(I1 f1, I1 l1, I2 f2, I2 l2, Cmp comp) {
    //     typedef decltype(comp(*f1, *f2)) ret_t;

    //     // static_assert(std::disjunction_v<
    //     //                 std::is_same<ret_t, std::strong_ordering>,
    //     //                 std::is_same<ret_t, std::weak_ordering>,
    //     //                 std::is_same<ret_t, std::partial_ordering>>,
    //     //             "The return type must be a comparison category type.");
    
    //     bool exhaust1 = (f1 == l1);
    //     bool exhaust2 = (f2 == l2);
    //     for (; !exhaust1 && !exhaust2; exhaust1 = (++f1 == l1), exhaust2 = (++f2 == l2))
    //         if (auto c = comp(*f1, *f2); c != 0)
    //             return c;
    
    //     return lhs < rhs ? std::weak_ordering::less :
    //         rhs < lhs ? std::weak_ordering::greater :
    //                     std::weak_ordering::equivalent
    // }

    template <bool Cond, typename T> struct enable_if {};
    template <typename T> struct enable_if<true, T> {typedef T type;};
    template <typename> struct is_integral_base : std::false_type {};
    template <> struct is_integral_base<bool> : std::true_type {};
    template <> struct is_integral_base<int> : std::true_type {};
    template <> struct is_integral_base<char> : std::true_type {};
    template <> struct is_integral_base<long> : std::true_type {};
    template <> struct is_integral_base<long long> : std::true_type {};
    template <> struct is_integral_base<char16_t> : std::true_type {};
    template <> struct is_integral_base<char32_t> : std::true_type {};
    template <> struct is_integral_base<wchar_t> : std::true_type {};
    template <> struct is_integral_base<short> : std::true_type {};
    template<typename T>
    struct is_integral : is_integral_base<typename std::remove_cv<T>::type> {};

    template <class T1, class T2>
    struct pair {
        typedef T1 first_type;
        typedef T2 second_type;

        pair() {};

        pair(const T1 &x, const T2 &y): first(x), second(y) {}

        template <class U1, class U2>
        pair(const pair<U1, U2> &p): first(p.first), second(p.second) {}
        
        first_type first;
        second_type second;
    };

    template <class T1, class T2>
    bool operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
    {return lhs.first > rhs.first;}

    template <class T1, class T2>
    bool operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
    {return lhs.first < rhs.first;}

    template <class T1, class T2>
    bool operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
    {return lhs.first <= rhs.first;}

    template <class T1, class T2>
    bool operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
    {return lhs.first >= rhs.first;}

    template <class T1, class T2>
    bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
    {return lhs.first == rhs.first;}

    template <class T1, class T2>
    bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
    {return lhs.first != rhs.first;}

    template <class T1, class T2>
    ft::pair<T1, T2> make_pair(T1 x, T2 y) {return ft::pair<T1, T2>(x, y);}

    template <typename T>
    struct BTreeNode {
        typedef typename T::first_type  Key;
        typedef typename T::second_type Val;
        typedef T pair_type;

        BTreeNode(const T &pair):
        isRed(false), data(pair), left(NULL), right(NULL), p(NULL) {}

        ~BTreeNode() {}

        bool isRed;
        T data;
        struct BTreeNode *left;
        struct BTreeNode *right;
        struct BTreeNode *p;
    };

    // template <typename T>
    // class SmarPtr {
    // public:
    //     SmarPtr(): ptr(NULL) {}
    //     SmarPtr(T *ptr): ptr(ptr) {}

    //     ~SmarPtr() {
    //         if (ptr)
    //             delete ptr;
    //     }

    //     T &operator*() {return *ptr;}

    // private:
    //     T *ptr;
    // };
}

#endif
