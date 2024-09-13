#include <iostream>
#include <string>
#include <memory>
using namespace std;

int main() {
	
	unique_ptr<double> pvalue (new double);
	unique_ptr<std::string> name = make_unique<std::string>();

	*pvalue = 2894.8;     // Store value at allocated address
	*name = "Carlos";
	
	unique_ptr<double> p2val;
	if (!(p2val = make_unique<double>())) {
		cout << "No memory for pointer\n";
	}

	cout << "Value of pvalue : " << *pvalue << endl;
	cout << "name : " << *name << endl;

	p2val = std::move(pvalue);
	
	cout << "Value of pvalue : " << *pvalue << endl;
	cout << "Value of p2val : " << *p2val << endl;
	cout << "name : " << *name << endl;

	return 0;
}