#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "linkedlist.h"
#include "exception.h"

typedef std::string Elem;

class LinkedStack {
public:
    LinkedStack();
    int size() const;
    bool empty() const;
    const Elem& top() const;
    void push(const Elem& e);
    void pop();
private:
    SLinkedList<Elem> S;
    int n;
};

LinkedStack::LinkedStack(): S(), n(0) {}

int LinkedStack::size() const {return n;}

bool LinkedStack::empty() const {return n == 0;}

const Elem& LinkedStack::top() const {
    if(empty()) {
        std::cout << "Top of empty stack" << '\n';
        exit(1);
    }
    return S.front();
}

void LinkedStack::push(const Elem& e) {
    ++n;
    S.addFront(e);
}

void LinkedStack::pop() {
    if (empty()) {
        std::cout << "Pop from empty stack" << '\n';
        exit(1);
    }
    --n;
    S.removeFront();
}

std::vector<std::string> getHtmlTags(const char* filename) {
    std::vector<std::string> tags;
    std::ifstream file;
    file.open(filename);
    while(file) {
        std::string line;
        std::getline(file, line);
        int pos = 0;
        int ts = line.find("<", pos);
        while(ts != (int)std::string::npos) {
            int te = line.find(">", ts+1);
            tags.push_back(line.substr(ts, te-ts+1));
            pos = te + 1;
            ts = line.find("<", pos);
        }
    }
    return tags;
}

bool isHtmlMatched(const std::vector<std::string>& tags) {
    LinkedStack S;
    typedef std::vector<std::string>::const_iterator Iter;
    for(Iter p = tags.begin(); p != tags.end(); ++p) {
        if(p->at(1) != '/')
            S.push(*p);
        else {
            if(S.empty()) return false;
            std::string open = S.top().substr(1);
            //std::cout << open << '\n';
            std::string close = p->substr(2);
            //std::cout << close << '\n';
            if(open.compare(close) != 0) return false;
            else S.pop();
        }
    }
    if(S.empty()) return true;
    else return false;
}

int main() {
    std::string line;
    std::ifstream file;
    file.open("HTML.txt");

    if(file.is_open()) {
        std::cout << "Reading from a file:\n";
        while(file) {
            std::getline(file, line);
            std::cout << line << '\n';
        }
    } else {
        std::cout << "Couldn't open the file\n";
    }
    file.close();

    auto tags = getHtmlTags("HTML.txt");
    for(auto it = tags.begin(); it != tags.end(); it++) {
        std::cout << *it << '\n';
    }

    std::cout << isHtmlMatched(tags) << '\n';

    if(isHtmlMatched(getHtmlTags("HTML.txt")))
        std::cout << "HTML is GOOD\n";
    else
        std::cout << "Ill formed HTML\n";
         
    return 0;
}