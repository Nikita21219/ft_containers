#include "containers.h"

#ifndef RBTREE_HPP
#define RBTREE_HPP

namespace ft
{

    template <class T1, class T2>
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;

        pair(){};

        pair(const T1 &x, const T2 &y)
        {
            first = x;
            second = y;
        };

        template <class U1, class U2>
        pair(const pair<U1, U2> &p)
        {
            first = p.first;
            second = p.second;
        };

        first_type first;
        second_type second;
    };

    template <typename keyT, typename valT>
    struct RBTreeNode
    {
        RBTreeNode()
        {
            isRed = false;
            left = NULL;
            right = NULL;
            p = NULL;
        }

        ~RBTreeNode() {}

        bool isRed;
        ft::pair<keyT, valT> pair;
        struct RBTreeNode *left;
        struct RBTreeNode *right;
        struct RBTreeNode *p;
    };

    template <
        class Key,
        class T,
        class Compare = std::less<Key>,
        class Alloc = std::allocator<ft::pair<const Key, T> > >
    class RBTree
    {
    public:
        typedef struct ft::pair<Key, T> value_type;
        typedef RBTreeNode<Key, T> TreeNode;
        typedef Alloc allocator_type;
        typedef value_type *pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename allocator_type::size_type size_type;
        typedef ft::InputIt<TreeNode> iterator;
        typedef ft::InputIt<const TreeNode> const_iterator;
        typedef typename iterator::difference_type difference_type;
        typedef ft::ReverseInputIt<iterator> reverse_iterator;
        typedef ft::ReverseInputIt<const_iterator> const_reverse_iterator;

        RBTree()
        {
            // nil = getNewNode(ft::pair<Key, T>());
            // root = nil;
            root = NULL;
        }

        ~RBTree() {}

        RBTree(const RBTree &other); // TODO implement

        // void treeInsertFixUp(TreeNode *valNode, TreeNode *y) {
        //     while (valNode->parent->isRed) {
        //         if (valNode && valNode->parent && \
        //         valNode->parent->parent && valNode->parent \
        //         == valNode->parent->parent->left) {
        //             y = valNode->parent->parent->right;
        //             if (y->isRed) {
        //                 valNode->parent->isRed = false;
        //                 y->isRed = false;
        //                 valNode->parent->parent->isRed = true;
        //                 valNode = valNode->parent->parent;
        //             } else if (valNode == valNode->parent->right) {
        //                 valNode = valNode->parent;
        //                 leftRotate(valNode);
        //                 valNode->parent->isRed = false;
        //                 valNode->parent->parent->isRed = true;
        //                 rightRotate(valNode->parent->parent);
        //             } else {
        //                 valNode = valNode->parent;
        //                 rightRotate(valNode);
        //                 valNode->parent->isRed = false;
        //                 valNode->parent->parent->isRed = true;
        //                 leftRotate(valNode->parent->parent);
        //             }
        //         }
        //     }
        //     root->isRed = false;
        // }

        ft::pair<iterator, bool> treeInsert(const value_type &value)
        {
            TreeNode *node = getNewNode(value);
            TreeNode *y = NULL;
            TreeNode *x = root;
            while (x != NULL) {
                y = x;
                if (node->pair.first < x->pair.first)
                    x = x->left;
                else
                    x = x->right;
            }
            node->p = y;
            if (y == NULL)
                root = node;
            else if (node->pair.first < y->pair.first)
                y->left = node;
            else
                y->right = node;
            return ft::pair<iterator, bool>(iterator(node), false);
        }

        void treeErase(const Key &value) {
            if (root == NULL)
                return;
            TreeNode *node = root;
            while (node && node->pair.first != value) {
                if (value > node->pair.first) {
                    node = node->right;
                } else if (value < node->pair.first) {
                    node = node->left;
                }
            }
            if (node == NULL)
                return;
            if (node->left == NULL) {
                transplant(node, node->right);
            } else if (node->right == NULL) {
                transplant(node, node->left);
            } else {
                TreeNode *y = getMin(node->right);
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
        }

        void printTree() { printBT("", root, false); }


    private:
        TreeNode *root;

        TreeNode *getMin(TreeNode *node) {
            if (node == NULL)
                return NULL;
            while (node->left)
                node = node->left;
            return node;
        }

        TreeNode *getMax(TreeNode *node) {
            if (node == NULL)
                return NULL;
            while (node->right)
                node = node->right;
            return node;
        }

        void transplant(TreeNode *u, TreeNode *v) {
            if (u->p == NULL)
                root = v;
            else if (u == u->p->left)
                u->p->left = v;
            else
                u->p->right = v;
            if (v != NULL)
                v->p = u->p;
        }

        TreeNode *getNewNode(const value_type pair)
        {
            RBTreeNode<Key, T> *node = new RBTreeNode<Key, T>();
            node->pair = pair;
            node->left = NULL;
            node->right = NULL;
            node->p = NULL;
            return node;
        }

        void printBT (
            const std::string& prefix,
            const RBTreeNode<Key, T>* nodeV,
            bool isLeft
            ) const {
                std::cout << prefix;
                std::cout << (isLeft ? "├──" : "└──" );
                if (nodeV == NULL) {
                    std::cout <<"\033[0;36m"<< "nil" << "\033[0m"<<std::endl;
                    return ;
                }
                // print the value of the node
                if (nodeV->isRed == 0)
                    std::cout <<"\033[0;36m"<< nodeV->pair.first<<"\033[0m"<<std::endl;
                else
                    std::cout <<"\033[0;31m"<< nodeV->pair.first << "\033[0m"<<std::endl;
                printBT( prefix + (isLeft ? "│   " : "    "), nodeV->left, true);
                printBT( prefix + (isLeft ? "│   " : "    "), nodeV->right, false);
        }

    public:                                  // TODO delete this line
        TreeNode *getRoot() { return root; } // TODO tmp func
    };
}

#endif
