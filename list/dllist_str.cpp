#include <iostream>
#include <string>

typedef std::string Elem;

class Node {
private:
	Elem elem;
	Node* prev;
	Node* next;
	friend class DLinkedList;
};

class DLinkedList {
public:
	DLinkedList();
	~DLinkedList();
	bool empty() const;
	const Elem& front() const;
	const Elem& back() const;
	void addFront(const Elem& e);
	void addBack(const Elem& e);
	void removeFront();
	void removeBack();
	void display() const;
	friend std::ostream& operator<<(std::ostream& os, const DLinkedList& ll);
	long size();
	friend void listReverse(DLinkedList& L);
private:
	Node* header;
	Node* trailer;
	long count;
protected:
	void add(Node* v, const Elem& e);
	void remove(Node* v);
};

DLinkedList::DLinkedList() {
	header = new Node;
	trailer = new Node;
	header->next = trailer;
	trailer->prev = header;
	std::cout << "\"DLinked List created\"" << std::endl;
}

DLinkedList::~DLinkedList() {
	while(!empty()) removeFront();
	delete header;
	delete trailer;
	std::cout << "\"DLinked List destroyed\"" << std::endl;
}

bool DLinkedList::empty() const {
	return (header->next == trailer);
}

const Elem& DLinkedList::front() const {
	return header->next->elem;
}

const Elem& DLinkedList::back() const {
	return trailer->prev->elem;
}

void DLinkedList::add(Node* v, const Elem& e) {
	Node* u = new Node;
	u->elem = e;
	u->next = v;
	u->prev = v->prev;
	v->prev->next = u;
	v->prev = u;
}

void DLinkedList::addFront(const Elem& e) {
	add(header->next, e);
}

void DLinkedList::addBack(const Elem& e) {
	add(trailer, e);
}

void DLinkedList::remove(Node* v) {
	Node* u = v->prev;
	Node* w = v->next;
	u->next = w;
	w->prev = u;
	delete v;
}

void DLinkedList::removeFront() {
	remove(header->next);
}

void DLinkedList::removeBack() {
	remove(trailer->prev);
}

long DLinkedList::size() {
	Node* cur = header->next;
	count = 0;
	while(cur != trailer) {
		count++;
		cur = cur->next;
	}
	return count;
}

void DLinkedList::display() const {
	Node* nodeH = header->next;
	Node* nodeB = trailer->prev;
	Node* node = nodeH->next;
	std::cout << "[header<->" << nodeH->elem << "<->";
	while(node != nodeB) {
		std::cout << node->elem << "<->";
		node = node->next;
	}
	std::cout << nodeB->elem << "<->trailer]\n";
}

std::ostream& operator<<(std::ostream& os, const DLinkedList& ll) {
	ll.display();
	return os;
}

void listReverse(DLinkedList& L) {
	DLinkedList T;
	Elem s;
	while(!L.empty()) {
		s = L.front();
		L.removeFront();
		T.addFront(s);
	}
	while(!T.empty()) {
		s = T.front();
		T.removeFront();
		L.addBack(s);
	}
}

int main() {
	DLinkedList dlist;
	std::cout  << dlist.empty() << '\n';
	dlist.addFront("First");
	dlist.addFront("Second");
	dlist.addFront("Third");
	dlist.addFront("Fourth");
	dlist.addFront("Fifth");
	std::cout << dlist.front() << '\n';
	std::cout << dlist.back() << '\n';
	std::cout << "empty ?: " << (dlist.empty() ? "true\n" : "false\n");
	std::cout << dlist;
	std::cout << "size: " << dlist.size() << '\n';
	listReverse(dlist);
	std::cout << dlist;

	return 0;
}
