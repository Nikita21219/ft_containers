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
        typedef random_access_iterator_tag iterator_category;
        typedef T                          value_type;
        typedef ptrdiff_t                  difference_type;
        typedef T*                         pointer;
        typedef T&                         reference;
    };

    template<typename T>
    struct iterator_traits<const T*> {
        typedef random_access_iterator_tag iterator_category;
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
    public:
        typedef typename ft::iterator<ft::random_access_iterator_tag, T> iterator;
        typedef typename iterator_traits<T*>::value_type                 value_type;
        typedef typename iterator_traits<T*>::iterator_category          iterator_category;
        typedef typename iterator_traits<T*>::difference_type            difference_type;
        typedef typename iterator_traits<T*>::pointer                    pointer;
        typedef typename iterator_traits<T*>::reference                  reference;

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

    template<class It>
    typename ft::iterator_traits<It>::difference_type distance_helper(It first, It last, ft::random_access_iterator_tag) {
        return last - first;
    }

    template<class It>
    typename ft::iterator_traits<It>::difference_type distance_helper(It first, It last, ft::input_iterator_tag) {
        typename ft::iterator_traits<It>::difference_type count = 0;
        while (first++ != last++)
            count++;
        return count;
    }

    template<class It>
    typename ft::iterator_traits<It>::difference_type distance(It first, It last) {
        return distance_helper(first, last, typename ft::iterator_traits<It>::iterator_category());
    }
}
