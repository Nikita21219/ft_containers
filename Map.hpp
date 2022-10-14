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
        typedef typename Alloc::pointer                     pointer;
        typedef typename Alloc::const_pointer               const_pointer;
        typedef Compare                                     key_compare;
        typedef Alloc                                       allocator_type;
        typedef const Key                                   key_type;
        typedef T                                           mapped_type;
        typedef typename ft::pair<key_type, mapped_type>    value_type;
        typedef ft::BTree<value_type, Compare, Alloc>       Tree;
        // typedef typename std::size_t                        size_type;
        // typedef typename std::ptrdiff_t                     difference_type;
        // typedef value_type&                                 reference;
        // typedef const value_type&                           const_reference;
        typedef BTreeNode<value_type>                       TreeNode;
        typedef BidirIter<TreeNode, false>              iterator;
        // typedef ft::BidirIter<TreeNode, true>               const_iterator;
        // typedef ft::ReverseBidirIter<iterator>              reverse_iterator;
        // typedef ft::ReverseBidirIter<const_iterator>        const_reverse_iterator;

        explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): alloc(alloc), comp(comp), tree() {}

        // template <class InputIt>
        // map(
        //     InputIt first,
        //     InputIt last,
        //     const key_compare& comp = key_compare(),
        //     const allocator_type& alloc = allocator_type()
        //     ): alloc(alloc), comp(comp), tree() {
        //     while (first != last) {
        //         tree.treeInsert(*first);
        //         first++;
        //     }
        // }

        // ft::pair<iterator, bool> insert(const value_type& val) {
        //     return tree.treeInsert(val);
        // }

        void insert(const value_type& val) {
            tree.treeInsert(val);
        }


    private:
        allocator_type alloc;
        key_compare comp;
        Tree tree;
    };
}

#endif
