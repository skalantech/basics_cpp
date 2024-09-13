#include <iostream>
using namespace std;

class Book{
   // private:

    public:
       string title;
       string author;
int pages;
       Book(string aTitle, string aAuthor, int aPages){
            title = aTitle;
            author = aAuthor;                               // Constructor
            //setlength(aPages);
            pages = aPages;
       }

       bool islong(){
            if(pages >= 600){                               // Object function
                return true;
            }
            return false;
       }
/*        void setlength(int aPages){
            if(aPages <= 500){
               pages = aPages;
            } else {
                pages = 1000;
            }

        int getlenght(){
            return pages;

        }*/
};


int main()
{

/*
    Book book1;
    book1.title = "Harry Potter";
    book1.author = "JK Rowling";
    book1.pages = 500;
                                                    // without constructors

    Book book2;
    book2.title = "Lord of the Rings";
    book2.author = "Tolkein";
    book2.pages = 700;
*/

    Book book1("Harry Potter","JK Rowling",500);
    Book book2("Lord of the Rings","Tolkein",700);

    cout << book2.islong();
   // cout << book2.setlength();

    return 0;
}
