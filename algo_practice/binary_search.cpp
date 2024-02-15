/**
* Performs the standard binary search using two comparisons per level.
* Returns index where item is found or -1 if not found.
*/

#include <vector>
#include <iostream>
#include <numeric>

#define NOT_FOUND -1;

template <typename Comparable>
int binarySearch (const std::vector<Comparable> & a, const Comparable & x)
{
    int low = 0, high= a.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if(a[mid] < x)
            low = mid + 1;
        else if( a[mid] > x)
            high = mid - 1;
        else
            return mid;     //Found
    }
    return NOT_FOUND;       // NOT_FOUND is defined as -1
}

bool binary_search(const std::vector<int>& a, int key)
{
    auto low = 0;
    auto high = static_cast<int>(a.size() - 1);
    while (low <= high)
    {
        const auto mid = std::midpoint(low, high);
        if (a[mid] < key)
            low = mid + 1;
        else if (a[mid] > key)
            high = mid - 1;
        else
            return true;        
    }
    return false;
}

int main() 
{
    std::vector<int> v {0,1,2,3,5,6,7,9,12,15,17,22,25};
    int result = binarySearch(v, 4);
    bool result2 = binary_search(v, 4);
    if (result == -1)
        std::cout << "NOT_FOUND" << '\n';
    else
        std::cout << "YES" << '\n';
    std::cout << result << '\n';    
    std::cout << result2 << '\n';
}