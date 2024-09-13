#include <iostream>
#include <variant>
#include <optional>

enum class ErrorCode
{
    None = 0, NotFound = 1, NoAccess = 2,
};

std::variant<std::string, ErrorCode> ReadFileAsString()
{
    return {};
}

int main()
{
    std::variant<std::string, int> data;

    std::cout << sizeof(int) << '\n';
    std::cout << sizeof(std::string) << '\n';
    std::cout << sizeof(data) << '\n';

    data = "Carlos";
    std::cout << data.index() << '\n';
    std::cout << std::get<std::string>(data) << '\n';
    if (auto value = std::get_if<std::string>(&data))
    {
        std::string& v = *value;
        std::cout << v << '\n';
    }
    else
    {

    }

    data = 40;
    std::cout << data.index() << '\n';
    std::cout << std::get<int>(data) << '\n';

    return 0;
}