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

        class value_compare {
            friend class map;

            public:
                typedef bool        result_type;
                typedef value_type  first_argument_type;
                typedef value_type  second_argument_type;

                bool operator()(const value_type &x, const value_type &y) const {
                    return comp(x.first, y.first);
                }

            protected:
                Compare comp;
                value_compare(Compare c): comp(c) {}
        };

        explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): alloc(alloc), comp(comp), tree() {}

        template <class InputIt>
        map(
            InputIt first,
            InputIt last,
            const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type()
            ): alloc(alloc), comp(comp), tree() {
                insert(first, last);
        }
        
        map &operator= (const map &other) {
            tree = other.tree;
            return *this;
        }

        ft::pair<iterator, bool> insert(const value_type &val) {
            return tree.treeInsert(val, tree.getRoot());
        }

        template <class InputIt>
        void insert(InputIt first, InputIt last) {
            while (first != last)
                insert(*first++);
        }

        iterator insert(iterator position, const value_type &val) {
            ft::pair<iterator, bool> p = tree.treeInsert(val, position.getPtr());
            if (p.second)
                return p.first;
            return tree.treeInsert(val, position.getPtr()).first;
        }

        size_type max_size() const  {
            return std::numeric_limits<difference_type>::max();
        }

        const_iterator lower_bound(const key_type &k) const {
            return tree.lower_bound(k);
        }

        iterator upper_bound(const key_type &k) {
            return tree.upper_bound(k);
        }

        const_iterator upper_bound(const key_type &k) const {
            return tree.upper_bound(k);
        }

        map(const map& other)                           {*this = other;}
        void erase(iterator position)                   {tree.erase(position.getPtr());}
        void erase(iterator first, iterator last)       {tree.treeEraseRange(first, last);}
        void swap(map &other)                           {tree.swap(other.tree);}
        void clear()                                    {tree.clear();}
        iterator find(const key_type &k)                {return tree.find(k);}
        const_iterator find(const key_type &k) const    {return tree.find(k);}
        iterator begin()                                {return tree.begin();}
        const_iterator begin() const                    {return tree.cbegin();}
        reverse_iterator rbegin()                       {return tree.rbegin();}
        const_reverse_iterator rbegin() const           {return tree.crbegin();}
        iterator end()                                  {return tree.end();}
        const_iterator end() const                      {return tree.cend();}
        reverse_iterator rend()                         {return tree.rend();}
        const_reverse_iterator rend() const             {return tree.crend();}
        size_type erase(const key_type& k)              {return tree.treeErase(k) ? 1 : 0;}
        size_type size() const                          {return tree.size();}
        bool empty() const                              {return size();}
        mapped_type &operator[](const key_type &k)      {return tree[k];}
        mapped_type &at(const key_type& k)              {return tree.at(k);}
        const mapped_type &at(const key_type &k) const  {return tree.at(k);}
        key_compare key_comp() const                    {return tree.key_comp();}
        value_compare value_comp() const                {return value_compare(comp);}
        size_type count(const key_type &k) const        {return tree.count(k);}
        iterator lower_bound(const key_type &k)         {return tree.lower_bound(k);}

    private:
        allocator_type alloc;
        key_compare comp;
        Tree tree;
    };
}

#endif
