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
    > class Iterator {
    public:
        typedef Category    iterator_category;
        typedef T           value_type;
        typedef Distance    difference_type;
        typedef Pointer     pointer;
        typedef Reference   reference;
        typedef typename std::conditional<isConst, const pointer, pointer>::type conditional_ptr;
        typedef typename std::conditional<isConst, const reference, reference>::type conditional_ref;

        Iterator(conditional_ptr ptr) {this->ptr = ptr;};
        conditional_ref operator*()                           {return *ptr;};
        /*        
        iterator& operator++() {
            ptr++;
            return *this;
        };
        
        iterator& operator+=(int n) {
            ptr += n;
            return *this;
        };
        
        iterator& operator-=(int n) {
            ptr -= n;
            return *this;
        };
        
        iterator& operator+(int n) {
            ptr += n;
            return *this;
        };
        
        iterator& operator-(int n) {
            ptr -= n;
            return *this;
        };

        iterator operator++(int) {
            iterator it = *this;
            ++(*this);
            return it;
        };
        
        iterator& operator--() {
            ptr--;
            return *this;
        };

        iterator operator--(int) {
            iterator it = *this;
            --(*this);
            return it;
        };

        reference operator[](int idx)                   {return *(ptr + idx);}
        pointer operator->()                            {return ptr;}
        bool operator ==(const iterator &other) const   {return ptr == other.ptr;}
        bool operator !=(const iterator &other) const   {return !(*this == other);}
        */

    private:
        conditional_ptr ptr;
    };
}
