#pragma once

namespace ft {

    template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
    class set {

    public:
        typedef T key_type;
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef Compare key_compare;
        typedef value_type *pointer;
        typedef value_type &reference;
        typedef const value_type *const_pointer;
        typedef const value_type &const_reference;
        typedef size_t size_type;
        typedef MapIterator<value_type> iterator;
        typedef MapIterator<const value_type> const_iterator;
        typedef ReverseMapIterator<value_type> reverse_iterator;
        typedef ReverseMapIterator<const value_type> const_reverse_iterator;
        typedef rbNode<value_type> rbnode;
        typedef rbNode<value_type> *node_pointer;
        typedef rbNode<value_type> &node_reference;
        typedef typename allocator_type::template rebind<rbnode>::other node_allocator;

        class value_compare: public std::binary_function<value_type, value_type, bool> {
        public:
            key_compare _comp;
            explicit value_compare(key_compare comp): _comp(comp) {};
            bool operator()(const value_type &x, const value_type &y) const {return _comp(x, y);};
        };

    private:
        enum Direction {
            _RIGHT,
            _LEFT
        };
        enum Color {
            _BLACK,
            _RED
        };

        node_allocator _alloc_node;
        allocator_type _alloc_value;
        key_compare _comp;
        node_pointer _root;
        size_type _size;
        node_pointer _end;
        node_pointer _begin;

        void initset() {
            _end = _alloc_node.allocate(1);
            _end->parent = nullptr;
            _end->left = nullptr;
            _end->right = nullptr;
            _end->data = _alloc_value.allocate(0);
            _end->color = _BLACK;
            _begin = _alloc_node.allocate(1);
            _begin->parent = nullptr;
            _begin->left = nullptr;
            _begin->right = nullptr;
            _begin->data = _alloc_value.allocate(0);
            _begin->color = _BLACK;
        };

        void deleteNode(node_pointer node) {
            _alloc_value.destroy(node->data);
            _alloc_value.deallocate(node->data, 1);
            _alloc_node.deallocate(node, 1);
            _size--;
        };

        node_pointer getMaxFromIt(node_pointer node) {
            node_pointer tmp = node;
            for (; tmp && tmp->right; tmp = tmp->right);
            return tmp;
        };

        node_pointer getMinFromIt(node_pointer node) {
            node_pointer tmp = node;
            for (; tmp && tmp->left; tmp = tmp->left);
            return tmp;
        };

        node_pointer getUncle(node_pointer node) {
            node_pointer grandParent = getGrandParent(node);
            if (!grandParent)
                return nullptr;
            if (isOnLeft(node->parent))
                return grandParent->right;
            else
                return grandParent->left;
        };

        node_pointer createNode(value_type val){
            node_pointer newElem = _alloc_node.allocate(1);
            newElem->parent = nullptr;
            newElem->right = nullptr;
            newElem->left = nullptr;
            newElem->color = _RED;
            newElem->data = _alloc_value.allocate(1);
            _alloc_value.construct(newElem->data, val);
            _size++;
            return newElem;
        };

        node_pointer getGrandParent(node_pointer node) {
            if (node && node->parent)
                return node->parent->parent;
            return nullptr;
        };

        void relinkTreeEnd() {
            if (!_size)
                return;
            node_pointer min = getMinFromIt(_root);
            node_pointer max = getMaxFromIt(_root);
            min->left = _begin;
            max->right = _end;
            _begin->parent = min;
            _end->parent = max;
        };

        void rotation(node_pointer node, Direction direction) {
            if (direction == _LEFT) {
                node_pointer pivot = node->right;
                node->right = pivot->left;
                if (pivot->left)
                    pivot->left->parent = node;
                pivot->parent = node->parent;
                if (!node->parent)
                    _root = pivot;
                else if (node == node->parent->left)
                    node->parent->left = pivot;
                else
                    node->parent->right = pivot;
                pivot->left = node;
                node->parent = pivot;
            }
            else if (direction == _RIGHT) {
                node_pointer pivot = node->left;
                node->left = pivot->right;
                if (pivot->right)
                    pivot->right->parent = node;
                pivot->parent = node->parent;
                if (!node->parent)
                    _root = pivot;
                else if (node == node->parent->left)
                    node->parent->left = pivot;
                else
                    node->parent->right = pivot;
                pivot->right = node;
                node->parent = pivot;
            }
        };

        bool isOnLeft(node_pointer node) {
            return node == node->parent->left;
        };

    public:

        explicit set(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) :
                _alloc_value(alloc), _comp(comp), _root(nullptr), _size(0) {
            initset();
        };

        template<class InputIterator>
        set(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type(),
            typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type * = 0):
                _alloc_value(alloc), _comp(comp), _root(nullptr), _size(0) {
            initset();
            insert(first, last);
        };

        set(const set &x) : _root(nullptr), _size(0) {
            if (this == &x)
                return;
            *this = x;
        };

        set &operator=(const set &x) {
            clear();
            _alloc_value = x._alloc_value;
            _comp = x._comp;
            insert(x.begin(), x.end());
        };

        virtual ~set() {
            clear();
            _alloc_value.destroy(_end->data);
            _alloc_value.destroy(_begin->data);
            _alloc_value.deallocate(_begin->data, 1);
            _alloc_value.deallocate(_end->data, 1);
            _alloc_node.destroy(_end);
            _alloc_node.destroy(_begin);
            _alloc_node.deallocate(_begin, 1);
            _alloc_node.deallocate(_end, 1);
        };

        iterator begin() {
            if (!_size)
                return iterator(_end);
            return iterator(_begin->parent);
        };

        const_iterator begin() const {
            if (!_size)
                return const_iterator(_end);
            return const_iterator(_begin->parent);
        };

        reverse_iterator rbegin() {
            if (!_size)
                return reverse_iterator(_begin);
            return reverse_iterator(_end->parent);
        };

        const_reverse_iterator rbegin() const {
            if (!_size)
                return const_reverse_iterator(_begin);
            return const_reverse_iterator(_end->parent);
        };

        iterator end() { return iterator(_end); };
        const_iterator end() const { return const_iterator(_end); };
        reverse_iterator rend() { return reverse_iterator(_begin); };
        const_reverse_iterator rend() const { return const_reverse_iterator(_begin); };

        void standartBstInsertion(value_type val) {
            node_pointer elem = createNode(val);
            node_pointer parent = nullptr;
            node_pointer tmp = _root;
            while (tmp) {
                parent = tmp;
                if (!_comp(val, *(tmp->data)))
                    tmp = tmp->right;
                else
                    tmp = tmp->left;
            }
            elem->parent = parent;
            if (!parent) {
                _root = elem;
                _root->color = _BLACK;
                return;
            }
            else if (_comp(*(parent->data), val))
                parent->right = elem;
            else
                parent->left = elem;
            if (!elem->parent->parent)
                return;
            rbInsertion(elem);
        };

        void rbInsertion(node_pointer tmp) {
            node_pointer uncle;
            while (tmp->parent && tmp->parent->color == _RED) {
                if (tmp->parent == tmp->parent->parent->right) {
                    uncle = tmp->parent->parent->left;
                    if (uncle && uncle->color == _RED) {
                        uncle->color = _BLACK;
                        tmp->parent->color = _BLACK;
                        tmp->parent->parent->color = _RED;
                        tmp = tmp->parent->parent;
                    }
                    else {
                        if (tmp == tmp->parent->left) {
                            tmp = tmp->parent;
                            rotation(tmp, _RIGHT);
                        }
                        tmp->parent->color = _BLACK;
                        tmp->parent->parent->color = _RED;
                        rotation(tmp->parent->parent, _LEFT);
                    }
                }
                else {
                    uncle = tmp->parent->parent->right;
                    if (uncle && uncle->color == _RED) {
                        uncle->color = _BLACK;
                        tmp->parent->color = _BLACK;
                        tmp->parent->parent->color = _RED;
                        tmp = tmp->parent->parent;
                    }
                    else {
                        if (tmp == tmp->parent->right) {
                            tmp = tmp->parent;
                            rotation(tmp, _LEFT);
                        }
                        tmp->parent->color = _BLACK;
                        tmp->parent->parent->color = _RED;
                        rotation(tmp->parent->parent, _RIGHT);
                    }
                }
                if (tmp == _root)
                    break;
            }
            _root->color = _BLACK;
        };

        void unlink() {
            if (_begin->parent)
                _begin->parent->left = nullptr;
            if (_end->parent)
                _end->parent->right = nullptr;
        }

        void transplant(node_pointer u, node_pointer v) {
            if (u && !u->parent)
                _root = v;
            else if (isOnLeft(u))
                u->parent->left = v;
            else
                u->parent->right = v;
            if (v)
                v->parent = u->parent;
        };

        void deleteFromTree(node_pointer node) {
            node_pointer y(node), x;
            int savedColor = y->color;
            if (!node->left) {
                x = node->right;
                transplant(node, node->right);
            }
            else if (!node->right) {
                x = node->left;
                transplant(node, node->left);
            }
            else {
                y = getMinFromIt(node->right);
                savedColor = y->color;
                x = y->right;
                if (node == y->parent) {
                    if (x)
                        x->parent = y;
                }
                else {
                    transplant(y, y->right);
                    y->right = node->right;
                    y->right->parent = y;
                }
                transplant(node, y);
                y->left = node->left;
                y->left->parent = y;
                y->color = node->color;
            }
            if (savedColor == _BLACK)
                fixTreeAfterDeletion(x);
            deleteNode(node);
        };

        void fixTreeAfterDeletion(node_pointer x) {
            if (!x)
                return;
            while (x != _root and x->color == _BLACK) {
                if (x == x->parent->left) {
                    node_pointer w = x->parent->right;
                    if (w->color == _RED) {
                        w->color = _BLACK;
                        x->parent->color = _RED;
                        rotation(x->parent, _LEFT);
                        w = x->parent->right;
                    }
                    if (w->left->color == _BLACK and w->right->color == _BLACK) {
                        w->color = _RED;
                        x = x->parent;
                    }
                    else {
                        if (w->right->color == _BLACK) {
                            w->left->color = _BLACK;
                            w->color = _RED;
                            rotation(w, _RIGHT);
                            w = x->parent->right;
                        }
                        else {
                            w->color = x->parent->color;
                            w->parent->color = _BLACK;
                            w->right->color = _BLACK;
                            rotation(x->parent, _LEFT);
                            x = _root;
                        }
                    }
                }
                else {
                    node_pointer w = x->parent->left;
                    if (w->color == _RED) {
                        w->color = _BLACK;
                        x->parent->color = _RED;
                        rotation(x->parent, _RIGHT);
                        w = x->parent->left;
                    }
                    if (w->right->color == _BLACK and w->left->color == _BLACK) {
                        w->color = _RED;
                        x = x->parent;
                    }
                    else {
                        if (w->left->color == _BLACK) {
                            w->right->color = _BLACK;
                            w->color = _RED;
                            rotation(w, _LEFT);
                            w = x->parent->left;
                        }
                        else {
                            w->color = x->parent->color;
                            x->parent->color = _BLACK;
                            w->left->color = _BLACK;
                            rotation(x->parent, _RIGHT);
                            x = _root;
                        }
                    }
                }
            }
            x->color = _BLACK;
        };

        std::pair<iterator, bool> insert(const value_type &val) {
            iterator found = find(val);
            if (found != end()) {
                return std::pair<iterator, bool>(found, false);
            }
            unlink();
            standartBstInsertion(val);
            relinkTreeEnd();
            found = find(val);
            return std::pair<iterator, bool>(found, true);
        };

        template<class InputIterator>
        void insert(InputIterator first, InputIterator last,
                    typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type * = 0) {
            for (; first != last; first++)
                insert(*first);
        };

        iterator insert(iterator position, const value_type &val) {
            (void) position;
            return insert(val);
        };

        iterator find(const key_type &k) {
            iterator it = begin();
            for (iterator ite = end(); it != ite && *it != k; it++);
            return it;
        };

        const_iterator find(const key_type &k) const {
            const_iterator it = begin();
            for (const_iterator ite = end(); it != ite && *it != k; it++);
            return it;
        };

        size_type max_size() const {  return _alloc_value.max_size() / sizeof(node_pointer); };
        size_type size() const { return _size; };
        bool empty() const { return _size == 0; };

        void clear() {
            while (_size)
                erase(begin());
        };

        void erase(iterator position) {
            erase(*position);
        };

        size_type erase(const key_type &k) {
            node_pointer tmp = _root;
            unlink();
            while (tmp) {
                if (k == *(tmp->data)) {
                    deleteFromTree(tmp);
                    relinkTreeEnd();
                    return 1;
                }
                if (_comp(k, *(tmp->data)))
                    tmp = tmp->left;
                else
                    tmp = tmp->right;
            }
            relinkTreeEnd();
            return 0;
        };

        void erase(iterator first, iterator last) {
            for (; first != last; first++)
                erase(first);
        };

        key_compare key_comp() const {return _comp;};

        value_compare value_comp() const {return value_compare(_comp);};

        void swap(set &x) {
            ft::swap(_size, x._size);
            ft::swap(_root, x._root);
            ft::swap(_begin, x._begin);
            ft::swap(_end, x._end);
        };

        size_type count(const key_type& k) const {
            for (iterator it = begin(), ite = end(); it != ite; it++)
                if (it == k)
                    return 1;
            return 0;
        };

        iterator lower_bound (const key_type& k) {
            iterator it = begin();
            for (iterator ite = end(); it != ite && _comp(*it, k); it++);
            return it;
        };

        const_iterator lower_bound (const key_type& k) const {
            const_iterator it = begin();
            for (const_iterator ite = end(); it != ite && _comp(*it, k); it++);
            return it;
        };

        iterator upper_bound (const key_type& k) {
            iterator it = lower_bound(k);
            if (it != end())
                return ++it;
            return it;
        };
        const_iterator upper_bound (const key_type& k) const {
            const_iterator it = lower_bound(k);
            if (it != end())
                return ++it;
            return it;
        };

        std::pair<const_iterator, const_iterator> equal_range (const key_type& k) const {
            return std::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
        };

        std::pair<iterator, iterator> equal_range (const key_type& k) {
            return std::pair<iterator, iterator>(lower_bound(k), upper_bound(k));
        };
    };

}