#pragma once
#include <iostream>
#include <memory>

namespace ft {

    template<class T>
    struct Node {
        T *content;
        Node *next;
        Node *prev;
    };

    template<typename T>
    void swap(T &a, T &b) {
        T tmp = a;
        a = b;
        b = tmp;
    };

    template<class T>
    class ListIterator {

    public:
        typedef T &reference;
        typedef T valueType;
        typedef Node<T> *pointer;

    protected:
        pointer _ptr;

    public:
        ListIterator() : _ptr(nullptr) {};

        ListIterator(ListIterator const &other) {
            *this = other;
        }

        ListIterator(pointer ptr) : _ptr(ptr) {};

        virtual ~ListIterator() {};

        pointer getNode() const { return _ptr; }

        ListIterator &operator=(ListIterator const &other) {
            _ptr = other._ptr;
            return *this;
        }

        ListIterator &operator++() {
            _ptr = _ptr->next;
            return *this;
        }

        ListIterator operator++(int) {
            ListIterator tmp(*this);
            _ptr = _ptr->next;
            return (tmp);
        }

        ListIterator &operator--() {
            _ptr = _ptr->prev;
            return *this;
        }

        ListIterator operator--(int) {
            ListIterator tmp(*this);
            _ptr = _ptr->prev;
            return (tmp);
        }

        bool operator==(ListIterator const &other) const { return _ptr == other._ptr; };

        bool operator!=(ListIterator const &other) const { return _ptr != other._ptr; };

        bool operator>(ListIterator const &other) const { return _ptr > other._ptr; };

        bool operator>=(ListIterator const &other) const { return _ptr >= other._ptr; };

        bool operator<(ListIterator const &other) const { return _ptr < other._ptr; };

        bool operator<=(ListIterator const &other) const { return _ptr <= other._ptr; };

        valueType &operator*() { return *(_ptr->content); };
    };

    template<class T>
    class ConstListIterator {

    public:
        typedef T &reference;
        typedef T valueType;
        typedef Node<T> *pointer;

    private:
        pointer _ptr;

    public:
        ConstListIterator() : _ptr(nullptr) {};

        ConstListIterator(ConstListIterator const &other) {
            *this = other;
        }

        ConstListIterator(pointer ptr) : _ptr(ptr) {};

        virtual ~ConstListIterator() {};

        pointer getNode() const { return _ptr; }

        ConstListIterator &operator=(ConstListIterator const &other) {
            _ptr = other._ptr;
            return *this;
        }

        ConstListIterator &operator++() {
            _ptr = _ptr->next;
            return *this;
        }

        ConstListIterator operator++(int) {
            ConstListIterator tmp(*this);
            _ptr = _ptr->next;
            return (tmp);
        }

        ConstListIterator &operator--() {
            _ptr = _ptr->prev;
            return *this;
        }

        ConstListIterator operator--(int) {
            ConstListIterator tmp(*this);
            _ptr = _ptr->prev;
            return (tmp);
        }

        bool operator==(ConstListIterator const &other) const { return _ptr == other._ptr; };

        bool operator!=(ConstListIterator const &other) const { return _ptr != other._ptr; };

        bool operator>(ConstListIterator const &other) const { return _ptr > other._ptr; };

        bool operator>=(ConstListIterator const &other) const { return _ptr >= other._ptr; };

        bool operator<(ConstListIterator const &other) const { return _ptr < other._ptr; };

        bool operator<=(ConstListIterator const &other) const { return _ptr <= other._ptr; };

        valueType &operator*() const { return *(_ptr->content); };
    };

    template<class T>
    class ReverseListIterator {

    public:
        typedef T &reference;
        typedef T valueType;
        typedef Node<T> *pointer;

    protected:
        pointer _ptr;

    public:
        ReverseListIterator() {};

        ReverseListIterator(ReverseListIterator const &other) {
            *this = other;
        }

        ReverseListIterator(pointer ptr) : _ptr(ptr) {};

        virtual ~ReverseListIterator() {};

        pointer getNode() const {
            return _ptr;
        }

        ReverseListIterator &operator=(ReverseListIterator const &other) {
            _ptr = other._ptr;
            return *this;
        }

        ReverseListIterator &operator++() {
            _ptr = _ptr->prev;
            return *this;
        }

        ReverseListIterator operator++(int) {
            ReverseListIterator tmp(*this);
            _ptr = _ptr->prev;
            return (tmp);
        }

        ReverseListIterator &operator--() {
            _ptr = _ptr->next;
            return *this;
        }

        ReverseListIterator operator--(int) {
            ReverseListIterator tmp(*this);
            _ptr = _ptr->next;
            return (tmp);
        }

        bool operator==(ReverseListIterator const &other) const { return _ptr == other._ptr; };
        bool operator!=(ReverseListIterator const &other) const { return _ptr != other._ptr; };
        bool operator>(ReverseListIterator const &other) const { return _ptr > other._ptr; };
        bool operator>=(ReverseListIterator const &other) const { return _ptr >= other._ptr; };
        bool operator<(ReverseListIterator const &other) const { return _ptr < other._ptr; };
        bool operator<=(ReverseListIterator const &other) const { return _ptr <= other._ptr; };
        valueType &operator*() { return *(_ptr->content); };
    };

    template<class T>
    class ConstReverseListIterator {

    public:
        typedef T &reference;
        typedef T valueType;
        typedef Node<T> *pointer;

    protected:
        pointer _ptr;

    public:
        ConstReverseListIterator() {};
        ConstReverseListIterator(ConstReverseListIterator const &other) {
            *this = other;
        }

        ConstReverseListIterator(pointer ptr) : _ptr(ptr) {};

        virtual ~ConstReverseListIterator() {};

        pointer getNode() const {
            return _ptr;
        }

        ConstReverseListIterator &operator=(ConstReverseListIterator const &other) {
            _ptr = other._ptr;
            return *this;
        }

        ConstReverseListIterator &operator++() {
            _ptr = _ptr->prev;
            return *this;
        }

        ConstReverseListIterator operator++(int) {
            ConstReverseListIterator tmp(*this);
            _ptr = _ptr->prev;
            return (tmp);
        }

        ConstReverseListIterator &operator--() {
            _ptr = _ptr->next;
            return *this;
        }

        ConstReverseListIterator operator--(int) {
            ConstReverseListIterator tmp(*this);
            _ptr = _ptr->next;
            return (tmp);
        }

        bool operator==(ConstReverseListIterator const &other) const { return _ptr == other._ptr; };
        bool operator!=(ConstReverseListIterator const &other) const { return _ptr != other._ptr; };
        bool operator>(ConstReverseListIterator const &other) const { return _ptr > other._ptr; };
        bool operator>=(ConstReverseListIterator const &other) const { return _ptr >= other._ptr; };
        bool operator<(ConstReverseListIterator const &other) const { return _ptr < other._ptr; };
        bool operator<=(ConstReverseListIterator const &other) const { return _ptr <= other._ptr; };
        valueType &operator*() const { return *(_ptr->content); };
    };

    template<bool B, class T = void>
    struct enable_if {};

    template<class T>
    struct enable_if<true, T> {
        typedef T type;
    };

    template<class T>
    struct is_iterator{static const bool value = true;};
    template<>
    struct is_iterator<int>{static const bool value = false;};
    template<>
    struct is_iterator<bool>{static const bool value = false;};
    template<>
    struct is_iterator<char>{static const bool value = false;};
    template<>
    struct is_iterator<unsigned int>{static const bool value = false;};
    template<>
    struct is_iterator<long>{static const bool value = false;};
    template<>
    struct is_iterator<long long>{static const bool value = false;};

    template<class T, class Alloc = std::allocator<T> >
    class list {

    public:

        typedef T valueType;
        typedef Alloc allocator_type;
        typedef Node<valueType>  node;
        typedef Node<valueType>* node_ptr;
        typedef Node<valueType>& node_ref;
        typedef typename allocator_type::template rebind<node>::other node_allocator;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename std::ptrdiff_t difference_type;
        typedef unsigned long size_type;
        typedef ListIterator<valueType> iterator;
        typedef ConstListIterator<valueType> const_iterator;
        typedef ReverseListIterator<valueType> reverse_iterator;
        typedef ConstReverseListIterator<valueType> const_reverse_iterator;

    private:
        node_ptr _emptyNode;
        allocator_type _allocator;
        node_allocator _node_allocator;
        size_type _size;

        void initList() {
            _emptyNode = _node_allocator.allocate(1);
            _emptyNode->content = _allocator.allocate(1);
            _emptyNode->next = _emptyNode;
            _emptyNode->prev = _emptyNode;
        };

        node_ptr addNewNode(valueType const &val, node_ptr next, node_ptr prev) {
            node_ptr newNode = _node_allocator.allocate(1);
            newNode->content = _allocator.allocate(1);
            _allocator.construct(newNode->content, val);
            newNode->next = next;
            newNode->prev = prev;
            _size++;
            return newNode;
        };

        void destroyNode(node_ptr node) {
            node->next->prev = node->prev;
            node->prev->next = node->next;
            _allocator.destroy(node->content);
            _allocator.deallocate(node->content, 1);
            _node_allocator.destroy(node);
            _node_allocator.deallocate(node, 1);
            _size--;
        };

    public:

        explicit list(allocator_type const &alloc = allocator_type()) :
                _emptyNode(nullptr), _allocator(alloc), _size(0) {
            initList();
        };

        explicit list(size_type n, valueType const &val = valueType(),
                      allocator_type const &alloc = allocator_type()) :
                _emptyNode(nullptr), _allocator(alloc), _size(0) {
            initList();
            assign(n, val);
        };

        template<class InputIterator>
        list(InputIterator first, InputIterator last,
             const allocator_type &alloc = allocator_type(),
             typename ft::enable_if<ft::is_iterator<InputIterator>::value>::type* = 0):
             _emptyNode(nullptr), _allocator(alloc), _size(0) {
            initList();
            assign(first, last);
        };

        list(const list &x) {
            initList();
            *this = x;
        };

        ~list() {
            clear();
            _allocator.destroy(_emptyNode->content);
            _allocator.deallocate(_emptyNode->content, 1);
            _node_allocator.destroy(_emptyNode);
            _node_allocator.deallocate(_emptyNode, 1);
        }

        list &operator=(const list &x) {
            if (this == &x)
                return (*this);
            clear();
            assign(x.begin(), x.end());
            return (*this);
        };

        iterator begin() { return iterator(_emptyNode->next); };
        iterator end() { return iterator(_emptyNode); };
        const_iterator begin() const { return const_iterator(_emptyNode->next); };
        const_iterator end() const { return const_iterator(_emptyNode); };
        reverse_iterator rbegin() { return _emptyNode->prev; };
        const_reverse_iterator rbegin() const { return const_reverse_iterator(_emptyNode->prev); };
        reverse_iterator rend() { return _emptyNode; };
        const_reverse_iterator rend() const { return const_reverse_iterator(_emptyNode); };

        template<class InputIterator>
        void assign(InputIterator first, InputIterator last, typename ft::enable_if<ft::is_iterator<InputIterator>::value>::type* = 0) {
            clear();
            while (first != last)
                push_back(*first++);
        };

        void assign(size_type n, const valueType &val) {
            clear();
            while (n--) {
                push_back(val);
            }
        };


        size_type size() const {
            return _size;
        };

        reference front() { return *_emptyNode->next->content; };
        const_reference front() const { return *_emptyNode->next->content; };
        reference back() { return *_emptyNode->prev->content; };
        const_reference back() const { return *_emptyNode->prev->content; };

        void clear() {
            while (_size > 0)
                pop_back();
        }

        void push_back(const valueType &val) {
            node_ptr element = addNewNode(val, _emptyNode, _emptyNode->prev);
            _emptyNode->prev->next = element;
            _emptyNode->prev = element;
        }

        void push_front(const valueType &val) {
            node_ptr element = addNewNode(val, _emptyNode->next, _emptyNode);
            _emptyNode->next->prev = element;
            _emptyNode->next = element;
        }

        void pop_front(){
            destroyNode(_emptyNode->next);
        }

        void pop_back() {
            destroyNode(_emptyNode->prev);
        }

        bool empty() const {
            return _size == 0;
        };

        size_type max_size() const {
            return std::numeric_limits<size_type>::max() / sizeof(Node<valueType>);
        };

        void swap(list &x) {
            ft::swap(_size, x._size);
            ft::swap(_emptyNode, x._emptyNode);
        };

        iterator insert(iterator position, const valueType& val) {
            node_ptr tmp = position.getNode();
            node_ptr newNode = addNewNode(val, tmp, tmp->prev);
            tmp->prev->next = newNode;
            tmp->prev = newNode;
            return iterator(newNode);

        };

        void insert(iterator position, size_type n, const valueType &val) {
            while(n--)
                insert(position, val);
        };

        template<class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<ft::is_iterator<InputIterator>::value>::type* = 0) {
                while (first != last)
                    insert(position, *first++);
        };

        iterator erase(iterator position) {
            node_ptr tmp = position.getNode();
            iterator it(tmp->next);
            destroyNode(tmp);
            return it;
        };

        iterator erase(iterator first, iterator last) {
            while (first != last)
                erase(first++);
            return iterator(last);
        };

        void resize(size_type n, valueType val = valueType()) {
            while (_size > n)
                pop_back();
            while (_size < n)
                push_back(val);
        };

        void splice(iterator position, list& x) {
            splice(position, x, x.begin(), x.end());
        };

        void splice (iterator position, list& x, iterator i) {
            splice(position, x, i, ++i);
        };

        void splice (iterator position, list& x, iterator first, iterator last) {
            size_type i = 0;
            for (iterator counter = first; counter != last; counter++, i++);
            x._size -= i;
            _size += i;
            node_ptr tmpFirst = position.getNode();
            node_ptr firstX = first.getNode();
            node_ptr lastX = last.getNode();
            node_ptr currLastX = lastX->prev;
            firstX->prev->next = lastX;
            lastX->prev = firstX->prev;
            tmpFirst->prev->next = firstX;
            firstX->prev = tmpFirst->prev;
            tmpFirst->prev = currLastX;
            currLastX->next = tmpFirst;
        };

        void remove (const valueType& val) {
            for(iterator it = begin(); it != end(); it++)
                if (*it == val)
                    erase(it);
        };

        template<class Predicate>
        void remove_if(Predicate pred) {
            for(iterator it = begin(); it != end(); it++)
                if (pred(*it))
                    erase(it);
        };

        void unique() {
            iterator it = begin();
            for(; it != end(); it++) {
                iterator it2 = it;
                it2++;
                    for (;*it == *it2; it2++)
                        erase(it2);
            }
        };

        template <class BinaryPredicate>
        void unique(BinaryPredicate binary_pred) {
            for (iterator it = begin(), ite = end(); it != ite;) {
                iterator tmp(it.getNode()->next);
                for (;tmp != ite && binary_pred(*it, *tmp); tmp++);
                if (++it != tmp)
                    it = erase(it, tmp);
            }
        };

        void merge(list& x) {
            if (&x == this)
                return;
            splice(end(), x, x.begin(), x.end());
        };

        template <class Compare>
        void merge (list& x, Compare comp) {
            if (&x == this)
                return;
            iterator it = begin();
            iterator ite = end();
            iterator itX = x.begin();
            iterator iteX = x.end();
            while (it != ite && itX != iteX) {
                while (it != ite && !comp(*it, *itX))
                    it++;
                itX++;
                splice(it, x, iterator(itX.getNode()->prev));
            }
            if (itX != iteX)
                splice(it, x, itX, iteX);
        };

        void sort() {
            for(iterator it = begin(); it != end(); it++) {
                iterator it2 = it;
                it2++;
                for (; it2 != end(); it2++) {
                    if (*it > *it2)
                        ft::swap(*it, *it2);
                }
            }
        };

        template <class Compare>
        void sort(Compare comp) {
            for(iterator it = begin(); it != end(); it++) {
                iterator it2 = it;
                it2++;
                for (; it2 != end(); it2++) {
                    if (comp(*it2, *it))
                        ft::swap(*it, *it2);
                }
            }
        };

        void reverse() {
            if (_size > 1) {
                iterator ite = end();
                node_ptr tmp;
                for(iterator it = begin(); it != ite;) {
                    tmp = it.getNode();
                    ft::swap(tmp->next, tmp->prev);
                    tmp = tmp->prev;
                    it = iterator(tmp);
                }
                tmp = ite.getNode();
                ft::swap(tmp->prev, tmp->next);
            }
        };
    };

    template<typename T>
    bool operator==(list<T> const &l, list<T> const &r) {
        if (l.size() != r.size())
            return false;
        typename list<T>::const_iterator lit = l.begin();
        typename list<T>::const_iterator rit = r.begin();
        for (; lit != l.end(); lit++, rit++)
            if (*lit != *rit)
                return false;
        return true;
    };

    template<typename T>
    bool operator!=(list<T> const &l, list<T> const &r) {
        return !(l == r);
    };

    template<typename T>
    bool operator<(list<T> const &l, list<T> const &r) {
        if (l.size() >= r.size())
            return false;
        typename list<T>::const_iterator lit = l.begin();
        typename list<T>::const_iterator rit = r.begin();
        for (; lit != l.cend(); lit++, rit++)
            if (*lit >= *rit)
                return false;
        return true;
    };

    template<typename T>
    bool operator<=(list<T> const &l, list<T> const &r) {
        if (l.size() > r.size())
            return false;
        typename list<T>::const_iterator lit = l.cbegin();
        typename list<T>::const_iterator rit = r.cbegin();
        for (; lit != l.cend(); lit++, rit++)
            if (*lit > *rit)
                return false;
        return true;
    };

    template<typename T>
    bool operator>(list<T> const &l, list<T> const &r) {
        return !(l < r);
    };

    template<typename T>
    bool operator>=(list<T> const &l, list<T> const &r) {
        return !(l <= r);
    };

    template<class T, class Alloc>
    void swap(list<T, Alloc> &a, list<T, Alloc> &b) {
        a.swap(b);
    };
}

