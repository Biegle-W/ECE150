#include <iostream>
#include <algorithm>

template <typename T>
std::size_t linear_search( T const array[], std::size_t const capacity, T const &sought_value )
{
    for ( std::size_t k{0}; k < capacity; ++k )
    {
        if ( array[k] == sought_value )
        {
            return k;
        }
    }

    return capacity;
}

template <typename T>
std::size_t linear_search( T const array[], std::size_t const begin, std::size_t const end, T const &sought_value )
{
    for ( std::size_t k{begin}; k < end; ++k )
    {
        if ( array[k] == sought_value )
        {
            return k;
        }
    }

    return end;
}

int main()
{
    int array[10]{1, 5, 5, 2, 4, 7, 6, 2, 4, 5};

    for ( int k{0}; k < 10; ++k )
    {
        int *p_loc{std::search( array, array + 10, &k, &k + 1 )};

        if ( p_loc != (array + 10) )
        {
            std::cout << k << ": array[" << (p_loc - array) << "] == " << *p_loc << std::endl;
        }
    }

    return 0;
}
