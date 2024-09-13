#include <vector>
#include <iostream>
#include <array>
#include <algorithm>
#include "scopedTimer.h"
#include "print.h"

struct Point
{
    int x_{};
    int y_{};
};

bool linear_search(const std::vector<Point>& a, const Point & key)
{
    for (size_t i = 0; i < a.size(); ++i)
    {
        if (a[i].x_ == key.x_ && a[i].y_ == key.y_)
            return true;
    }
    return false;
}

bool linear_search(const std::vector<int>& a, const int & key)
{
    for (size_t i = 0; i < a.size(); ++i)
    {
        if (a[i] == key)
            return true;
    }
    return false;
}

bool linear_search(const std::array<int, 11>& a, const int & key)
{
    for (size_t i = 0; i < 11; ++i)
    {
        if (a[i] == key)
            return true;
    }
    return false;
}


int main() 
{
    Point uno = {1, 1};
    Point dos = {1, 2};
    Point tres = {2, 1};
    Point cuatro = {2,2};
    std::vector<Point> points {uno, dos, tres, cuatro};
    std::vector<int> v {50,12,16,84,2,46,74,51,21,96,34};
    std::array<int, 11> a {50,12,16,84,2,46,74,51,21,96,34};
    std::sort(v.begin(), v.end());
    std::sort(a.begin(), a.end());
    for (const auto& x: v)
        std::cout << x << ',' << ' ';
    std::cout << '\n';
    for (const auto& y: a)
        std::cout << y << ',' << ' ';
    std::cout << '\n';

    std::cout << static_cast<bool>(linear_search(v, 21));
    std::cout << '\n';
    std::cout << static_cast<bool>(linear_search(a, 16));
    std::cout << '\n';
    std::cout << (linear_search(points, {1, 2}));
    std::cout << '\n';
    ScopedTimer(linear_search(v, 96));
    ScopedTimer(linear_search(a, 16));
    ScopedTimer(linear_search(points, {1, 2}));
    print(v);
}