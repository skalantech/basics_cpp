#include <iostream>
using namespace std;

// first name space
namespace first_space {
   void func() {
      cout << "Inside first_space" << endl;
   }
   
   // second name space
   namespace second_space {
      void func() {
         cout << "Inside second_space" << endl;
      }
   }
}

using namespace first_space::second_space;
int main () {
   // This calls function from second name space.
   func();
   first_space::second_space::func();
   first_space::func();
   
   return 0;
}

/*
namespace namespace_name {
   // code declarations
}

namespace namespace_name1 {
   // code declarations
   namespace namespace_name2 {
      // code declarations
   }
}

// to access members of namespace_name2
using namespace namespace_name1::namespace_name2;

// to access members of namespace:name1
using namespace namespace_name1;
*/