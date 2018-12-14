#include <iostream>
#include <algorithm> // std::min, std::max 
#include <utility> // std::swap

template <typename T>
T max( T a, T b );

template <typename T>
T max( T a, T b )
{
    if ( a >= b )
    {
        return a;
    }
    else
    {
        return b;
    }
}

template <typename T>
void swap( T &a, T &b );

template <typename T>
void swap( T &a, T &b )
{
    T tmp{a};
    a = b;
    b = tmp;
}

template <typename T>
T array_max( T const array[], std::size_t const capacity, std::size_t &location )
{
    T max{array[0]};
    location = 0;

    for ( std::size_t k{1}; k < capacity; ++k )
    {
        if ( array[k] > max )
        {
            max = array[k];
            location = k;
        }
    }

    return max;
}


int main()
{
    long a{5928395425359233};
    double x{3.14};

    std::cout << max<double>( a, x ) << std::endl;


    int array[10]{1, 5, 5, 2, 4, 7, 6, 2, 4, 5};

    for ( int k{0}; k < 10; ++k )
    {
        std::cout << k << ": " << std::count( array, array + 10, k ) << std::endl; // Pointer arithmetic! – The address of the first entry – The address one beyond the last entry
    }

    for ( int k{0}; k < 10; ++k )
    {
        int *p_loc = std::find( array, array + 10, k );

        if ( p_loc != array + 10 )
        {
            std::cout << k << ": array[" << (p_loc - array) << "] == " << *p_loc << std::endl; // Pointer difference! – The number of positions between the two addresses
        }
    }

    int *p_min{ std::min_element( array, array + 10 ) };
    int *p_max{ std::max_element( array, array + 10 ) };

    std::cout << "Minimum: array[" << (p_min - array) << "] == " << *p_min << std::endl;
    std::cout << "Maximum: array[" << (p_max - array) << "] == " << *p_max << std::endl; // Pointer difference! – The number of positions between the two addresses




    return 0;
}
