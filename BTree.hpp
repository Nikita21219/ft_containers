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
        typedef Compare                                 key_compare;

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
        key_compare key_comp() const                {return comp;}

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
            std::swap(root, other.root);
            std::swap(sz, other.sz);
            std::swap(comp, other.comp);
            std::swap(alloc, other.alloc);
        }

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

        size_type count(const Key &k) const {
            if (find(k) != cend())
                return 1;
            return 0;
        }

        ft::pair<iterator, bool> treeInsert(const value_type &value, Node *start) {
            (void)start;
            if (root == NULL) {
                root = new Node(value);
                root->isRed = false;
                return ft::pair<iterator, bool>(iterator(NULL), false);
                // return true;
            }
            Node *parent = NULL;
            Node *cur = root;
            while (cur) {
                if (cur->data.first < value.first) {
                    parent = cur;
                    cur = cur->right;
                } else if (cur->data.first > value.first) {
                    parent = cur;
                    cur = cur->left;
                } else {
                    return ft::pair<iterator, bool>(iterator(NULL), false);
                    // return false;
                }
            }
            cur = new Node(value);
            cur->isRed = true;
            if (parent->data.first < value.first) {
                parent->right = cur;
                cur->p = parent;
            } else {
                parent->left = cur;
                cur->p = parent;
            }
            while (parent && parent->isRed == true) {
                Node* grand = parent->p;
                if (parent == grand->left)
                {
                    Node* uncle = grand->right;
                    if (uncle && uncle->isRed == true) {
                        parent->isRed = uncle->isRed = false;
                        grand->isRed = true;
                        cur = grand;
                        parent = cur->p;
                    } else {
                        if (cur == parent->right) {
                            RotateL(parent);
                            std::swap(cur, parent);
                        }
                        RotateR(grand);
                        parent->isRed = false;
                        grand->isRed = true;
                    }
                } else {
                    Node* uncle = grand->left;
                    if (uncle && uncle->isRed == true)
                    {
                        parent->isRed = false;
                        uncle->isRed = false;
                        grand->isRed = true;

                        cur = grand;
                        parent = cur->p;
                    } else {
                        if (cur == parent->left) {
                            RotateR(parent);
                            std::swap(cur, parent);
                        }
                        RotateL(grand);
                        parent->isRed = false;
                        grand->isRed = true;
                    }
                }
            }
            root->isRed = false;
            return ft::pair<iterator, bool>(iterator(NULL), false);
        }

        void RotateR(Node *parent) {
            Node *subL = parent->left;
            Node *subLR = subL->right;
            Node *ppNode = parent->p;

            parent->left = subLR;
            if (subLR)
                subLR->p = parent;
            subL->right = parent;
            parent->p = subL;
            if (ppNode == NULL) {
                root = subL;
                subL->p = NULL;
            } else {
                if (ppNode->left == parent)
                    ppNode->left = subL;
                else
                    ppNode->right = subL;
                subL->p = ppNode;
            }
        }

        void RotateL(Node *parent) {
            Node *subR = parent->right;
            Node *subRL = subR->left;
            Node *ppNode = parent->p;

            parent->right = subRL;
            if (subRL)
                subRL->p = parent;
            subR->left = parent;
            parent->p = subR;
            if (ppNode == NULL) {
                root = subR;
                subR->p = NULL;
            } else {
                if (ppNode->left == parent)
                    ppNode->left = subR;
                else
                    ppNode->right = subR;
                subR->p = ppNode;
            }
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

        iterator lower_bound(const Key &k) {
            iterator it = begin();
            while (it != end()) {
                if (comp(it->first, k) == false)
                    return it;
                it++;
            }
            return end();
        }

        const_iterator lower_bound(const Key &k) const {
            const_iterator it = cbegin();
            while (it != cend()) {
                if (comp(it->first, k) == false)
                    return it;
                it++;
            }
            return cend();
        }

        iterator upper_bound(const Key &k) {
            iterator it = begin();
            while (it != end()) {
                if (comp(k, it->first))
                    return it;
                it++;
            }
            return end();
        }

        const_iterator upper_bound(const Key &k) const {
            const_iterator it = cbegin();
            while (it != cend()) {
                if (comp(k, it->first))
                    return it;
                it++;
            }
            return cend();
        }

        ft::pair<iterator, iterator> equal_range(const Key &k) {
            iterator lb_it = lower_bound(k);
            iterator ub_it = upper_bound(k);
            iterator it = begin();
            while (it != lb_it && it != end())
                it++;
            iterator res_it1 = it;
            it = begin();
            while (it != ub_it && it != end())
                it++;
            iterator res_it2 = it;
            return ft::pair<iterator, iterator>(res_it1, res_it2);
        }

        ft::pair<const_iterator, const_iterator> equal_range(const Key &k) const {
            const_iterator lb_it = lower_bound(k);
            const_iterator ub_it = upper_bound(k);
            const_iterator it = cbegin();
            while (it != lb_it && it != cend())
                it++;
            const_iterator res_it1 = it;
            it = cbegin();
            while (it != ub_it && it != cend())
                it++;
            const_iterator res_it2 = it;
            return ft::pair<const_iterator, const_iterator>(res_it1, res_it2);
        }

        Node *getRoot() { return root; } // TODO tmp func

        // void printTree() { printBT("", root, false); }

    private:

        Node *getNodeByKey(const Key &k) const {
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
        key_compare comp;
        NodeAlloc alloc;
        size_t sz;
    };
}

#endif
