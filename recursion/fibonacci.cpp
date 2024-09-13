#include <utility>
#include <tuple>
#include <vector>
#include <memory>
#include <iostream>

std::unique_ptr<int[]> fibArray(int k) {
    std::unique_ptr<int[]> pair = std::make_unique<int[]>(2);
    if (k <= 1) {
        pair[0] = k;
        pair[1] = 0;
        return pair;
    }
    else {
        pair = fibArray(k - 1);
        int temp = pair[1];
        pair[1] = pair[0] + pair[1];
        pair[0] = temp;
        return pair;
    }
}

struct pair {
    int first{0};
    int second{0};
};

pair fibStruct(int k) {
    pair fibo;
    if (k <= 1) 
        return {fibo.first = k, fibo.second = 0};
    else {
        fibo = fibStruct(k - 1);
        return {fibo.second, fibo.first + fibo.second};
    }
}

std::vector<int> fibVector(int k) {
    std::vector<int> pair{0, 0};
    if (k <= 1) {
        pair[0] = k;
        pair[1] = 0;
        return pair;
    }
    else {
        pair = fibVector(k - 1);
        int temp = pair[1];
        pair[1] = pair[0] + pair[1];
        pair[0] = temp;
        return pair;
    }
}

auto fibTuple(unsigned int k) {
    std::tuple<unsigned int, unsigned int> fibo_tuple;
    if (k <= 1)
        return fibo_tuple = std::make_tuple(k, 0);
    else {
        fibo_tuple = fibTuple(k - 1);
        return std::make_tuple(std::get<1>(fibo_tuple), std::get<0>(fibo_tuple) + std::get<1>(fibo_tuple));            
    }
}

auto fibPair(unsigned int k) {
    std::pair<unsigned int, unsigned int> fibo_pair;
    if (k <= 1) {
        return fibo_pair = std::make_pair(k, 0);
    }
    else {
        fibo_pair = fibPair(k - 1);
        return std::make_pair(fibo_pair.second, fibo_pair.first + fibo_pair.second);
    }
}
int main() {
    auto fiboArray = fibArray(5);
    std::cout << fiboArray[0] << ", " << fiboArray[1] << '\n';

    auto fiboStruct = fibStruct(5);
    std::cout << fiboStruct.first << ", " << fiboStruct.second << '\n';

    auto fiboVector = fibVector(5);
    std::cout << fiboVector[0] << ", " << fiboVector[1] << '\n';

    auto fiboTuple = fibTuple(5);
    std::cout << std::get<0>(fiboTuple) << ", " << std::get<1>(fiboTuple) << '\n';

    auto fiboPair = fibPair(5);
    std::cout << fiboPair.first << ", " << fiboPair.second << '\n';

    return 0;
}
