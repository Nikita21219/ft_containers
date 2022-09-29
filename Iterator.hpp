#include "containers.h"

namespace ft {

    struct input_iterator_tag {};
    struct random_access_iterator_tag {};

    template <typename iterator>
    struct iterator_traits {
    typedef typename iterator::iterator_category iterator_category;
    typedef typename iterator::value_type        value_type;
    typedef typename iterator::difference_type   difference_type;
    typedef typename iterator::pointer           pointer;
    typedef typename iterator::reference         reference;
    // typedef          difference_type             distance_type;
    };

    template <typename T>
    struct iterator_traits<T*> {
        typedef std::random_access_iterator_tag iterator_category;
        typedef T                          value_type;
        typedef ptrdiff_t                  difference_type;
        typedef T*                         pointer;
        typedef T&                         reference;
    };

    template<typename T>
    struct iterator_traits<const T*> {
        typedef std::random_access_iterator_tag iterator_category;
        typedef ptrdiff_t                  difference_type;
        typedef const T                    value_type;
        typedef const T*                   pointer;
        typedef const T&                   reference;
    };

    template<
        class Category,
        class T,
        class Distance = ptrdiff_t,
        class Pointer = T*,
        class Reference = T&
    > class iterator {
    public:
        typedef Category    iterator_category;
        typedef T           value_type;
        typedef Distance    difference_type;
        typedef Pointer     pointer;
        typedef Reference   reference;
    };

    template<typename T>
    class RandAccessIt {
    //TODO const_iter = iter
    //TODO iter = const_iter
    public:
        typedef typename ft::iterator<std::random_access_iterator_tag, T> iterator;
        typedef typename iterator::value_type                 value_type;
        typedef typename iterator::iterator_category          iterator_category;
        typedef typename iterator::difference_type            difference_type;
        typedef typename iterator::pointer                    pointer;
        typedef typename iterator::reference                  reference;

        RandAccessIt()                                                       {};
        RandAccessIt(pointer ptr): ptr(ptr)                                  {};
        reference operator*()                                              {return *ptr;};
        pointer operator->() const                                       {return ptr;}
        reference operator[](int idx)                                      {return *(ptr + idx);}
        bool operator==(const RandAccessIt &other) const                     {return ptr == other.ptr;}
        bool operator!=(const RandAccessIt &other) const                     {return !(*this == other);}
        friend bool operator>(const RandAccessIt& lhs, const RandAccessIt& rhs)  {return lhs.ptr > rhs.ptr;}
        friend bool operator<(const RandAccessIt& lhs, const RandAccessIt& rhs)  {return lhs.ptr < rhs.ptr;}
        friend bool operator>=(const RandAccessIt& lhs, const RandAccessIt& rhs) {return lhs.ptr >= rhs.ptr;}
        friend bool operator<=(const RandAccessIt& lhs, const RandAccessIt& rhs) {return lhs.ptr <= rhs.ptr;}
        const pointer& base() const {return ptr;}

        RandAccessIt operator++() {
            ptr++;
            return *this;
        };

        RandAccessIt operator+=(int n) {
            ptr += n;
            return *this;
        };

        RandAccessIt operator-=(int n) {
            ptr -= n;
            return *this;
        };
        
        RandAccessIt operator+(int n) {
            ptr += n;
            return *this;
        };
        
        RandAccessIt operator-(int n) {
            ptr -= n;
            return *this;
        };
        
        difference_type operator-(RandAccessIt it) {
            return ptr - it.ptr;
        };

        RandAccessIt operator++(int) {
            RandAccessIt it = *this;
            ++(*this);
            return it;
        };
        
        RandAccessIt operator--() {
            ptr--;
            return *this;
        };

        RandAccessIt operator--(int) {
            RandAccessIt it = *this;
            --(*this);
            return it;
        };

    private:
        pointer ptr;
    };

    template <typename Iter> // TODO inheritance typedefs from general iterator
    class ReverseRandAccessIt {
    public:
        typedef Iter iterator_type;
        typedef typename iterator_type::reference reference;
        typedef typename iterator_type::pointer pointer;
        typedef typename iterator_type::difference_type difference_type;

        ReverseRandAccessIt(Iter iter): iter(iter)                                          {}
        iterator_type base() const                                                       {return iter;}
        iterator_type operator->() const                                                 {return iter;}
        reference operator*()                                                              {return *iter;}
        reference operator[](int idx)                                                      {return *(iter + idx);}
        bool operator!=(const ReverseRandAccessIt &other) const                             {return !(*this == other);}
        bool operator==(const ReverseRandAccessIt &other) const                             {return this->iter == other.iter;}
        friend bool operator>(const ReverseRandAccessIt& lhs, const ReverseRandAccessIt& rhs)  {return lhs.ptr > rhs.ptr;}
        friend bool operator<(const ReverseRandAccessIt& lhs, const ReverseRandAccessIt& rhs)  {return lhs.ptr < rhs.ptr;}
        friend bool operator>=(const ReverseRandAccessIt& lhs, const ReverseRandAccessIt& rhs) {return lhs.ptr >= rhs.ptr;}
        friend bool operator<=(const ReverseRandAccessIt& lhs, const ReverseRandAccessIt& rhs) {return lhs.ptr <= rhs.ptr;}

        ReverseRandAccessIt<iterator_type>& operator++() {
            iter--;
            return *this;
        }

        ReverseRandAccessIt<iterator_type>& operator--() {
            iter++;
            return *this;
        }

        ReverseRandAccessIt<iterator_type>& operator+=(int n) {
            iter -= n;
            return *this;
        };

        ReverseRandAccessIt<iterator_type>& operator-=(int n) {
            iter += n;
            return *this;
        };
        
        ReverseRandAccessIt<iterator_type>& operator+(int n) {
            iter -= n;
            return *this;
        };
        
        ReverseRandAccessIt<iterator_type>& operator-(int n) {
            iter += n;
            return *this;
        };

        ReverseRandAccessIt<iterator_type>& operator++(int) {
            ReverseRandAccessIt<iterator_type>& it = *this;
            iter--;
            return it;
        };

        ReverseRandAccessIt<iterator_type>& operator--(int) {
            ReverseRandAccessIt<iterator_type>& it = *this;
            iter++;
            return it;
        };

        //TODO need to realize operator-(iterator). reverse_iter1 - reverse_iter2

    private:
        iterator_type iter;
    };

    template<class InputIt1, class InputIt2>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
    {
        for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2) {
            if (*first1 < *first2)
                return true;
            if (*first2 < *first1)
                return false;
        }
        return (first1 == last1) && (first2 != last2);
    }

    template <bool Cond, typename T>
    struct enable_if {};

    template <typename T>
    struct enable_if<true, T> {
        typedef T type;
    };

    template <typename>
    struct is_integral_base : std::false_type {};

    template <>
    struct is_integral_base<bool> : std::true_type {};

    template <>
    struct is_integral_base<int> : std::true_type {};

    template <>
    struct is_integral_base<char> : std::true_type {};
    
    template <>
    struct is_integral_base<long> : std::true_type {};
    
    template <>
    struct is_integral_base<long long> : std::true_type {};
    
    template <>
    struct is_integral_base<char16_t> : std::true_type {};
    
    template <>
    struct is_integral_base<char32_t> : std::true_type {};
    
    template <>
    struct is_integral_base<wchar_t> : std::true_type {};
    
    template <>
    struct is_integral_base<short> : std::true_type {};
    
    template<typename T>
    struct is_integral : is_integral_base<typename std::remove_cv<T>::type> {};
}
