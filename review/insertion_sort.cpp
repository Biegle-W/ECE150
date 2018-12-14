#include <iostream>
#include <utility>

template <typename T>
void insertion_sort( T array[], std::size_t const capacity )
{
    for ( std::size_t k{1}; k < capacity; ++k )
    {
        // Keep swapping to the left
        for ( std::size_t i{k}; i > 0; --i )
        {
            if ( array[i - 1] > array[i] )
            {
                std::swap( array[i - 1], array[i] );
            }
            else
            {
                // If array[i - 1] >= array[i], they are in order
                break;
            }
        }
    }
}

int main()
{
    return 0;
}
