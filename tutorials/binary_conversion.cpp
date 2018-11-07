#include <iostream>
using namespace std;

int main();

int main(){
    int decimal_number =0;

    std::cout <<"Enter number to convert";
    std::cin  >> decimal_number;

    std::cout << decimal_number / 256;
    decimal_number = decimal_number % 256;
    std::cout << decimal_number / 128;
    decimal_number = decimal_number % 128;
    std::cout << decimal_number / 64;
    decimal_number = decimal_number % 64;
    std::cout << decimal_number / 32;
    decimal_number = decimal_number % 32;
    std::cout << decimal_number / 16;
    decimal_number = decimal_number % 16;
    std::cout << decimal_number /8;
    decimal_number = decimal_number % 8;
    std::cout << decimal_number / 4;
    decimal_number = decimal_number % 4;
    std::cout << decimal_number / 2;
    decimal_number = decimal_number % 2;
    std::cout << decimal_number;

    return 0;

}
