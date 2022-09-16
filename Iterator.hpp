#include "containers.h"

namespace ft {
    template <typename iterator>
    struct iterator_traits {
    typedef typename iterator::iterator_category iterator_category;
    typedef typename iterator::value_type        value_type;
    typedef typename iterator::difference_type   difference_type;
    typedef typename iterator::pointer           pointer;
    typedef typename iterator::reference         reference;
    typedef          difference_type             distance_type;
    };

    struct random_access_iterator {};

    template <typename T>
    struct iterator_traits<T *> {
        typedef random_access_iterator      iterator_category;
        typedef T                           value_type;
        typedef ptrdiff_t                   distance_type;
        typedef T                           *pointer;
        typedef T&                          reference;
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

        iterator(value_type *ptr = NULL) {this->ptr = ptr;};
        ~iterator() {};

        reference operator *() {return *ptr;};
        
        iterator& operator ++() {
            ptr++;
            return *this;
        };
        
        iterator operator ++(int) {
            iterator it = *this;
            ++(*this);
            return it;
        };

    private:
        pointer ptr;
    };
}