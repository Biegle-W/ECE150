#include <iostream>
#include <utility>
#include <algorithm>

template <typename T>
void selection_sort( T array[], std::size_t const capacity )
{
    for ( std::size_t k{capacity - 1}; k > 0; --k )
    {
        std::size_t index_max{find_max( array, 0, k + 1 )};
        std::swap( array[index_max], array[k] );
    }
}

template <typename T>
void selection_sort( T array[], std::size_t const begin, std::size_t const end )
{
    for ( std::size_t k{end - 1}; k > begin; --k )
    {
        std::size_t index_max{find_max( array, begin, k + 1 )};
        std::swap( array[index_max], array[k] );
    }
}

int main()
{
    return 0; 
}
