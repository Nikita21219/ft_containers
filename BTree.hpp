#include "containers.h"

#ifndef BTREE_HPP
#define BTREE_HPP

namespace ft
{
    template <
        class T,
        class Compare = std::less<typename T::first_type>,
        class Alloc = std::allocator<T>,
        class Node = ft::BTreeNode<T> >
    class BTree
    {
    public:
        typedef Alloc allocator_type;
        typedef typename allocator_type::template rebind<Node>::other NodeAlloc;
        typedef T  value_type;
        typedef T* pointer;
        typedef typename T::first_type                  Key;
        typedef typename T::second_type                 mapped_type;
        typedef typename allocator_type::const_pointer  const_pointer;
        typedef typename allocator_type::size_type      size_type;
        typedef Node                                    node_type;
        typedef BidirIter<Node>                         iterator;
        typedef ConstBidirIter<Node>                    const_iterator;
        typedef ReverseBidirIter<iterator>              reverse_iterator;
        typedef ReverseBidirIter<const_iterator>        const_reverse_iterator;
        typedef typename iterator::difference_type      difference_type;

        BTree(const Compare& comp = Compare(), const NodeAlloc& alloc = NodeAlloc()):
        root(NULL), comp(comp), alloc(alloc), sz(0) {}

        ~BTree() {treeEraseRange(begin(), end());}

        BTree(const BTree &other)                   {*this = other;}
        iterator begin()                            {return iterator(getMin(root));}
        const_iterator cbegin() const               {return const_iterator(getMin(root));}
        reverse_iterator rbegin()                   {return reverse_iterator(getMax(root));}
        const_reverse_iterator crbegin() const      {return const_reverse_iterator(getMax(root));}
        iterator end()                              {return iterator(NULL);}
        const_iterator cend() const                 {return const_iterator(NULL);}
        reverse_iterator rend()                     {return reverse_iterator(NULL);}
        const_reverse_iterator crend() const        {return const_reverse_iterator(NULL);}
        size_type size() const                      {return sz;}
        iterator find(const Key &k)                 {return iterator(getNodeByKey(k));}
        const_iterator find(const Key &k) const     {return const_iterator(getNodeByKey(k));}
        const mapped_type &at(const Key &k) const   {return at(k);}
        
        void clear() {
            treeEraseRange(begin(), end());
            sz = 0;
        }

        mapped_type &operator[](const Key &k) {
            iterator it = find(k);
            if (it != end())
                return it->second;
            ft::pair<iterator, bool> p = treeInsert(ft::make_pair(k, mapped_type()), root);
            if (p.second)
                return p.first->second;
            else
                return find(k)->second;
        }

        void swap(BTree &other) {
            BTree tmp = *this;
            *this = other;
            other = tmp;
        } //TODO not right! need to fix

        mapped_type &at(const Key &k) {
            iterator it = find(k);
            if (it != end())
                return it->second;
            else
                throw std::out_of_range("key not found");
        }

        const BTree &operator=(const BTree &other) {
            if (size())
                treeEraseRange(begin(), end());
            treeInsertRange(other.cbegin(), other.cend());
            return *this;
        }

        void treeWalk(Node *x) {
            if (x != NULL) {
                treeWalk(x->left);
                std::cout << x->data.first << " ";
                treeWalk(x->right);
            }
        }

        bool valueInTree(const value_type &value) {
            for (iterator i = begin(); i != end(); i++)
                if (i->first == value.first)
                    return true;
            return false;
        }

        ft::pair<iterator, bool> treeInsert(const value_type &value, Node *start) {
            Node *y = NULL;
            Node *x = start;
            while (x != NULL) {
                y = x;
                if (value.first == x->data.first)
                    return ft::pair<iterator, bool>(iterator(x), false);
                else if (comp(value.first, x->data.first))
                    x = x->left;
                else
                    x = x->right;
            }
            if (root != start && (comp(y->data.first, value.first) || valueInTree(value)))
                return ft::pair<iterator, bool>(iterator(x), false);
            Node *node = alloc.allocate(sizeof(Node));
            alloc.construct(node, value);
            node->p = y;
            if (y == NULL)
                root = node;
            else if (comp(node->data.first, y->data.first))
                y->left = node;
            else
                y->right = node;
            sz++;
            return ft::pair<iterator, bool>(iterator(node), true);
        }

        bool treeErase(const Key &value) {
            if (root == NULL)
                return false;
            Node *node = root;
            while (node && node->data.first != value) {
                if (comp(value, node->data.first) == false)
                    node = node->right;
                else if (comp(value, node->data.first))
                    node = node->left;
            }
            return erase(node);
        }

        template <class InputIt>
        void treeInsertRange(InputIt first, InputIt last) {
            while (first != last) {
                treeInsert(first.getPtr()->data, getRoot());
                first++;
            }
        }

        bool erase(Node *node) {
            if (node == NULL)
                return false;
            if (node->left == NULL) {
                transplant(node, node->right);
            } else if (node->right == NULL) {
                transplant(node, node->left);
            } else {
                Node *y = getMin(node->right);
                if (y->p != node) {
                    transplant(y, y->right);
                    y->right = node->right;
                    y->right->p = y;
                }
                transplant(node, y);
                y->left = node->left;
                y->left->p = y;
            }
            alloc.destroy(node);
            alloc.deallocate(node, sizeof(node));
            sz--;
            return true;
        }

        void treeEraseRange(iterator first, iterator last) {
            iterator tmp_it;
            while (first != last) {
                tmp_it = first++;
                erase(tmp_it.getPtr());
            }
        }

        Node *getRoot() { return root; } // TODO tmp func

        // void printTree() { printBT("", root, false); }

    private:

        Node *getNodeByKey(const Key &k) {
            Node *node = root;
            while (node) {
                if (node->data.first == k)
                    return node;
                if (comp(k, node->data.first))
                    node = node->left;
                else
                    node = node->right;
            }
            return NULL;
        }

        Node *getMin(Node *node) const {
            if (node == NULL)
                return NULL;
            while (node->left)
                node = node->left;
            return node;
        }

        Node *getMax(Node *node) const {
            if (node == NULL)
                return NULL;
            while (node->right)
                node = node->right;
            return node;
        }

        void transplant(Node *u, Node *v) {
            if (u->p == NULL)
                root = v;
            else if (u == u->p->left)
                u->p->left = v;
            else
                u->p->right = v;
            if (v != NULL)
                v->p = u->p;
        }

        // void printBT (
        //     const std::string& prefix,
        //     const Node<value_type>* nodeV,
        //     bool isLeft
        //     ) const {
        //         std::cout << prefix;
        //         std::cout << (isLeft ? "├──" : "└──" );
        //         if (nodeV == NULL) {
        //             std::cout <<"\033[0;36m"<< "nil" << "\033[0m"<<std::endl;
        //             return ;
        //         }
        //         // print the value of the node
        //         if (nodeV->isRed == 0)
        //             std::cout <<"\033[0;36m"<< nodeV->pair.first<<"\033[0m"<<std::endl;
        //         else
        //             std::cout <<"\033[0;31m"<< nodeV->pair.first << "\033[0m"<<std::endl;
        //         printBT( prefix + (isLeft ? "│   " : "    "), nodeV->left, true);
        //         printBT( prefix + (isLeft ? "│   " : "    "), nodeV->right, false);
        // }

        Node *root;
        Compare comp;
        NodeAlloc alloc;
        size_t sz;
    };
}

#endif
