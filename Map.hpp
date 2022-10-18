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
        typedef BTree<value_type, Compare, Alloc>           Tree;
        typedef typename std::size_t                        size_type;
        typedef typename std::ptrdiff_t                     difference_type;
        typedef value_type&                                 reference;
        typedef const value_type&                           const_reference;
        typedef typename Tree::iterator                     iterator;
        typedef typename Tree::const_iterator               const_iterator;
        typedef typename Tree::reverse_iterator             reverse_iterator;
        typedef typename Tree::const_reverse_iterator       const_reverse_iterator;
        typedef typename Tree::node_type                    node_type;

        explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): alloc(alloc), comp(comp), tree() {}

        template <class InputIt>
        map(
            InputIt first,
            InputIt last,
            const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type()
            ): alloc(alloc), comp(comp), tree() {
            while (first != last)
                tree.treeInsert(*first++, tree.getRoot());
        }
        map(const map& x): tree(x.tree) {}

        ft::pair<iterator, bool> insert(const value_type& val) {
            return tree.treeInsert(val, tree.getRoot());
        }

        iterator insert(iterator position, const value_type &val) {
            ft::pair<iterator, bool> p = tree.treeInsert(val, position.getPtr());
            if (p.second)
                return p.first;
            return tree.treeInsert(val, position.getPtr()).first;
        }

        iterator begin()                            {return tree.begin();}
        const_iterator begin() const                {return tree.cbegin();}
        reverse_iterator rbegin()                   {return tree.rbegin();}
        const_reverse_iterator rbegin() const       {return tree.crbegin();}
        iterator end()                              {return tree.end();}
        const_iterator end() const                  {return tree.cend();}
        reverse_iterator rend()                     {return tree.rend();}
        const_reverse_iterator rend() const         {return tree.crend();}
        size_type erase(const key_type& k)          {return tree.treeErase(k) ? 1 : 0;}
        void erase(iterator position)               {tree.erase(position.getPtr());}
        void erase(iterator first, iterator last)   {tree.treeEraseRange(first, last);}
        size_type size() const                      {return tree.size();}

    private:
        allocator_type alloc;
        key_compare comp;
        Tree tree;
    };
}

#endif
