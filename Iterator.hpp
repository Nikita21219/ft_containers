#include "containers.h"

namespace ft {

    template <class T1, class T2>
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;

        pair() {};

        pair(const T1 &x, const T2 &y): first(x), second(y) {}

        template <class U1, class U2>
        pair(const pair<U1, U2> &p): first(p.first), second(p.second) {}

        first_type first;
        second_type second;
    };

    template <typename keyT, typename valT>
    struct RBTreeNode
    {
        typedef keyT Key;
        typedef valT Val;

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
        typedef typename iterator::reference                              reference;
        typedef typename value_type::Key                                  key_type;
        typedef typename value_type::Val                                  val_type;
        typedef typename ft::pair<key_type, val_type>                     pair_type;
        typedef typename ft::RBTreeNode<key_type, val_type>               node_type;

        BidirIter()                                                           {}
        BidirIter(pointer ptr): ptr(ptr)                                      {}
        pair_type *operator->() const    {return &ptr->pair;}
        pair_type operator*()            {return ptr->pair;}
        bool operator==(const BidirIter &other) const                         {return ptr == other.ptr;}
        bool operator!=(const BidirIter &other) const                         {return !(*this == other);}
        // friend bool operator>(const BidirIter& lhs, const BidirIter& rhs)     {return lhs.ptr > rhs.ptr;}
        // friend bool operator<(const BidirIter& lhs, const BidirIter& rhs)     {return lhs.ptr < rhs.ptr;}
        // friend bool operator>=(const BidirIter& lhs, const BidirIter& rhs)    {return lhs.ptr >= rhs.ptr;}
        // friend bool operator<=(const BidirIter& lhs, const BidirIter& rhs)    {return lhs.ptr <= rhs.ptr;}
        // TODO implement lexicographically compares
        const pointer& base() const                                           {return ptr;}

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

        ReverseBidirIter(Iter iter): iter(iter)                                    {}
        iterator_type base() const                                               {return iter;}
        iterator_type operator->() const                                         {return iter;}
        reference operator*()                                                    {return *iter;}
        reference operator[](int idx)                                            {return *(iter + idx);}
        bool operator!=(const ReverseBidirIter &other) const                       {return !(*this == other);}
        bool operator==(const ReverseBidirIter &other) const                       {return iter == other.iter;}
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

    template<class InputIt1, class InputIt2>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
    {
        for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2) {
            if (*first1 < *first2)
                return true;
            if (*first2 < *first1)
                return false;
        }
        return (first1 == last1) && (first2 != last2);
    }

    template <bool Cond, typename T>
    struct enable_if {};

    template <typename T>
    struct enable_if<true, T> {
        typedef T type;
    };

    template <typename>
    struct is_integral_base : std::false_type {};

    template <>
    struct is_integral_base<bool> : std::true_type {};

    template <>
    struct is_integral_base<int> : std::true_type {};

    template <>
    struct is_integral_base<char> : std::true_type {};
    
    template <>
    struct is_integral_base<long> : std::true_type {};
    
    template <>
    struct is_integral_base<long long> : std::true_type {};
    
    template <>
    struct is_integral_base<char16_t> : std::true_type {};
    
    template <>
    struct is_integral_base<char32_t> : std::true_type {};
    
    template <>
    struct is_integral_base<wchar_t> : std::true_type {};
    
    template <>
    struct is_integral_base<short> : std::true_type {};
    
    template<typename T>
    struct is_integral : is_integral_base<typename std::remove_cv<T>::type> {};
}
