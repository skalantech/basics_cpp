#include <iostream>
#include <chrono>

int main () {

    auto start = std::chrono::steady_clock::now();

    int i, j;
    int count{0};
    
    for(i = 2; i<10000; i++) {

        for(j = 2; j <= (i/j); j++) 
            if(!(i%j)) break; 
        if(j > (i/j))
        {
            //std::cout << i << " is prime" << std::endl;
            count++;
        }
    }
    std::cout << "there are " << count << " prime numbers from 0 to " << i << std::endl;
    
    auto end = std::chrono::steady_clock::now();
    /*
    std::cout << "Runtime: "
        << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() 
        << "ms" << std::endl;
    */
    auto time_taken = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    
    std::cout << "Time taken: " << static_cast<double>(time_taken)/10000 << std::endl;
        
    return 0;
}
