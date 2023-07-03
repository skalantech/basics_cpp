/*A derived class can access all the non-private members of its base class. 
Thus base-class members that should not be accessible to the member functions
 of derived classes should be declared private in the base class.
 
 Access	        public	        protected	        private
Same class	      yes	            yes	          yes
Derived classes	yes	            yes	          no
Outside classes	yes	            no	             no
 
 A derived class inherits all base class methods with the following exceptions:

***Constructors, destructors and copy constructors of the base class.
***Overloaded operators of the base class.
***The friend functions of the base class.

Multiple Inheritance

class derived-class: access baseA, access baseB....

The friend declaration appears in a class body and grants a function or another class access to private and protected members of the class where the friend declaration appears.
*/

#include <iostream>
 
using namespace std;

// Base class Shape
class Shape {
   public:
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

// Base class PaintCost
class PaintCost {
   public:
      int getCost(int area) {
         return area * 70;
      }
};

// Derived class
class Rectangle: public Shape, public PaintCost {
   public:
      int getArea() {
         return (width * height); 
      }
};

int main(void) {
   Rectangle Rect;
   int area;
 
   Rect.setWidth(5);
   Rect.setHeight(7);

   area = Rect.getArea();
   
   // Print the area of the object.
   cout << "Total area: " << Rect.getArea() << endl;

   // Print the total cost of painting
   cout << "Total paint cost: $" << Rect.getCost(area) << endl;

}