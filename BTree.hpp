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
        typedef T  value_type;
        typedef T* pointer;
        typedef typename T::first_type Key;
        // typedef typename T::second_type Val;
        // typedef typename allocator_type::const_pointer const_pointer;
        // typedef typename allocator_type::size_type size_type;
        typedef BidirIter<Node>                         iterator;
        typedef ConstBidirIter<Node>                    const_iterator;
        typedef ReverseBidirIter<iterator>              reverse_iterator;
        typedef ReverseBidirIter<const_iterator>        const_reverse_iterator;
        // typedef typename iterator::difference_type      difference_type;

        BTree(): root(NULL), count(0) {}
        ~BTree() {} // TODO implement
        BTree(const BTree &other); // TODO implement
        iterator begin() {return iterator(getMin(root));}
        const_iterator cbegin() const {return const_iterator(getMin(root));}
        reverse_iterator rbegin() {return reverse_iterator(getMax(root));}
        const_reverse_iterator crbegin() const {return const_reverse_iterator(getMax(root));}

        iterator end() {return iterator(NULL);}
        const_iterator cend() const {return const_iterator(NULL);}
        reverse_iterator rend() {return reverse_iterator(NULL);}
        const_reverse_iterator crend() const {return const_reverse_iterator(NULL);}

        void treeWalk(Node *x) {
            if (x != NULL) {
                treeWalk(x->left);
                std::cout << x->data.first << " ";
                treeWalk(x->right);
            }
        }

        ft::pair<iterator, bool> treeInsert(const value_type &value) {
            Node *node = new Node(value);
            Node *y = NULL;
            Node *x = root;
            while (x != NULL) {
                y = x;
                if (comp(node->data.first, x->data.first))
                    x = x->left;
                else
                    x = x->right;
            }
            node->p = y;
            if (y == NULL)
                root = node;
            else if (comp(node->data.first, y->data.first))
                y->left = node;
            else
                y->right = node;
            count++;
            return ft::pair<iterator, bool>(iterator(node), false);
        }

        size_t treeErase(const Key &value) {
            size_t counter = 0;
            treeEraseRecursion(value, &counter);
            return counter;
        }

        // void printTree() { printBT("", root, false); }
        
        Node *getRoot() { return root; } // TODO tmp func


    private:
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

        void treeEraseRecursion(const Key &value, size_t *counter) {
            if (root == NULL)
                return;
            Node *node = root;
            while (node && node->data.first != value) {
                if (comp(value, node->data.first) == false)
                    node = node->right;
                else if (comp(value, node->data.first))
                    node = node->left;
            }
            if (node == NULL)
                return;
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
            delete node;
            (*counter)++;
            treeEraseRecursion(value, counter); // TODO fix recursion
        }


        Node *root;
        Node **sortArr;
        Compare comp;
        size_t count;
    };
}

#endif
