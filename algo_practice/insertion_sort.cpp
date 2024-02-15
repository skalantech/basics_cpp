#include <vector>
#include <iostream>
#include "scopedTimer.h"

void insertionSort(char * A, int n)
{
    for (int i = 1; i < n; i++)
    {
        char cur = A[i];
        int j = i - 1;
        while ((j >= 0) && (A[j] > cur))
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = cur;
    }
}

void insertionSort(std::vector<int>& a)
{
    for (size_t i = 1; i < a.size(); ++i)
    {
        auto j = i;
        while (j > 0 && a[j - 1] > a[j])
        {
            std::swap(a[j], a[j-1]);
            --j;
        }
    }
}

int main()
{
    char A[10] {'b', 'c', 'a', 'z', 'm', 'o', 'r', 't', 'n', 'j'};
    std::vector<int> V {9, 1, 0, 5, 4, 7, 6, 8, 2, 3 };
    insertionSort(A, 10);
    insertionSort(V);
    
    for (size_t i = 0; i < 10; ++i)
    {
        std::cout << A[i] << ' ';
    }
    std::cout << '\n';
    
    for (std::vector<int>::const_iterator it = V.begin(); it != V.end(); ++it)
        std::cout << *it << ' ';
    std::cout << '\n';
    
    for (auto& v: V)
    {
        std::cout << v << ' ';
    }
    std::cout << '\n';
}
