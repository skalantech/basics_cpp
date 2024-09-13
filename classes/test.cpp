#include <iostream>
#include <string>

using namespace std;

int main() {
	cout << "Hello Notepad++ and C++" << endl;
	
	cout << "Please give your name" << endl;
	
	//read user input
	string str_name;
	getline(cin, str_name);
	
	cout << "Name: " << str_name << '\n';
	
	return 0;
}