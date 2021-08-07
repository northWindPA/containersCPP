#pragma once

namespace ft {

    template<class T, class Container = ft::list<T> >
    class stack {

    public:
        typedef T value_type;
        typedef Container container_type;
        typedef size_t size_type;

    protected:
        container_type _cntr;

    public:
        explicit stack(const container_type& cntr = container_type()): _cntr(cntr) {};

        stack(const stack<value_type, container_type> &x): _cntr(x._cntr) {};

        stack &operator=(const stack<value_type, container_type> &x) {
            if (this == &x)
                return ;
            _cntr = x._cntr;
            return *this;
        };

        virtual ~stack() {};
        bool empty() const {return _cntr.empty();};
        value_type& top() {return _cntr.back();};
        const value_type& top() const{return _cntr.back();};
        size_type size() const {return _cntr.size();};
        void push(const value_type& val) {_cntr.push_back(val);};
        void pop() {_cntr.pop_back();};
    };

    template <class T, class Container>
    bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {return lhs._cntr == rhs._cntr;};
    template <class T, class Container>
    bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {return lhs._cntr != rhs._cntr;};
    template <class T, class Container>
    bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {return lhs._cntr < rhs._cntr;};
    template <class T, class Container>
    bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {return lhs._cntr <= rhs._cntr;};
    template <class T, class Container>
    bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {return lhs._cntr > rhs._cntr;};
    template <class T, class Container>
    bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {return lhs._cntr >= rhs._cntr;};
}