#include <string>
#include <vector>
#include <fstream>
#include <iostream>

std::vector<std::string> fhand(const char * filename) { // store lines in a vector
std::vector<std::string> lines; // vector of lines
std::ifstream file;
file.open(filename);
while (file) { // read until end of file
    std::string line;
    std::getline(file, line); // input a full line of text
    lines.push_back(line); // append tag to the vector
    }
    return lines; // return vector of tags
}

int main(){

    
    std::vector<std::string> file = fhand("HTML.txt");
    for(int i = 0; i < file.size(); i++)
        std::cout << file[i] << '\n';

    return 0;
}