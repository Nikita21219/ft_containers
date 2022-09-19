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
        typedef random_access_iterator_tag  iterator_category;
        typedef T                           value_type;
        typedef ptrdiff_t                   distance_type;
        typedef T                           *pointer;
        typedef T&                          reference;
    };

    template<
        bool isConst,
        class Category,
        class T,
        class Distance = ptrdiff_t,
        class Pointer = T*,
        class Reference = T&
    > class iterator {
        typedef typename std::conditional<isConst, const T*, T*>::type CondPtr;
        typedef typename std::conditional<isConst, const T&, T&>::type CondRef;

    public:
        typedef Category    iterator_category;
        typedef T           value_type;
        typedef Distance    difference_type;
        typedef Pointer     pointer;
        typedef Reference   reference;

        iterator()                                   {};
        iterator(CondPtr ptr): ptr(ptr)      {};
        CondRef operator*()                  {return *ptr;};
        CondRef operator[](int idx)          {return *(ptr + idx);}
        bool operator==(const iterator &other) const {return ptr == other.ptr;}
        bool operator!=(const iterator &other) const {return !(*this == other);}
        CondPtr operator->() const           {return ptr;}

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


    template <bool isConst, typename Iter>
    class reverse_iterator {
        typedef typename std::conditional<isConst, const typename Iter::value_type*, typename Iter::value_type*>::type CondPtr;
        typedef typename std::conditional<isConst, const typename Iter::value_type&, typename Iter::value_type&>::type CondRef;
    public:
        typedef Iter iterator_type;

        reverse_iterator(Iter iter): iter(iter) {};
        iterator_type base() const {return iter;} //TODO realise base method
        CondRef operator*()                  {return *iter;}
        // CondRef operator[](int idx)          {return *(ptr + idx);}
        // bool operator==(const reverse_iterator &other) const {return ptr == other.ptr;}
        // bool operator!=(const reverse_iterator &other) const {return !(*this == other);}
        // CondPtr operator->() const           {return ptr;}

        // reverse_iterator<iterator_type>& operator++() {
        //     iter--;
        //     return *this;
        // }
        /*
        // reverse_iterator operator+=(int n) {
        //     ptr += n;
        //     return *this;
        // };

        // reverse_iterator operator-=(int n) {
        //     ptr -= n;
        //     return *this;
        // };
        
        // reverse_iterator operator+(int n) {
        //     ptr += n;
        //     return *this;
        // };
        
        // reverse_iterator operator-(int n) {
        //     ptr -= n;
        //     return *this;
        // };

        // reverse_iterator operator++(int) {
        //     reverse_iterator it = *this;
        //     ++(*this);
        //     return it;
        // };
        // reverse_iterator operator--() {
        //     ptr--;
        //     return *this;
        // };

        // reverse_iterator operator--(int) {
        //     reverse_iterator it = *this;
        //     --(*this);
        //     return it;
        // };
        */

    private:
        iterator_type iter;
    };

}
