/*class Box {
   double width;
   
   public:
      double length;
      friend void printWidth( Box box );
      void setWidth( double wid );
};

To declare all member functions of class ClassTwo as friends of class ClassOne, 
place a following declaration in the definition of class ClassOne −

friend class ClassTwo;
*/

#include <iostream>
 
using namespace std;
 
class Box {
   double width;
   
   public:
      friend void printWidth( Box box );
      void setWidth( double wid );
};

// Member function definition
void Box::setWidth( double wid ) {
   width = wid;
}

// Note: printWidth() is not a member function of any class.
void printWidth( Box box ) {
   /* Because printWidth() is a friend of Box, it can
   directly access any member of this class */
   cout << "Width of box : " << box.width <<endl;
}
 
// Main function for the program
int main() {
   Box box;
 
   // set box width without member function
   box.setWidth(10.0);
   
   // Use friend function to print the wdith.
   printWidth( box );
 
   return 0;
}