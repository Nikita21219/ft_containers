#include "containers.h"

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft {
    template <typename iterator>
    struct iterator_traits {
    typedef typename iterator::iterator_category iterator_category;
    typedef typename iterator::value_type        value_type;
    typedef typename iterator::difference_type   difference_type;
    typedef typename iterator::pointer           pointer;
    typedef typename iterator::reference         reference;
    };

    template <typename T>
    struct iterator_traits<T*> {
        typedef std::random_access_iterator_tag iterator_category;
        typedef T                          value_type;
        typedef ptrdiff_t                  difference_type;
        typedef T*                         pointer;
        typedef T&                         reference;
    };

    template<typename T>
    struct iterator_traits<const T*> {
        typedef std::random_access_iterator_tag iterator_category;
        typedef ptrdiff_t                  difference_type;
        typedef const T                    value_type;
        typedef const T*                   pointer;
        typedef const T&                   reference;
    };

    template<
        class Category,
        class T,
        class Distance = ptrdiff_t,
        class Pointer = T*,
        class Reference = T&
    > class iterator {
    public:
        typedef Category    iterator_category;
        typedef T           value_type;
        typedef Distance    difference_type;
        typedef Pointer     pointer;
        typedef Reference   reference;
    };

    template<typename T>
    class BidirIter {
    public:
        typedef typename ft::iterator<std::bidirectional_iterator_tag, T> iterator;
        typedef typename iterator::value_type                             value_type;
        typedef typename iterator::iterator_category                      iterator_category;
        typedef typename iterator::difference_type                        difference_type;
        typedef typename iterator::pointer                                pointer;
        typedef const pointer                                             const_pointer;
        typedef typename iterator::reference                              reference;
        typedef typename value_type::pair_type                            pair_type;

        BidirIter()                                                       {}
        BidirIter(pointer ptr): ptr(ptr)                                  {}
        BidirIter(const BidirIter &other): ptr(other.ptr)                 {}
        pair_type *operator->() const                                     {return &ptr->data;}
        pair_type operator*()                                             {return ptr->data;}
        bool operator==(const BidirIter &other) const                     {return ptr == other.ptr;}
        bool operator!=(const BidirIter &other) const                     {return !(*this == other);}

        friend bool operator>(const BidirIter& lhs, const BidirIter& rhs);// TODO implement
        friend bool operator<(const BidirIter& lhs, const BidirIter& rhs);// TODO implement
        friend bool operator>=(const BidirIter& lhs, const BidirIter& rhs);// TODO implement
        friend bool operator<=(const BidirIter& lhs, const BidirIter& rhs);// TODO implement
        BidirIter& operator= (const BidirIter &other) {
            ptr = other.ptr;
            return *this;
        }

        BidirIter operator++() {
            if (ptr->right) {
                ptr = ptr->right;
                while (ptr->left)
                    ptr = ptr->left;
            } else {
                pointer tmp = ptr->p;
                while (tmp && ptr == tmp->right) {
                    ptr = tmp;
                    tmp = tmp->p;
                }
                ptr = tmp;
            }
            return *this;
        }

        BidirIter operator++(int) {
            BidirIter it = *this;
            ++(*this);
            return it;
        }
    
        BidirIter operator--() {
            if (ptr->left) {
                ptr = ptr->left;
                while (ptr->right)
                    ptr = ptr->right;
            } else {
                pointer tmp = ptr->p;
                while (tmp && ptr == tmp->left) {
                    ptr = tmp;
                    tmp = tmp->p;
                }
                ptr = tmp;
            }
            return *this;
        }

        BidirIter operator--(int) {
            BidirIter it = *this;
            --(*this);
            return it;
        }

        const_pointer getPtr() const {return ptr;}

    private:
        pointer ptr;
    };

    template<typename T>
    class ConstBidirIter {
    public:
        typedef typename ft::iterator<std::bidirectional_iterator_tag, T> iterator;
        typedef typename iterator::value_type                             value_type;
        typedef typename iterator::iterator_category                      iterator_category;
        typedef typename iterator::difference_type                        difference_type;
        typedef typename iterator::pointer                                pointer;
        typedef const pointer                                             const_pointer;
        typedef typename iterator::reference                              reference;
        typedef const typename value_type::pair_type                      pair_type;

        ConstBidirIter()                                                            {}
        ConstBidirIter(pointer ptr): ptr(ptr)                                       {}
        ConstBidirIter(const ConstBidirIter &other): ptr(other.ptr)                 {}
        ConstBidirIter(const BidirIter<value_type> &other): ptr(other.getPtr())     {}
        // TODO implement operator =
        pair_type *operator->() const                                     {return &ptr->data;}
        pair_type operator*()                                             {return ptr->data;}
        bool operator==(const ConstBidirIter &other) const                {return ptr == other.ptr;}
        bool operator!=(const ConstBidirIter &other) const                {return !(*this == other);}
        const pointer& base() const                                       {return ptr;}

        friend bool operator>(const ConstBidirIter& lhs, const ConstBidirIter& rhs);// TODO implement
        friend bool operator<(const ConstBidirIter& lhs, const ConstBidirIter& rhs);// TODO implement
        friend bool operator>=(const ConstBidirIter& lhs, const ConstBidirIter& rhs);// TODO implement
        friend bool operator<=(const ConstBidirIter& lhs, const ConstBidirIter& rhs);// TODO implement

        ConstBidirIter operator++() {
            if (ptr->right) {
                ptr = ptr->right;
                while (ptr->left)
                    ptr = ptr->left;
            } else {
                pointer tmp = ptr->p;
                while (tmp && ptr == tmp->right) {
                    ptr = tmp;
                    tmp = tmp->p;
                }
                ptr = tmp;
            }
            return *this;
        }

        ConstBidirIter operator++(int) {
            ConstBidirIter it = *this;
            ++(*this);
            return it;
        }
    
        ConstBidirIter operator--() {
            if (ptr->left) {
                ptr = ptr->left;
                while (ptr->right)
                    ptr = ptr->right;
            } else {
                pointer tmp = ptr->p;
                while (tmp && ptr == tmp->left) {
                    ptr = tmp;
                    tmp = tmp->p;
                }
                ptr = tmp;
            }
            return *this;
        }

        ConstBidirIter operator--(int) {
            ConstBidirIter it = *this;
            --(*this);
            return it;
        }

        const_pointer getPtr() const {return ptr;}

    private:
        pointer ptr;
    };


    template <typename Iter> // TODO inheritance typedefs from general iterator
    class ReverseBidirIter {
    public:
        typedef Iter iterator_type;
        typedef typename iterator_type::reference reference;
        typedef typename iterator_type::pointer pointer;
        typedef typename iterator_type::difference_type difference_type;

        template <class IterT>
        ReverseBidirIter(const ReverseBidirIter<IterT>& it): iter(it.base())         {}
        ReverseBidirIter(Iter iter): iter(iter)                                      {}
        iterator_type base() const                                                   {return iter;}
        iterator_type operator->() const                                             {return iter;}
        reference operator*()                                                        {return *iter;}
        reference operator[](int idx)                                                {return *(iter + idx);}
        bool operator!=(const ReverseBidirIter &other) const                         {return !(*this == other);}
        bool operator==(const ReverseBidirIter &other) const                         {return iter == other.iter;}
        friend bool operator>(const ReverseBidirIter& l, const ReverseBidirIter& r)  {return l.ptr > r.ptr;}
        friend bool operator<(const ReverseBidirIter& l, const ReverseBidirIter& r)  {return l.ptr < r.ptr;}
        friend bool operator>=(const ReverseBidirIter& l, const ReverseBidirIter& r) {return l.ptr >= r.ptr;}
        friend bool operator<=(const ReverseBidirIter& l, const ReverseBidirIter& r) {return l.ptr <= r.ptr;}

        ReverseBidirIter<iterator_type>& operator++() {
            iter--;
            return *this;
        }

        ReverseBidirIter<iterator_type>& operator--() {
            iter++;
            return *this;
        }

        ReverseBidirIter<iterator_type>& operator++(int) {
            ReverseBidirIter<iterator_type>& it = *this;
            iter--;
            return it;
        }

        ReverseBidirIter<iterator_type>& operator--(int) {
            ReverseBidirIter<iterator_type>& it = *this;
            iter++;
            return it;
        }

        //TODO need to realize operator-(iterator). reverse_iter1 - reverse_iter2

    private:
        iterator_type iter;
    };

    template <typename Iter> // TODO inheritance typedefs from general iterator
    class ConstReverseBidirIter {
    public:
        typedef Iter iterator_type;
        typedef typename iterator_type::reference reference;
        typedef typename iterator_type::pointer pointer;
        typedef typename iterator_type::difference_type difference_type;

        ConstReverseBidirIter(Iter iter): iter(iter)              {}
        iterator_type base() const                                {return iter;}
        iterator_type operator->() const                          {return iter;}
        reference operator*()                                     {return *iter;}
        reference operator[](int idx)                             {return *(iter + idx);}
        bool operator!=(const ConstReverseBidirIter &other) const {return !(*this == other);}
        bool operator==(const ConstReverseBidirIter &other) const {return iter == other.iter;}
        friend bool operator>(const ConstReverseBidirIter& l, const ConstReverseBidirIter& r)
        {return l.ptr > r.ptr;}
        friend bool operator<(const ConstReverseBidirIter& l, const ConstReverseBidirIter& r) {return l.ptr < r.ptr;}
        friend bool operator>=(const ConstReverseBidirIter& l, const ConstReverseBidirIter& r) {
            return l.ptr >= r.ptr;
        }
        friend bool operator<=(const ConstReverseBidirIter& l, const ConstReverseBidirIter& r) {
            return l.ptr <= r.ptr;
        }

        ConstReverseBidirIter<iterator_type>& operator++() {
            iter--;
            return *this;
        }

        ConstReverseBidirIter<iterator_type>& operator--() {
            iter++;
            return *this;
        }

        ConstReverseBidirIter<iterator_type>& operator++(int) {
            ConstReverseBidirIter<iterator_type>& it = *this;
            iter--;
            return it;
        }

        ConstReverseBidirIter<iterator_type>& operator--(int) {
            ConstReverseBidirIter<iterator_type>& it = *this;
            iter++;
            return it;
        }

        //TODO need to realize operator-(iterator). reverse_iter1 - reverse_iter2

    private:
        iterator_type iter;
    };

    template<typename T>
    class RandAccessIt {
    //TODO const_iter = iter
    //TODO iter = const_iter
    //TODO NEED TO FIX!!!!!!!!!!!!!!!
    public:
        typedef typename ft::iterator<std::random_access_iterator_tag, T> iterator;
        typedef typename iterator::value_type                 value_type;
        typedef typename iterator::iterator_category          iterator_category;
        typedef typename iterator::difference_type            difference_type;
        typedef typename iterator::pointer                    pointer;
        typedef typename iterator::reference                  reference;

        RandAccessIt()                                                           {};
        RandAccessIt(pointer ptr): ptr(ptr)                                      {};
        reference operator*()                                                    {return *ptr;}
        pointer operator->() const                                               {return ptr;}
        reference operator[](int idx)                                            {return *(ptr + idx);}
        bool operator==(const RandAccessIt &other) const                         {return ptr == other.ptr;}
        bool operator!=(const RandAccessIt &other) const                         {return !(*this == other);}
        friend bool operator>(const RandAccessIt& lhs, const RandAccessIt& rhs)  {return lhs.ptr > rhs.ptr;}
        friend bool operator<(const RandAccessIt& lhs, const RandAccessIt& rhs)  {return lhs.ptr < rhs.ptr;}
        friend bool operator>=(const RandAccessIt& lhs, const RandAccessIt& rhs) {return lhs.ptr >= rhs.ptr;}
        friend bool operator<=(const RandAccessIt& lhs, const RandAccessIt& rhs) {return lhs.ptr <= rhs.ptr;}
        const pointer& base() const                                              {return ptr;}
        difference_type operator-(RandAccessIt it)                               {return ptr - it.ptr;}
        RandAccessIt operator+(int n)                                            {return RandAccessIt(ptr + n);}
        RandAccessIt operator-(int n)                                            {return RandAccessIt(ptr - n);}

        RandAccessIt operator++() {
            ptr++;
            return *this;
        }

        RandAccessIt operator+=(int n) {
            ptr += n;
            return *this;
        }

        RandAccessIt operator-=(int n) {
            ptr -= n;
            return *this;
        }

        RandAccessIt operator++(int) {
            RandAccessIt it = *this;
            ++(*this);
            return it;
        }
        
        RandAccessIt operator--() {
            ptr--;
            return *this;
        }

        RandAccessIt operator--(int) {
            RandAccessIt it = *this;
            --(*this);
            return it;
        }

    private:
        pointer ptr;
    };

    template <typename Iter> // TODO inheritance typedefs from general iterator
    class ReverseRandAccessIt {
    public:
        typedef Iter iterator_type;
        typedef typename iterator_type::reference reference;
        typedef typename iterator_type::pointer pointer;
        typedef typename iterator_type::difference_type difference_type;

        ReverseRandAccessIt(Iter iter): iter(iter)                                          {}
        iterator_type base() const                                                       {return iter;}
        iterator_type operator->() const                                                 {return iter;}
        reference operator*()                                                              {return *iter;}
        reference operator[](int idx)                                                      {return *(iter + idx);}
        bool operator!=(const ReverseRandAccessIt &other) const                             {return !(*this == other);}
        bool operator==(const ReverseRandAccessIt &other) const                             {return this->iter == other.iter;}
        friend bool operator>(const ReverseRandAccessIt& lhs, const ReverseRandAccessIt& rhs)  {return lhs.ptr > rhs.ptr;}
        friend bool operator<(const ReverseRandAccessIt& lhs, const ReverseRandAccessIt& rhs)  {return lhs.ptr < rhs.ptr;}
        friend bool operator>=(const ReverseRandAccessIt& lhs, const ReverseRandAccessIt& rhs) {return lhs.ptr >= rhs.ptr;}
        friend bool operator<=(const ReverseRandAccessIt& lhs, const ReverseRandAccessIt& rhs) {return lhs.ptr <= rhs.ptr;}

        ReverseRandAccessIt<iterator_type>& operator++() {
            iter--;
            return *this;
        }

        ReverseRandAccessIt<iterator_type>& operator--() {
            iter++;
            return *this;
        }

        ReverseRandAccessIt<iterator_type>& operator+=(int n) {
            iter -= n;
            return *this;
        };

        ReverseRandAccessIt<iterator_type>& operator-=(int n) {
            iter += n;
            return *this;
        };
        
        ReverseRandAccessIt<iterator_type>& operator+(int n) {
            iter -= n;
            return *this;
        }; //TODO fix error! return new ReverseRandAccessIt(iter - n)
        
        ReverseRandAccessIt<iterator_type>& operator-(int n) {
            iter += n;
            return *this;
        }; //TODO fix error! return new ReverseRandAccessIt(iter - n)

        ReverseRandAccessIt<iterator_type>& operator++(int) {
            ReverseRandAccessIt<iterator_type>& it = *this;
            iter--;
            return it;
        };

        ReverseRandAccessIt<iterator_type>& operator--(int) {
            ReverseRandAccessIt<iterator_type>& it = *this;
            iter++;
            return it;
        };

        //TODO need to realize operator-(iterator). reverse_iter1 - reverse_iter2

    private:
        iterator_type iter;
    };

}

#endif
