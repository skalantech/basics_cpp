#include <iostream>
#include <fstream>
#include <optional>
#include <vector>

std::string ReadFileAsString(const std::string& filepath, bool& outSuccess)
{
    std::ifstream stream(filepath);
    if (stream)
    {
        std::string result;
        char ch;
        while (stream.get(ch))
        {
            std::cout << ch;
        }
        std::cout << '\n';
        stream.close();
        outSuccess = true;
        return result;
    }
    outSuccess = false;
    return std::string();
}

std::optional<std::string> ReadFileAsStringOpt(const std::string& filepath)
{
    std::ifstream stream(filepath);
    if (stream)
    {
        std::string line;
        while (getline(stream, line))
        {
            std::cout << line << '\n';
        }
        stream.close();
        return line;
    }
    return {};      // empty std::optional
}

int main()
{
    bool FileOpenedSuccesfully;
    std::string data = ReadFileAsString("data.txt", FileOpenedSuccesfully);
    if (FileOpenedSuccesfully)
    {
        std::cout << "data: " << data << '\n';
        std::cout << "File read successfully!\n\n";
    }
    else
    {
        std::cout << "File could not be opened!\n\n";
    }

    std::optional<std::string> dataOpt = ReadFileAsStringOpt("data.txt");
    std::string value = dataOpt.value_or("Not present");
    std::cout << "value: " << value << '\n';    // stores the last line of the file

    // EX
    std::optional<int> count;
    int c = count.value_or(100);
    std::cout << c << '\n';

    if (dataOpt.has_value())
    {
        std::cout << "dataOpt.value: " << dataOpt.value() << '\n'; // stores the last line of the file
        std::cout << "File read successfully using OPT!\n";
    }
    else
    {
        std::cout << "File could not be opened using OPT!\n";
    }

    std::cin.get();
}

