/*char* pvalue  = NULL;         // Pointer initialized with null
pvalue  = new char[20];       // Request memory for the variable

delete [] pvalue;             // Delete array pointed to by pvalue

*******Multidimensional arrays*********

double** pvalue  = NULL;      // Pointer initialized with null 
pvalue  = new double [3][4];  // Allocate memory for a 3x4 array 

delete [] pvalue;            // Delete array pointed to by pvalue
*/

#include <iostream>
using namespace std;

class Box {
   public:
      Box() { 
         cout << "Constructor called!" <<endl; 
      }
      ~Box() { 
         cout << "Destructor called!" <<endl; 
      }
};
int main() {
   Box* myBoxArray = new Box[4];
   delete [] myBoxArray; // Delete array

   return 0;
}