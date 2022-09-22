#include "containers.h"

namespace ft {

    struct random_access_iterator_tag {};

    template <typename iterator>
    struct iterator_traits {
    typedef typename iterator::iterator_category iterator_category;
    typedef typename iterator::value_type        value_type;
    typedef typename iterator::difference_type   difference_type;
    typedef typename iterator::pointer           pointer;
    typedef typename iterator::reference         reference;
    // typedef          difference_type             distance_type;
    };

    template <typename T>
    struct iterator_traits<T *> {
        typedef random_access_iterator_tag iterator_category;
        typedef T                          value_type;
        typedef ptrdiff_t                  difference_type;
        typedef T*                         pointer;
        typedef T&                         reference;
    };

    template< class T >
    struct iterator_traits<const T*> {
        typedef random_access_iterator_tag iterator_category;
        typedef T                          value_type;
        typedef ptrdiff_t                  difference_type;
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

    template<bool isConst, typename T>
    class RandAccessIt {
    public:
        typedef typename std::conditional<isConst, const T*, T*>::type CondPtr;
        typedef typename std::conditional<isConst, const T&, T&>::type CondRef;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T> iterator;
        typedef typename iterator::value_type                            value_type;
        typedef typename iterator::iterator_category                     iterator_category;
        typedef typename iterator::difference_type                       difference_type;
        typedef typename iterator::pointer                               pointer;
        typedef typename iterator::reference                             reference;

        RandAccessIt()                                                       {};
        RandAccessIt(CondPtr ptr): ptr(ptr)                                  {};
        CondRef operator*()                                              {return *ptr;};
        CondPtr operator->() const                                       {return ptr;}
        CondRef operator[](int idx)                                      {return *(ptr + idx);}
        bool operator==(const RandAccessIt &other) const                     {return ptr == other.ptr;}
        bool operator!=(const RandAccessIt &other) const                     {return !(*this == other);}
        friend bool operator>(const RandAccessIt& lhs, const RandAccessIt& rhs)  {return lhs.ptr > rhs.ptr;}
        friend bool operator<(const RandAccessIt& lhs, const RandAccessIt& rhs)  {return lhs.ptr < rhs.ptr;}
        friend bool operator>=(const RandAccessIt& lhs, const RandAccessIt& rhs) {return lhs.ptr >= rhs.ptr;}
        friend bool operator<=(const RandAccessIt& lhs, const RandAccessIt& rhs) {return lhs.ptr <= rhs.ptr;}

        RandAccessIt operator++() {
            ptr++;
            return *this;
        };

        RandAccessIt operator+=(int n) {
            ptr += n;
            return *this;
        };

        RandAccessIt operator-=(int n) {
            ptr -= n;
            return *this;
        };
        
        RandAccessIt operator+(int n) {
            ptr += n;
            return *this;
        };
        
        RandAccessIt operator-(int n) {
            ptr -= n;
            return *this;
        };

        RandAccessIt operator++(int) {
            RandAccessIt it = *this;
            ++(*this);
            return it;
        };
        
        RandAccessIt operator--() {
            ptr--;
            return *this;
        };

        RandAccessIt operator--(int) {
            RandAccessIt it = *this;
            --(*this);
            return it;
        };

    private:
        CondPtr ptr;
    };

    template <typename Iter>
    class ReverseRandAccessIt {
    public:
        typedef Iter iterator_type;
        typedef typename iterator_type::reference reference;
        typedef typename iterator_type::pointer pointer;
        typedef typename iterator_type::CondRef CondRef;
        typedef typename iterator_type::CondPtr CondPtr;

        ReverseRandAccessIt(Iter iter): iter(iter)                                          {}
        iterator_type base() const                                                       {return iter;}
        iterator_type operator->() const                                                 {return iter;}
        CondRef operator*()                                                              {return *iter;}
        CondRef operator[](int idx)                                                      {return *(iter + idx);}
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
        };
        
        ReverseRandAccessIt<iterator_type>& operator-(int n) {
            iter += n;
            return *this;
        };

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

    private:
        iterator_type iter;
    };

    template<class It>
    typename ft::iterator_traits<It>::difference_type 
    do_distance(It first, It last, ft::random_access_iterator_tag)
    {
        return last - first;
    }
    
    template<class It>
    typename std::iterator_traits<It>::difference_type 
    distance(It first, It last)
    {
        return do_distance(first, last, typename ft::iterator_traits<It>::iterator_category());
    }
}
