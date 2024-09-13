#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char** argv) {
	struct {
		void operator()(int x) {
			std::cout << x << std::endl;
		}
	} something;

	something(35);

	//[](int x){std::cout << x << std::endl;}

	/*[](int x){
		if(x%2 == 0){
			std::cout << x << " is even number" << std::endl;
		}
		else{
			std::cout << x << " is odd number" << std::endl;
		}
	}*/

	int d = 2, y = 3;

	std::vector<int> v{ 2, 3, 7, 14, 23 };

	std::for_each(v.begin(), v.end(), [](int x) {std::cout << x << std::endl; });

	std::for_each(v.begin(), v.end(), [d, &y](int x) { //[&] passing all by reference, [=] passing all by value
		if (x % d == 0) {
			std::cout << x << " is even number" << std::endl;
		}
		else {
			std::cout << x << " is odd number" << std::endl;
			y = 2;
			std::cout << "y = " << y << std::endl;
		}
		});

	std::cout << "Out of the for_each" << std::endl;
	std::cout << "y = " << y << std::endl;

	return 0;
}