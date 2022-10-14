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
        typedef typename std::size_t                        size_type;
        typedef typename std::ptrdiff_t                     difference_type;
        typedef value_type&                                 reference;
        typedef const value_type&                           const_reference;
        typedef BTreeNode<value_type>                       TreeNode;
        typedef BidirIter<TreeNode>                         iterator;
        typedef BidirIter<const TreeNode>                   const_iterator;
        // typedef BidirIter<TreeNode, false>                  iterator;
        // typedef BidirIter<TreeNode, true>                   const_iterator;
        typedef ReverseBidirIter<iterator>                  reverse_iterator;
        typedef ReverseBidirIter<const_iterator>            const_reverse_iterator;

        explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): alloc(alloc), comp(comp), tree() {}

        template <class InputIt>
        map(
            InputIt first,
            InputIt last,
            const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type()
            ): alloc(alloc), comp(comp), tree() {
            while (first != last)
                tree.treeInsert(*first++);
        }

        ft::pair<iterator, bool> insert(const value_type& val) {
            return tree.treeInsert(val);
        }

        iterator begin() {return tree.begin();}
        const_iterator cbegin() const {return tree.cbegin();}
        iterator end() {return tree.end();}
        const_iterator end() const {return tree.end();}

    private:
        allocator_type alloc;
        key_compare comp;
        Tree tree;
    };
}

#endif
