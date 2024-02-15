#include <iostream>
#include <chrono>

void printTime (auto start, auto end) {

    std::cout << "Elapsed time in nanoseconds: "
            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
            << " ms" << std::endl;

    std::cout << "Elapsed time in microseconds: "
        << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
        << " us" << std::endl;
        
    std::cout << "Elapsed time in milliseconds: "
        << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
        << " ms" << std::endl;
        
    std::cout << "Elapsed time in seconds: "
        << std::chrono::duration_cast<std::chrono::seconds>(end - start).count()
        << " sec";

}