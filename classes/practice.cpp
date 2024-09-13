#include <iostream>
#include <string>

class Book {
public:
	Book(int num_pages, std::string aut, int id, char* y);
	~Book();
	Book(const Book& book);
	const int get_id();
	const int get_num_pages();
	const std::string get_author();
	const char* get_year();

private:
	int* ptr_num_pages;
	std::string* author;
	int id;
	char* year;
};

Book::Book(int num_pages, std::string aut, int id, char* y) : year(y) {
	std::cout << "Book Created\n";
	this->id = id;
	ptr_num_pages = new int;
	author = new std::string;
	*ptr_num_pages = num_pages;
	*author = aut;
}

Book::Book(const Book& book) {
	std::cout << "Book copied\n";
	ptr_num_pages = new int;
	author = new std::string;
	*ptr_num_pages = *book.ptr_num_pages;
	*author = *book.author;
	id = book.id;
	year = book.year;

}

Book::~Book() {
	std::cout << "Deleting book\n";
	delete ptr_num_pages;
	delete author;
}

const int Book::get_num_pages() {
	return *ptr_num_pages;
}

const std::string Book::get_author() {
	return *author;
}

const int Book::get_id() {
	return id;
}

const char* Book::get_year() {
	return year;
}

void display(Book book) {
	std::cout << "This book has " << book.get_num_pages() << " pages\n";
	std::cout << "This book has been written by " << book.get_author() << '\n';
	std::cout << "ID: " << book.get_id() << '\n';
	std::cout << "Published in " << book.get_year() << '\n';
}

int main() {
	Book book1(125, "Carlos Escalante", 37, "1998");
	Book book2 = book1;

	display(book1);
	display(book2);

	return 0;
}