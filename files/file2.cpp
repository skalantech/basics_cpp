#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

int main (){
	
	auto start = std::chrono::steady_clock::now();
	
    std::ifstream myfile;
    myfile.open("HTML.txt");
    std::string myline;
    if ( myfile.is_open() ) {
        while ( myfile ) { // equivalent to myfile.good()
        std::getline (myfile, myline);
        std::cout << myline << '\n';
        }
    }
    else {
        std::cout << "Couldn't open file\n";
    }
	
	auto stop = std::chrono::steady_clock::now();
	auto duration = (stop - start);
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
	std::cout << ms << " ms " << '\n';
    return 0;      
}