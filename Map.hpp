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
        typedef Key                                     key_type;
        typedef T                                       mapped_type;
        typedef typename ft::pair<const Key, T>         value_type;
        typedef typename std::size_t                    size_type;
        typedef typename std::ptrdiff_t                 difference_type;
        typedef Compare                                 key_compare;
        typedef Alloc                                   allocator_type;
        typedef value_type&                             reference;
        typedef const value_type&                       const_reference;
        typedef typename Alloc::pointer                 pointer;
        typedef typename Alloc::const_pointer           const_pointer;
        typedef BTreeNode<Key, T>                       TreeNode;
        typedef ft::BidirIter<TreeNode, false>          iterator;
        typedef ft::BidirIter<TreeNode, true>     const_iterator;
        typedef ft::ReverseBidirIter<iterator>          reverse_iterator;
        typedef ft::ReverseBidirIter<const_iterator>    const_reverse_iterator;

        explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): comp(comp), alloc(alloc), tree() {}

        template <class InputIt>
        map(
            InputIt first,
            InputIt last,
            const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type()
            ): alloc(alloc), comp(comp), tree() {
            while (first != last) {
                tree.treeInsert(*first);
                first++;
            }
        }


    private:
        allocator_type alloc;
        key_compare comp;
        ft::BTree<Key, T, Compare, Alloc> tree;
    };
}

#endif
