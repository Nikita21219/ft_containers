#include "containers.h"
#ifndef VECTOR_HPP
#define VECTOR_HPP

namespace ft {
    template <typename T, typename Alloc = std::allocator<T> >
    class vector {
    public:
        typedef          Alloc                                       allocator_type;
        typedef          T                                           value_type;
        typedef          size_t                                      size_type;
        typedef typename allocator_type::reference                   reference;
        typedef typename allocator_type::pointer                     pointer;
        typedef typename allocator_type::const_reference             const_reference;
        typedef typename allocator_type::const_pointer               const_pointer;
        typedef ft::RandAccessIt<value_type>                         iterator;
        typedef ft::RandAccessIt<const value_type>                   const_iterator;
        typedef typename iterator::difference_type                   difference_type;
        typedef ft::ReverseRandAccessIt<iterator>                    reverse_iterator;
        typedef ft::ReverseRandAccessIt<const_iterator>              const_reverse_iterator;

        explicit vector(const allocator_type& alloc = allocator_type()):
        alloc(alloc), cp(0), sz(0) {
            arr = this->alloc.allocate(cp);
        }

        explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):
        alloc(alloc), cp(n), sz(n) {
            arr = this->alloc.allocate(sizeof(value_type) * n);
            for (size_t i = 0; i < sz; ++i)
                this->alloc.construct(arr + i, val);
        }

        vector(const vector& x):
        alloc(x.alloc), cp(x.capacity()), sz(x.size()) {
            arr = this->alloc.allocate(sizeof(value_type) * cp);
            for (size_t i = 0; i < cp; ++i)
                this->alloc.construct(arr + i, x[i]);
        }

        template <typename Iter>
        vector(Iter first, Iter last, typename ft::enable_if<!ft::is_integral<Iter>::value, Iter>::type* = NULL, const allocator_type &alloc = allocator_type()):
        alloc(alloc), cp(0), sz(0) {
            arr = this->alloc.allocate(cp);
            assign(first, last);
        }

        ~vector() {
            for (size_t i = 0; i < sz; ++i)
                this->alloc.destroy(arr + i);
            this->alloc.deallocate(arr, cp);
        }

        reference operator[] (size_type n) const       {return *(arr + n);}
        size_type capacity() const                     {return cp;}
        size_type size() const                         {return sz;}
        bool empty() const                             {return sz == 0;}
        reference front()                              {return arr[0];}
        const_reference front() const                  {return arr[0];}
        reference back()                               {return arr[sz - 1];}
        const_reference back() const                   {return arr[sz - 1];}
        allocator_type get_allocator() const           {return alloc;}
        iterator begin()                               {return iterator(arr);}
        iterator end()                                 {return iterator(arr + sz);}
        const_iterator cbegin() const                  {return const_iterator(arr);}
        const_iterator cend() const                    {return const_iterator(arr + sz);}
        reverse_iterator rbegin()                      {return reverse_iterator(--end());}
        reverse_iterator rend()                        {return reverse_iterator(--begin());}
        const_reverse_iterator crbegin() const         {return const_reverse_iterator(--cend());}
        const_reverse_iterator crend() const           {return const_reverse_iterator(--cbegin());}
        value_type* data()                             {return &this->arr.front();}
        const value_type* data() const                 {return &this->arr.front();}
        void pop_back()                                {alloc.destroy(arr + (sz-- - 1));}
        void clear()                                   {erase(begin(), end());}
        size_type max_size() const                     {return std::numeric_limits<difference_type>::max();} //TODO may be alloc.max_size()

        vector& operator= (const vector& x) {
            memory_reserve(x.capacity());
            sz = x.size();
            for (size_t i = 0; i < sz; ++i)
                alloc.construct(arr + i, x[i]);
            return *this;
        }

        iterator erase(iterator pos) {
            size_type idx = 0;
            for (iterator i = begin(); i != end(); i++) {
                if (i == pos) {
                    alloc.destroy(arr + idx);
                    sz--;
                    for (size_type j = idx; j < sz; j++) {
                        alloc.construct(arr + j, *(arr + j + 1));
                    }
                    break;
                }
                idx++;
            }
            return pos;
        }

        // iterator erase(iterator pos) {
        //     std::move(pos, end(), pos - 1);
        //     sz--;
        //     return pos;
        // }

        iterator erase(iterator first, iterator last) {
            std::move(last, end(), first);
            sz -= std::distance(first, last);
            return first;
        }

        void reserve(size_type new_cap) {
            if (new_cap < cp) return;
            memory_reserve(new_cap);
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
                if (cp == 0)
                    memory_reserve(1);
                else
                    memory_reserve(cp * 2);
            }
            alloc.construct(arr + sz, val);
            sz++;
        }

        void swap (vector& x) {
            size_type tmp_sz = x.size();
            size_type tmp_cp = x.capacity();
            pointer tmp_arr = arr;

            x.cp = cp;
            cp = tmp_cp;
            x.sz = sz;
            sz = tmp_sz;

            arr = x.arr;
            x.arr = tmp_arr;
        }

        void assign(size_type n, const value_type &val) {
            if (cp != n)
                memory_reserve(n);
            sz = 0;
            while (sz != n) {
                alloc.construct(arr + sz, val);
                sz++;
            }
        }

        template <typename Iter>
        void assign(Iter first, Iter last, typename ft::enable_if<!ft::is_integral<Iter>::value, Iter>::type* = NULL) {
            if (cp < static_cast<size_type>(std::distance(first, last)))
                memory_reserve(std::distance(first, last));
            sz = 0;
            while (first != last)
                alloc.construct(arr + sz++, *first++);
        }

        void resize(size_type n, value_type val = value_type()) {
            if (cp == n) return;
            if (sz > n) {
                size_type end = sz + (sz - n);
                for (size_type i = sz; i < end; i++) {
                    alloc.destroy(arr + i);
                    sz--;
                }
            }
            else if (sz < n) {
                if (cp < n) {
                    size_type new_cap = cp * 2 < n ? n : cp * 2;
                    reserve(new_cap);
                }
                for (size_t i = sz; i < n; i++) {
                    alloc.construct(arr + i, val);
                    sz++;
                }
            }
        }

        iterator insert(iterator pos, const value_type& val) {
            iterator result = NULL;
            value_type tmp_val;
            value_type tmp_val2;
            if (sz < cp) {
                iterator it = begin();
                iterator it_end = end();
                if (pos == it_end) {
                    *it_end = val;
                    sz++;
                    return it;
                }
                while (it != it_end) {
                    if (it == pos) {
                        tmp_val = *it;
                        *it = val;
                        result = it;
                        sz++;
                        break;
                    }
                    it++;
                }
                it++;
                tmp_val2 = *it;
                while (it != it_end) {
                    tmp_val2 = tmp_val;
                    tmp_val = *it;
                    *it++ = tmp_val2;
                }
                *it = tmp_val;
            } else if (sz == cp) {
                pointer copy_arr = get_copy_arr(cp * 2);
                iterator copy_it = iterator(copy_arr);
                if (pos == end()) {
                    result = iterator(copy_it + sz);
                    *result = val;
                    return result;
                }
                iterator it = begin();
                while (it != end()) {
                    if (it == pos) {
                        tmp_val = *copy_it;
                        *copy_it = val;
                        result = copy_it;
                        sz++;
                        break;
                    }
                    it++;
                    copy_it++;
                }
                it++;
                copy_it++;
                tmp_val2 = *copy_it;
                while (copy_it != iterator(copy_arr + sz)) {
                    tmp_val2 = tmp_val;
                    tmp_val = *copy_it;
                    *copy_it++ = tmp_val2;
                }
                *copy_it = tmp_val;
                for (size_type i = 0; i < sz - 1; ++i)
                    alloc.destroy(arr + i);
                alloc.deallocate(arr, cp);
                cp *= 2;
                arr = copy_arr;
            }
            return result;
        }

        iterator insert(iterator position, size_type n, const value_type& val) {
            size_type new_capacity = cp;
            while (new_capacity < cp + n) {
                new_capacity += sz + n > cp ? cp * 2 : cp;
                if (new_capacity > alloc.max_size()) throw std::bad_alloc();
            }
            pointer new_arr = this->alloc.allocate(sizeof(value_type) * (new_capacity));
            iterator it = begin();
            size_type i = 0;
            size_type count = 0;
            iterator result;
            while (i <= sz + n) {
                if (it == position) {
                    result = iterator(new_arr + i);
                    while (++count <= n)
                        alloc.construct(new_arr + i++, val);
                }
                alloc.construct(new_arr + i, *it++);
                i++;
            }
            for (size_type i = 0; i < sz; i++)
                alloc.destroy(arr + i);
            alloc.deallocate(arr, cp);
            arr = new_arr;
            cp = new_capacity;
            sz += n;
            return result;
        }

        template <class Iter>
        iterator insert(iterator position, Iter first, Iter last, typename ft::enable_if<!ft::is_integral<Iter>::value, Iter>::type* = NULL) {
            difference_type dist = std::distance(first, last);
            size_type new_capacity = sz + dist > cp ? cp * 2 : cp;
            if (sz + dist >= cp * 2)
                new_capacity = sz + dist;
            if (new_capacity > alloc.max_size()) throw std::bad_alloc();
            pointer new_arr = alloc.allocate(sizeof(value_type) * (new_capacity));
            iterator it = begin();
            size_type i = 0;
            iterator result;
            iterator ptr;
            while (i <= sz + dist) {
                if (it == position) {
                    result = iterator(new_arr + i);
                    while (first != last) {
                        try {
                            alloc.construct(new_arr + i++, *first++);
                        }
                        catch (...) {
                            for (size_t idx = 0; idx < i; idx++)
                                alloc.destroy(new_arr + idx);
                            alloc.deallocate(new_arr, new_capacity);
                            throw std::exception();
                        }
                    }
                }
                alloc.construct(new_arr + i, *it++);
                i++;
            }
            for (size_type i = 0; i < sz; i++)
                alloc.destroy(arr + i);
            alloc.deallocate(arr, cp);
            arr = new_arr;
            cp = new_capacity;
            sz += dist;
            return result;
        }

    private:
        pointer arr;
        allocator_type alloc;
        size_type cp;
        size_type sz;

        void memory_reserve(size_type new_cap) {
            if (new_cap > alloc.max_size()) throw std::bad_alloc();
            pointer new_arr = alloc.allocate(sizeof(value_type) * new_cap);
            for (size_type i = 0; i < sz; ++i) {
                alloc.construct(new_arr + i, arr[i]);
                alloc.destroy(arr + i);
            }
            alloc.deallocate(arr, cp);
            arr = new_arr;
            cp = new_cap;
        }

        pointer get_copy_arr(size_type new_cap) {
            if (new_cap > alloc.max_size()) throw std::bad_alloc();
            pointer new_arr = alloc.allocate(sizeof(value_type) * new_cap);
            for (size_type i = 0; i < sz; ++i)
                alloc.construct(new_arr + i, arr[i]);
            return new_arr;
        }

    };

    template <typename T, typename Alloc>
    bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
        size_t size = lhs.size();
        if (size != rhs.size()) return false;
        for (size_t i = 0; i < size; i++)
            if (lhs[i] != rhs[i])
                return false;
        return true;
    }

    template <class T, class Alloc>
    bool operator<(const vector<T, Alloc>& l, const vector<T, Alloc>& r) {
        return ft::lexicographical_compare(l.cbegin(), l.cend(), r.cbegin(), r.cend());
    }

    template <class T, class Alloc>
    bool operator<=(const vector<T, Alloc>& l, const vector<T, Alloc>& r) {return !(r < l);}

    template <typename T, typename Alloc>
    bool operator!=(const vector<T, Alloc>& l, const vector<T, Alloc>& r) {return !(l == r);}

    template <class T, class Alloc>
    bool operator>(const vector<T, Alloc>& l, const vector<T, Alloc>& r) {return r < l;}

    template <class T, class Alloc>
    bool operator>=(const vector<T, Alloc>& l, const vector<T, Alloc>& r) {return !(l < r);}

};
#endif