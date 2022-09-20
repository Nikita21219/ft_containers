#include "containers.h"

namespace ft {

    struct random_access_iterator_tag {};

    template <typename iterator>
    struct iterator_traits {
    typedef typename iterator::iterator_category iterator_category;
    typedef typename iterator::value_type        value_type;
    typedef typename iterator::difference_type   difference_type;
    typedef typename iterator::pointer           pointer;
    typedef typename iterator::reference         reference;
    typedef          difference_type             distance_type;
    };

    template <typename T>
    struct iterator_traits<T *> {
        typedef random_access_iterator_tag iterator_category;
        typedef T                          value_type;
        typedef ptrdiff_t                  distance_type;
        typedef T*                         pointer;
        typedef T&                         reference;
    };

    template< class T >
    struct iterator_traits<const T*> {
        typedef random_access_iterator_tag iterator_category;
        typedef T                          value_type;
        typedef ptrdiff_t                  distance_type;
        typedef const T*                   pointer;
        typedef const T&                   reference;
    };

    template<
        bool isConst,
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

        typedef typename std::conditional<isConst, const T*, T*>::type CondPtr;
        typedef typename std::conditional<isConst, const T&, T&>::type CondRef;

        iterator()                                                       {};
        iterator(CondPtr ptr): ptr(ptr)                                  {};
        CondRef operator*()                                              {return *ptr;};
        CondPtr operator->() const                                       {return ptr;}
        CondRef operator[](int idx)                                      {return *(ptr + idx);}
        bool operator==(const iterator &other) const                     {return ptr == other.ptr;}
        bool operator!=(const iterator &other) const                     {return !(*this == other);}
        friend bool operator>(const iterator& lhs, const iterator& rhs)  {return lhs.ptr > rhs.ptr;}
        friend bool operator<(const iterator& lhs, const iterator& rhs)  {return lhs.ptr < rhs.ptr;}
        friend bool operator>=(const iterator& lhs, const iterator& rhs) {return lhs.ptr >= rhs.ptr;}
        friend bool operator<=(const iterator& lhs, const iterator& rhs) {return lhs.ptr <= rhs.ptr;}

        iterator operator++() {
            ptr++;
            return *this;
        };

        iterator operator+=(int n) {
            ptr += n;
            return *this;
        };

        iterator operator-=(int n) {
            ptr -= n;
            return *this;
        };
        
        iterator operator+(int n) {
            ptr += n;
            return *this;
        };
        
        iterator operator-(int n) {
            ptr -= n;
            return *this;
        };

        iterator operator++(int) {
            iterator it = *this;
            ++(*this);
            return it;
        };
        
        iterator operator--() {
            ptr--;
            return *this;
        };

        iterator operator--(int) {
            iterator it = *this;
            --(*this);
            return it;
        };

    private:
        CondPtr ptr;
    };


    template <typename Iter>
    class reverse_iterator {
    public:
        typedef Iter iterator_type;
        typedef typename iterator_type::reference reference;
        typedef typename iterator_type::pointer pointer;
        typedef typename iterator_type::CondRef CondRef;
        typedef typename iterator_type::CondPtr CondPtr;

        reverse_iterator(Iter iter): iter(iter)                                          {}
        iterator_type base() const                                                       {return iter;}
        iterator_type operator->() const                                                 {return iter;}
        CondRef operator*()                                                              {return *iter;}
        CondRef operator[](int idx)                                                      {return *(iter + idx);}
        bool operator!=(const reverse_iterator &other) const                             {return !(*this == other);}
        bool operator==(const reverse_iterator &other) const                             {return this->iter == other.iter;}
        friend bool operator>(const reverse_iterator& lhs, const reverse_iterator& rhs)  {return lhs.ptr > rhs.ptr;}
        friend bool operator<(const reverse_iterator& lhs, const reverse_iterator& rhs)  {return lhs.ptr < rhs.ptr;}
        friend bool operator>=(const reverse_iterator& lhs, const reverse_iterator& rhs) {return lhs.ptr >= rhs.ptr;}
        friend bool operator<=(const reverse_iterator& lhs, const reverse_iterator& rhs) {return lhs.ptr <= rhs.ptr;}

        reverse_iterator<iterator_type>& operator++() {
            iter--;
            return *this;
        }

        reverse_iterator<iterator_type>& operator--() {
            iter++;
            return *this;
        }

        reverse_iterator<iterator_type>& operator+=(int n) {
            iter -= n;
            return *this;
        };

        reverse_iterator<iterator_type>& operator-=(int n) {
            iter += n;
            return *this;
        };
        
        reverse_iterator<iterator_type>& operator+(int n) {
            iter -= n;
            return *this;
        };
        
        reverse_iterator<iterator_type>& operator-(int n) {
            iter += n;
            return *this;
        };

        reverse_iterator<iterator_type>& operator++(int) {
            reverse_iterator<iterator_type>& it = *this;
            iter--;
            return it;
        };

        reverse_iterator<iterator_type>& operator--(int) {
            reverse_iterator<iterator_type>& it = *this;
            iter++;
            return it;
        };

    private:
        iterator_type iter;
    };

}
