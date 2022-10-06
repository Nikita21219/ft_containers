#include "containers.h"

#ifndef STACK_HPP
#define STACK_HPP

namespace ft {
    template<typename T, typename Container = ft::vector<T> >
    class stack {
    public:
        typedef Container                               container_type;
        typedef typename Container::value_type	        value_type;
        typedef typename Container::size_type	        size_type;
        typedef typename Container::reference	        reference;
        typedef typename Container::const_reference	    const_reference;

        stack(const container_type& c = container_type()): c(c) {}
        ~stack() {}
        reference top() {return c.back();}
        const_reference top() const {return c.back();}
        bool empty() const {return c.empty();}
        size_type size() const {return c.size();}
        void push(const value_type &value) {c.push_back(value);}
        void pop() {c.pop_back();}

    private:
        container_type c;

        template <typename T1, typename ContainerT>
        friend bool operator==(const ft::stack<T1, ContainerT>& l, const ft::stack<T1, ContainerT>& r);
        
        template <typename T1, typename ContainerT>
        friend bool operator!=(const ft::stack<T1, ContainerT>& l, const ft::stack<T1, ContainerT>& r);
        
        template <typename T1, typename ContainerT>
        friend bool operator>(const ft::stack<T1, ContainerT>& l, const ft::stack<T1, ContainerT>& r);
        
        template <typename T1, typename ContainerT>
        friend bool operator<(const ft::stack<T1, ContainerT>& l, const ft::stack<T1, ContainerT>& r);
        
        template <typename T1, typename ContainerT>
        friend bool operator<=(const ft::stack<T1, ContainerT>& l, const ft::stack<T1, ContainerT>& r);
        
        template <typename T1, typename ContainerT>
        friend bool operator>=(const ft::stack<T1, ContainerT>& l, const ft::stack<T1, ContainerT>& r);
    };

    template <typename T, typename Container>
    bool operator==(const ft::stack<T, Container>& l, const ft::stack<T, Container>& r) {return (l.c == r.c);}

    template <typename T, typename Container>
    bool operator!=(const ft::stack<T, Container>& l, const ft::stack<T, Container>& r) {return (l.c != r.c);}

    template <typename T, typename Container>
    bool operator>(const ft::stack<T, Container>& l, const ft::stack<T, Container>& r) {return (l.c > r.c);}

    template <typename T, typename Container>
    bool operator<(const ft::stack<T, Container>& l, const ft::stack<T, Container>& r) {return (l.c < r.c);}

    template <typename T, typename Container>
    bool operator<=(const ft::stack<T, Container>& l, const ft::stack<T, Container>& r) {return (l.c <= r.c);}

    template <typename T, typename Container>
    bool operator>=(const ft::stack<T, Container>& l, const ft::stack<T, Container>& r) {return (l.c >= r.c);}
}

#endif
