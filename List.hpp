#include "containers.h"

struct Node;

template <typename T, typename Alloc = std::allocator<T> >
class List {
    typedef struct Node {
        T data;
        struct Node *next;
        struct Node *prev;
    } Node;

public:
    typedef Alloc allocator_type;
    typedef T value_type;
    typedef size_t size_type;
    typedef typename allocator_type::template rebind<Node>::other nodeAllocator;

    List(const allocator_type &alloc = allocator_type()) {
        (void) alloc;
        list = newNode();
        sz = 0;
    };
    
    ~List() {};

    bool empty() const {return sz == 0;}

    void push_back(const value_type &val) {
        Node *node = newNode();
        node->data = val;
        if (empty()) {
            list = node;
        } else {
            Node *tmp = list;
            while (tmp->next)
                tmp = tmp->next;
            tmp->next = node;
            node->prev = tmp;
        }
        sz += 1;
    };

    void push_front(const value_type &val) {
        Node *node = newNode();
        node->data = val;
        if (empty()) {
            list = node;
        } else {
            Node *tmp = list;
            list = node;
            node->next = tmp;
        }
        sz += 1;
    }

    template<typename _Tp>
    struct iterator {
        
    };

private:
    Node *list;
    size_type sz;
    nodeAllocator allocator;

    Node *newNode() {
        Node *node = allocator.allocate(sizeof(Node));
        node->next = NULL;
        node->prev = NULL;
        return node;
    };
};
