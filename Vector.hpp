#include "containers.h"

namespace ft {
    template <typename T, typename Alloc = std::allocator<T> >
    class vector {
    public:
        typedef          Alloc                                              allocator_type;
        typedef          T                                                  value_type;
        typedef          size_t                                             size_type;
        typedef typename allocator_type::reference                          reference;
        typedef typename allocator_type::const_reference                    const_reference;

        typedef ft::iterator<false, random_access_iterator_tag, value_type> iterator;
        typedef ft::iterator<true, random_access_iterator_tag, value_type>  const_iterator;
        typedef ft::reverse_iterator<iterator>                              reverse_iterator;


        explicit vector(const allocator_type& alloc = allocator_type()) {
            cp = 0;
            sz = 0;
            this->alloc = alloc;
            arr = this->alloc.allocate(0);
        }

        explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
            cp = n;
            sz = n;
            this->alloc = alloc;
            arr = this->alloc.allocate(sizeof(value_type) * n);
            for (size_t i = 0; i < sz; ++i)
                this->alloc.construct(arr + i, val);
        }

        vector(const vector& x) {
            sz = x.size();
            cp = x.capacity();
            arr = this->alloc.allocate(sizeof(value_type) * cp);
            for (size_t i = 0; i < cp; ++i)
                this->alloc.construct(arr + i, x[i]);
        }

        ~vector() {
            this->clear();
            this->alloc.deallocate(arr, cp);
        }

        reference operator[] (size_type n) const                     {return *(arr + n);}
        size_type capacity() const                                   {return cp;}
        size_type size() const                                       {return sz;}
        bool empty() const                                           {return sz == 0;}
        reference front()                                            {return arr[0];}
        const_reference front() const                                {return arr[0];}
        reference back()                                             {return arr[sz - 1];}
        const_reference back() const                                 {return arr[sz - 1];}
        allocator_type get_allocator() const                         {return this->alloc;}
        friend bool operator!=(const vector& lhs, const vector& rhs) {return !(lhs == rhs);}
        iterator begin()                                             {return iterator(arr);}
        iterator end()                                               {return iterator(arr + sz);}
        const_iterator cbegin() const                                {return const_iterator(arr);}
        const_iterator cend() const                                  {return const_iterator(arr + sz);}
        reverse_iterator rbegin() {return reverse_iterator(arr);}
        reverse_iterator rend() {return reverse_iterator(arr + sz);}

        vector& operator= (const vector& x) {
            sz = x.size();
            cp = x.capacity();
            arr = this->alloc.allocate(sizeof(value_type) * cp);
            for (size_t i = 0; i < sz; ++i)
                this->alloc.construct(arr + i, x[i]);
            return *this;
        }

        friend bool operator==(const vector& lhs, const vector& rhs) {
            size_type size = lhs.size();
            if (size != rhs.size()) return false;
            for (size_t i = 0; i < size; i++)
                if (lhs[i] != rhs[i])
                    return false;
            return true;
        }


        void reserve(size_type new_cap) {
            if (new_cap < cp) return;
            cp = new_cap;
            value_type *old_arr = arr;
            arr = this->alloc.allocate(sizeof(value_type) * cp);
            for (size_t i = 0; i < sz; ++i)
                this->alloc.construct(arr + i, old_arr[i]);
        }

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
                if (cp == 0) cp = 1;
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

        void clear() {}

        value_type* data() {return &this->arr.front();}

        const value_type* data() const {return &this->arr.front();}

        void swap (vector& x) {
            size_type tmp_sz = x.size();
            size_type tmp_cp = x.capacity();
            value_type *tmp_arr = arr;

            x.cp = cp;
            cp = tmp_cp;
            x.sz = sz;
            sz = tmp_sz;

            arr = x.arr;
            x.arr = tmp_arr;
        }

    private:
        value_type *arr;
        size_type sz;
        size_type cp;
        allocator_type alloc;
    };
}
