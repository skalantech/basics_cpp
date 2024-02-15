#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <chrono>

std::vector<std::string> fhand(const char * filename) { // store lines in a vector
	std::vector<std::string> lines; // vector of lines
	std::ifstream file;
	file.open(filename);
	while (file) { // read until end of file
		std::string line;
		std::getline(file, line); // input a full line of text
		lines.push_back(line); // append tag to the vector
		}
	file.close();
    return lines; // return vector of tags
}

int main(){
	
	auto start = std::chrono::steady_clock::now();
	
    std::vector<std::string> file = fhand("HTML.txt");
	auto N = file.size();
	auto i = N - N;
    for(; i < N; i++)
	{
        std::cout << file[i] << '\n';
	}
	
	auto stop = std::chrono::steady_clock::now();
	auto duration = (stop - start);
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
	std::cout << ms << " ms " << '\n';

    return 0;
}