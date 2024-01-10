#ifndef _ARRAYSTACK_H
#define _ARRAYSTACK_H

template <typename E>
class ArrayStack {
    enum {DEF_CAPACITY = 100};
public:
    ArrayStack(int cap = DEF_CAPACITY);
    int size() const;
    bool empty() const;
    const E& top() const;
    void push(const E& e);
    void pop();
    ~ArrayStack();
    ArrayStack(const ArrayStack&);
    ArrayStack(ArrayStack&&) noexcept;
    ArrayStack& operator=(const ArrayStack&);
    ArrayStack& operator=(ArrayStack&&) noexcept;
private:
    E* S;
    int capacity;
    int indexTop;
};

#endif

template <typename E>
ArrayStack<E>::ArrayStack(int cap) : S{new E[cap]}, capacity{cap}, indexTop{-1} {}

template <typename E>
ArrayStack<E>::~ArrayStack() {
    delete[] S;
}

template <typename E>
int ArrayStack<E>::size() const {return (indexTop + 1);}

template <typename E>
bool ArrayStack<E>::empty() const {return (indexTop < 0);}

template <typename E>
const E& ArrayStack<E>::top() const {
    if(empty()) {
        std::cout << "Top of empty stack" << '\n';
        exit(1);
    }
     return S[indexTop];
}

template <typename E>
void ArrayStack<E>::push(const E& e) {
    if(size() == capacity) {
        std::cout << "Push to full stack" << '\n';
        exit(1);
    }
    S[++indexTop] = e;
}

template <typename E>
void ArrayStack<E>::pop() {
    if(empty()) {
        std::cout << "Pop from empty stack" << '\n';
        exit(1);
    }
    --indexTop;
}

template <typename E>
void reverse(std::vector<E>& V) {
    ArrayStack<E> S(V.size());
    for(int i = 0; i < V.size(); i++)
        S.push(V[i]);
    for(int i = 0; i < V.size(); i++) {
        V[i] = S.top();
        S.pop();
    }
};