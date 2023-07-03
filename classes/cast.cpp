#include <iostream>

int  i = 17;
char C = 'c'; /* ascii value is 99 */
float sum;

int suma = 17, count = 5;
double mean;

int64_t a = 1234;
double d = static_cast<double>(a);
double f = a;

int64_t b = 5432;
double c = double(b);

int64_t p = 9876;
double h = (double)p;       // least recommended

int main()
{
    sum = i + C;
    printf("Value of sum : %f\n", sum );

    mean = (double) suma / count;
    printf("Value of mean : %f\n", mean );

    std::cout << "a: " << a << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "f: " << f << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "p: " << p << std::endl;
    std::cout << "h: " << h << std::endl;

    return 0;
}

