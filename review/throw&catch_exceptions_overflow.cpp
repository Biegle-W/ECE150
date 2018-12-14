#include <iostream>
#include <cmath>

int add( int m, int n )
{
    int result = m + n;

    if ( ((m > 0) && (n > 0) && (result <= 0)) || ((m < 0) && (n < 0) && (result >= 0)) )
    {
        throw 0;  // The value can be any literal or other instance of any type
    }

    return result;
}

int main()
{
    try
    {
        std::cout << add( 2147483646, 1 ) << std::endl;
    }
    catch( int overflow )
    {
        std::cout << "An exception was thrown..." << std::endl;
    }

    std::cout << "Finished first try-catch block..." << std::endl;

    try
    {
        std::cout << add( 2147483647, 1 ) << std::endl;
    }
    catch( ... )
    {
        std::cout << "An exception was thrown..." << std::endl;
    }

    std::cout << "Finished second try-catch block..." << std::endl;

    return 0;
}
