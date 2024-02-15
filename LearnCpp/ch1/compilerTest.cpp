#include <array>
#include <iostream>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <limits>

namespace a::b::c
{
	inline constexpr std::string_view str{ "hello" };
}

template <class... T>
std::tuple<std::size_t, std::common_type_t<T...>> sum(T... args)
{
	return { sizeof...(T), (args + ...) };
}

int main()
{
	auto [iNumbers, iSum] { sum(1, 2, 3)};
	std::cout << a::b::c::str << ' ' << iNumbers << ' ' << iSum << '\n';

	std::array arr{ 1, 2, 3 };

	std::cout << std::size(arr) << '\n';

	std::cin.clear(); // reset any error flags
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user
	return 0;
}
