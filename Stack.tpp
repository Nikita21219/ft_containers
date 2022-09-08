#include "containers.h"

template <typename T>
Stack<T>::Stack() {
    st = NULL;
    sizeSt = 0;    
}

template <typename T>
Stack<T>::~Stack() {}

template <typename T>
Stack<T> &Stack<T>::operator=(const Stack &st) {
    this->st = st;
    this->sizeSt = st.size();
    return *this;
}

template <typename T>
bool Stack<T>::empty() {return st == NULL;}

template <typename T>
T &Stack<T>::top() {
    return st->data;
}

template <typename T>
void Stack<T>::push(const T &val) {
    Node *tmp = st;
    st = new Node;
    if (empty()) {
        st->data = val;
        st->next = NULL;
    } else {
        st->data = val;
        st->next = tmp;
    }
    sizeSt += 1;
}

template <typename T>
void Stack<T>::emplace(const T &val) {
    Node *tmp = st;
    st = new Node;
    if (empty()) {
        st->data = val;
        st->next = NULL;
    } else {
        st->data = val;
        st->next = tmp;
    }
    sizeSt += 1;
}

template <typename T>
void Stack<T>::pop() {
    Node *tmp = st;
    st = st->next;
    sizeSt -= 1;
    delete tmp;
}

template <typename T>
size_t Stack<T>::size() {return sizeSt;}
