#include <iostream>

template <typename T>
std::size_t binary_search( T const array[], std::size_t const capacity, T const sought_value ) //wrong
{
    std::size_t left{0};
    std::size_t right{capacity - 1};

    while ( left != right )
    {
        std::size_t midpoint{(left + right)/2};

        if ( array[midpoint] == sought_value )
        {
            return midpoint;
        }
        else if ( array[midpoint] > sought_value )
        {
            right = midpoint - 1;
        }
        else
        {
            left = midpoint + 1;
        }
    }

    return (array[left] == sought_value) ? left : capacity;
}

template <typename T>
std::size_t binary_search_1( T const array[], std::size_t const capacity, T const sought_value )
{
    std::size_t left{0};
    std::size_t right{capacity - 1};

    while ( left != right )
    {
        std::size_t midpoint{(left + right)/2};

        if ( array[midpoint] == sought_value )
        {
            return midpoint;
        }
        else if ( array[midpoint] > sought_value )
        {
            if ( left == midpoint )
            {
                return capacity;
            }
            else
            {
                right = midpoint - 1;
            }
        }
        else
        {
            if ( midpoint == right )
            {
                return capacity;
            }
            else
            {
                left = midpoint + 1;
            }
        }
    }

    return (array[left] == sought_value) ? left : capacity;
}

template <typename T>
std::size_t binary_search_2( T const array[], std::size_t const capacity, T const sought_value )
{
    if ( sought_value < array[0] )
    {
        return capacity;
    }
    std::size_t left{0};
    std::size_t right{capacity - 1};

    while ( left <= right )
    {
        std::size_t midpoint{(left + right)/2};

        if ( array[midpoint] == sought_value )
        {
            return midpoint;
        }
        else if ( array[midpoint] > sought_value )
        {
            right = midpoint - 1;
        }
        else
        {
            left = midpoint + 1;
        }
    }

    return capacity;
}

int main()
{
    return 0;
}
