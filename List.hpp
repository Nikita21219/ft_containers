#include "containers.h"

template <typename T, typename Alloc = std::allocator<T> >
class List {
public:
    typedef Alloc allocator_type;
    typedef T value_type;
    typedef size_t size_type;

public:
    List(const allocator_type &alloc = allocator_type()) {
        (void) alloc;
        list = NULL;
        sizeContainer = 0;
    };
    ~List() {};
    bool empty() const {return sizeContainer == 0;}
    // void push_back (const value_type &val) {
    //     Node *node = alloc.allocate(sizeof(Node));
    //     node->data = val;
    //     node->next = NULL;
    //     if (empty()) {
    //         sizeContainer += 1;
    //         list = node;
    //     } else {
    //         Node *tmp = list;
    //         while (tmp->next)
    //             tmp = tmp->next;
    //         tmp->next = node;
    //     }
    // };


    // ~List();
    // List<T> &operator=(const List &st); //TODO return value is const or not????
    // bool empty();
    // T &top();
    // void push(const T &val);
    // void emplace(const T &val);
    // void pop();
    // size_t size();

private:
    typedef struct Node {
        T data;
        struct Node *next;
    } Node;
    Node *list;
    size_type sizeContainer;
    Alloc alloc;

};
