#include <utility>
#include <tuple>
#include <vector>
#include <memory>
#include <iostream>

auto linearFibonacciPair(unsigned int k) {
    std::pair<unsigned int, int> fibo_pair;
    if(k <= 1)
        return fibo_pair = std::make_pair(k, 0);
    else {
        fibo_pair = linearFibonacciPair(k - 1);
        return fibo_pair = std::make_pair(fibo_pair.first + fibo_pair.second, fibo_pair.first);
    }
}

auto linearFibonacciTuple(unsigned int k) {
    std::tuple<unsigned int, int> fibo_tuple;
    if(k <= 1)
        return fibo_tuple = std::make_tuple(k, 0);
    else {
        fibo_tuple = linearFibonacciTuple(k - 1);
        return fibo_tuple = std::make_tuple(std::get<0>(fibo_tuple) + std::get<1>(fibo_tuple), std::get<0>(fibo_tuple));
    }
}

struct pair {
    int first{0};
    int second{0};
};

pair linearFibonacci(int k) {
    pair fibo;
    if(k <= 1) return {fibo.first = k, fibo.second = 0};
    else {
        fibo = linearFibonacci(k - 1);
        return {fibo.first + fibo.second, fibo.first};
    } 
}

// int* linearFibonacciArray(int k) 
// {
//     int* pair = new int[2];
//     if (k<=1) {
//         pair[0] = k;
//         pair[1] = 0;
//         return pair;
//     } else {
//         pair = linearFibonacciArray(k-1);
//         int temp = pair[0];
//         pair[0] = pair[0]+pair[1];
//         pair[1] = temp;
//         return pair;
//     }
// } Memory Leak!!!

std::unique_ptr<int[]> linearFibonacciArray(int k) {
    std::unique_ptr<int[]> pair(new int[2]);
    if(k <= 1) {
        pair[0] = k;
        pair[1] = 0;
        return pair;
    } else {
        pair = linearFibonacciArray(k - 1);
        int tmp = pair[0];
        pair[0] = pair[0] + pair[1];
        pair[1] = tmp;
        return pair;
    }
}

std::vector<int> linearFibonacciVectorS(int k) {
    std::vector<int> pair{0, 0};
    if(k <= 1) {
        pair[0] = k;
        pair[1] = 0;
        return pair;
    } else {
        pair = linearFibonacciVectorS(k - 1);
        int tmp = pair[0];
        pair[0] = pair[0] + pair[1];
        pair[1] = tmp;
        return pair;
    }
}

// std::vector<int>* linearFibonacciVectorH(int k) {
//     std::vector<int>* pair = new std::vector<int>(2);
//     if (k<=1) {
//         pair->front() = k;
//         pair->back() = 0;
//         return pair;
//     } else {
//         pair = linearFibonacciVectorH(k-1);
//         int temp = pair->front();
//         pair->front() = pair->front()+pair->back();
//         pair->back() = temp;
//         return pair;
//     }
// } Memory leak!!!

// std::unique_ptr<std::vector<int>> linearFibonacciVectorH(int k) {
//     std::unique_ptr<std::vector<int>> pair(new std::vector<int>[2]);
//     if(k <= 1) {
//         pair->front() = k;
//         pair->back() = 0;
//         return pair;
//     } else {
//         pair = linearFibonacciVectorH(k - 1);
//         int tmp = pair->front();
//         pair->front() = pair->front() + pair->back();
//         pair->back() = tmp;
//         return pair;
//     }
// } Segmentation fault!!!

int main() {
    auto fiboPair = linearFibonacciPair(10);
    std::cout << fiboPair.first << ", " << fiboPair.second << '\n';

    auto fiboTuple = linearFibonacciTuple(10);
    std::cout << std::get<0>(fiboTuple) << ", " << std::get<1>(fiboTuple) << '\n';

    auto fiboStruct = linearFibonacci(10);
    std::cout << fiboStruct.first << ", " << fiboStruct.second <<'\n';

    auto fiboArray = linearFibonacciArray(10);
    std::cout << fiboArray[0] << ", " << fiboArray[1] << '\n';

    auto fiboVectorS = linearFibonacciVectorS(10);
    std::cout << fiboVectorS[0] << ", " << fiboVectorS[1] << '\n';

    // auto fiboVectorH = linearFibonacciVectorH(10);
    // std::cout << fiboVectorH->at(0) << ", " << fiboVectorH->at(1) << '\n';

    return 0;
}