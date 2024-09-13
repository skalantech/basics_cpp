#include <iostream>
#include <string>

class Node {
private:
	std::string elem;

	Node* next;

	friend class StringLinkedList;
};

class StringLinkedList {
public:
	StringLinkedList();

	~StringLinkedList();

	bool empty() const;

	const std::string& front() const;

	void addFront(const std::string& e);

	void insert(const std::string& e, int i);

	void removeFront();

	void display() const;

	friend std::ostream& operator<<(std::ostream& os, const StringLinkedList& ll);

	long size();
private:
	Node* head;

	long count;
};

StringLinkedList::StringLinkedList() : head(NULL) {
	std::cout << "\"List created\"" << std::endl;
}

StringLinkedList::~StringLinkedList() {
	while(!empty()) removeFront();
	std::cout << "\"List destroyed\"" << std::endl;
}

bool StringLinkedList::empty() const {
	return head == NULL;
}

const std::string& StringLinkedList::front() const {
	return head->elem;
}

void StringLinkedList::addFront(const std::string& e) {
	Node* v = new Node;

	v->elem = e;

	v->next = head;

	head = v;
}

void StringLinkedList::removeFront() {
	Node* old = head;

	head = old->next;

	delete old;
}

long StringLinkedList::size() {
	Node* cur = head;
	count = 0;

	while(cur != NULL) {
		count++;
		cur = cur->next;
	}
	return count;
}

void StringLinkedList::insert(const std::string& e, int i) {
	int pos = i;
	Node* v = new Node;
	Node* cur = head;

	if(i == 0)
		addFront(e);

	if (i > 0) {
		v->elem = e;

		while(pos > 1) {
			cur = cur->next;
			pos--;
		}

		Node* prev = cur;
		Node* prox = cur->next;

		prev->next = v;
		v->next = prox;
	}
	count++;
}

void StringLinkedList::display() const {
	Node* node = head;
	while(node) {
		std::cout << node->elem << "->";
		node = node->next;
	}
	std::cout << "NULL";
}

std::ostream& operator<<(std::ostream& os, const StringLinkedList& ll) {
	ll.display();
	return os;
}

int main() {
	StringLinkedList list;
	std::cout << "size: " << list.size() << '\n';
	std::cout << "is it empty: " << (list.empty() ? "true\n" : "false\n");
	std::cout << "list: " << list << '\n';

	list.addFront("hola");
	std::cout << "addFront(\"hola\")\n";
	std::cout << "list: " << list << '\n';
	std::cout << "size: " << list.size() << '\n';
	std::cout << "is it empty: " << (list.empty() ? "true\n" : "false\n");

	list.addFront("chao");
	list.addFront("chao1");
	list.addFront("chao2");
	list.addFront("chao3");
	std::cout << "head: " << list.front() << '\n';
	std::cout << "size: " << list.size() << '\n';
	std::cout << "list: " << list << '\n';

	list.insert("culo", 2);
	std::cout << "size: " << list.size() << '\n';
	std::cout << "head: " << list.front() << '\n';
	std::cout << "list: " << list << '\n';

	for(int i = 0; i < 20; ++i) {
		std::string index = std::to_string(i);
		list.addFront(index);
	}

	std::cout << "list: " << list << '\n';
	std::cout << "size: " << list.size() << '\n';

	return 0;
}
