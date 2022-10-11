#include "containers.h"

#ifndef MAP_HPP
#define MAP_HPP

namespace ft {
    template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Alloc = std::allocator<ft::pair<const Key, T> > >
    class map {
    public:
        typedef Key                                 key_type;
        typedef T                                   mapped_type;
        typedef typename ft::pair<const Key, T>    value_type;
        typedef typename std::size_t                size_type;
        typedef typename std::ptrdiff_t             difference_type;
        typedef Compare                             key_compare;
        typedef Alloc                               allocator_type;
        typedef value_type&                         reference;
        typedef const value_type&                   const_reference;
        typedef typename Alloc::pointer             pointer;
        typedef typename Alloc::const_pointer       const_pointer;

        map() {}

        explicit map(const Compare &comp, const Alloc &alloc = Alloc()):
        alloc(alloc), comp(comp) {}

        template<class InputIt>
        map(InputIt first, InputIt last, const Compare &comp = Compare(), const Alloc &alloc = Alloc()):
        alloc(alloc), comp(comp) {
            (void) first;
            (void) last;
        }

        map(const map &other);


    private:
        allocator_type alloc;
        key_compare comp;
    };
}

#endif
