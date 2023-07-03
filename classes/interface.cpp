#include <iostream>
 
using namespace std;
 
// Base class
class Shape {
   public:
      // pure virtual function providing interface framework.
      virtual int getArea() = 0;
      void setWidth(int w) {
         width = w;
      }
   
      void setHeight(int h) {
         height = h;
      }
   
   protected:
      int width;
      int height;
};
 
// Derived classes
class Rectangle: public Shape {
   public:
      int getArea() { 
         return (width * height); 
      }
};

class Triangle: public Shape {
   public:
      int getArea() { 
         return (width * height)/2; 
      }
};
 
int main(void) {
   Rectangle Rect;
   Triangle  Tri;
 
   Rect.setWidth(5);
   Rect.setHeight(7);
   
   // Print the area of the object.
   cout << "Total Rectangle area: " << Rect.getArea() << endl;

   Tri.setWidth(5);
   Tri.setHeight(7);
   
   // Print the area of the object.
   cout << "Total Triangle area: " << Tri.getArea() << endl; 

   return 0;
}

/*Abstract class:(often referred to as an ABC) is to provide 
an appropriate base class from which other classes can inherit. 
Abstract classes cannot be used to instantiate objects and serves 
only as an interface. Attempting to instantiate an object of an 
abstract class causes a compilation error.

Thus, if a subclass of an ABC needs to be instantiated, it has to 
implement each of the virtual functions, which means that it supports 
the interface declared by the ABC. Failure to override a pure virtual 
function in a derived class, then attempting to instantiate objects 
of that class, is a compilation error.

Classes that can be used to instantiate objects are called concrete classes.*/