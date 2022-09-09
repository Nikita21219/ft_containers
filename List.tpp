#include "containers.h"

// template <typename T, typename Alloc = std::allocator<T> >
// List<T>::List(const Alloc &alloc) {
//     (void) alloc;
//     st = NULL;
//     sizeContainer = 0;
// };

// template <typename T>
// List<T>::~List() {}

// template <typename T>
// List<T> &List<T>::operator=(const List &st) {
//     this->st = st;
//     this->sizeSt = st.size();
//     return *this;
// }

// template <typename T>
// bool List<T>::empty() {return st == NULL;}

// template <typename T>
// T &List<T>::top() {
//     return st->data;
// }

// template <typename T>
// void List<T>::push(const T &val) {
//     Node *tmp = st;
//     st = new Node;
//     if (empty()) {
//         st->data = val;
//         st->next = NULL;
//     } else {
//         st->data = val;
//         st->next = tmp;
//     }
//     sizeSt += 1;
// }

// template <typename T>
// void List<T>::emplace(const T &val) {
//     Node *tmp = st;
//     st = new Node;
//     if (empty()) {
//         st->data = val;
//         st->next = NULL;
//     } else {
//         st->data = val;
//         st->next = tmp;
//     }
//     sizeSt += 1;
// }

// template <typename T>
// void List<T>::pop() {
//     Node *tmp = st;
//     st = st->next;
//     sizeSt -= 1;
//     delete tmp;
// }

// template <typename T>
// size_t List<T>::size() {return sizeSt;}
