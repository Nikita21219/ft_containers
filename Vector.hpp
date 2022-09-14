#include "containers.h"

struct Node;

template <typename T, typename Alloc = std::allocator<T> >
class vector {
public:
    typedef Alloc allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef T value_type;
    typedef size_t size_type;

    explicit vector(const allocator_type& alloc = allocator_type()) {
        (void) alloc;
        cp = 1;
        sz = 0;
        arr = this->alloc.allocate(1);
    };

    explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
        cp = n;
        sz = n;
        this->alloc = alloc;
        arr = this->alloc.allocate(sizeof(value_type) * n);
        for (size_t i = 0; i < sz; ++i)
            this->alloc.construct(arr + i, val);
    }

    // template <class InputIterator>
    // vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

    vector(const vector& x) {
        sz = x.size();
        cp = x.capacity();
        arr = this->alloc.allocate(sizeof(value_type) * cp);
        for (size_t i = 0; i < cp; ++i)
            this->alloc.construct(arr + i, x[i]);
    }

    ~vector() {
        for (size_t i = 0; i < sz; ++i)
            this->alloc.destroy(arr + i);
        this->alloc.deallocate(arr, cp);
    };

    reference operator[] (size_type n) const {return *(arr + n);};
    size_type capacity() const {return cp;};
    size_type size() const {return sz;};
    bool empty() const {return sz == 0;};
    reference front() {return arr[0];}
    const_reference front() const {return arr[0];}
    reference back() {return arr[sz - 1];}
    const_reference back() const {return arr[sz - 1];}

    vector& operator= (const vector& x) {
        sz = x.size();
        cp = x.capacity();
        arr = this->alloc.allocate(sizeof(value_type) * cp);
        for (size_t i = 0; i < sz; ++i)
            this->alloc.construct(arr + i, x[i]);
        return *this;
    };

    void reserve(size_type new_cap) {
        cp = new_cap;
        value_type *old_arr = arr;
        arr = this->alloc.allocate(sizeof(value_type) * cp);
        for (size_t i = 0; i < sz; ++i)
            this->alloc.construct(arr + i, old_arr[i]);
    };

    reference at(size_type n) {
        if (n >= sz || n < 0)
            throw std::out_of_range("out of range");
        return arr[n];
    }

    const_reference at (size_type n) const {
        if (n >= sz || n < 0)
            throw std::out_of_range("out of range");
        return arr[n];
    }

    void push_back(const value_type& val) {
        if (sz == cp) {
            reserve(cp * 2);
            arr[sz] = val;
        } else {
            arr[sz] = val;
        }
        sz += 1;
    }

    void pop_back() {
        alloc.destroy(arr + (sz - 1));
        sz -= 1;
    }

private:
    value_type *arr;
    size_type sz;
    size_type cp;
    allocator_type alloc;
};
