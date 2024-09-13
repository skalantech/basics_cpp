#include <iostream>
#include <vector>
#include <memory>

int main()
{
    std::vector<int>* arr_int = new std::vector<int>;
    arr_int->push_back(1);
    arr_int->push_back(2);
    std::cout << arr_int->size() << '\n';

    // Print the elements of arr_int
    for (int i = 0; i < arr_int->size(); ++i) {
        std::cout << (*arr_int)[i] << " ";
    }
    std::cout << '\n';

    delete arr_int;

    /////////////////////////////////////////////////
    std::unique_ptr<std::vector<int>> arr_int_uptr = std::make_unique<std::vector<int>>();
    arr_int_uptr->push_back(1);
    arr_int_uptr->push_back(2);

    // Print the elements of arr_int_uptr
    for (int i = 0; i < arr_int_uptr->size(); ++i) {
        std::cout << (*arr_int)[i] << " ";
    }
    std::cout <<'\n';


    return 0;
}