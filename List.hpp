#include "containers.h"

template <typename T>
class List {
private:
    typedef struct Node {
        T data;
        struct Node *next;
    } Node;
    Node *st;
    size_t sizeSt;

public:
    List();
    ~List();
    List<T> &operator=(const List &st); //TODO return value is const or not????
    bool empty();
    T &top();
    void push(const T &val);
    void emplace(const T &val);
    void pop();
    size_t size();
};
