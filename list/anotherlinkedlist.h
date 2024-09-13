#include <iostream>

template <class T>
class LinkedList {
    struct Node {
        T data;
        Node* next;
        Node(T val): data(val), next(nullptr) {}
    };

public:
    LinkedList() : head(nullptr) {}
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;
    ~LinkedList();
    void insert(T);
    void deleteNode(T);
    void display(std::ostream& out) const {
        Node *node = head;
        while(node != nullptr) {
            out << node->data << " ";
            node = node->next;
        }
    }
    template <class U>
    friend std::ostream& operator<<(std::ostream& os, const LinkedList<U>& ll);
private:
    Node* head;  
    Node* search(T val) {
        Node* node = head;
        while(node != nullptr) {
            if(node->data == val) return node;
            node = node->next;
        }
        std::cerr << "No such element in the list\n";
        return nullptr;
    }
};

template <class T>
LinkedList<T>::~LinkedList() {
    Node* tmp = nullptr;
    while(head) {
        tmp = head;
        head = head->next;
        delete tmp;
    }
    head = nullptr;
}

template <class T>
void LinkedList<T>::insert(T data) {
    Node* t = new Node(data);
    Node* tmp = head;
    if(tmp == nullptr) head = t;
    else {
        while(tmp->next != nullptr) tmp = tmp->next;
        tmp->next = t;
    }
}

template <class T>
void LinkedList<T>::deleteNode(T data) {
    Node* node = search(data);
    Node* tmp = head;
    if(tmp == node) {
        head = tmp->next;
        delete node;
    } else {
        while(node != nullptr) {
            if(tmp->next == node) {
                tmp->next = node->next;
                tmp = tmp->next;
                delete node;
                return;
            }            
            tmp = tmp->next;
        }
        return;
    }
}

template <class T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& ll) {
    ll.display(os);
    return os;
}