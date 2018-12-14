#include <iostream>
#include <string>

struct string_t
{
    char *string;
    std::size_t length;
    std::size_t capacity;
};

void string_init( string_t &str, std::size_t cap )
{
        str.capacity = cap;
        str.string = new char[str.capacity];
        str.length = 0;
}

std::size_t string_length( char *s_str )
{
    for ( std::size_t k{0}; true; ++k )
    {
        if ( s_str[k] == '\0' )
        {
            return k;
        }
    }
}

char *string_copy( char *s_str )
{
    std::size_t length{string_length( s_str )};
    char *s_result{new char[length + 1]};

    for ( std::size_t k{0}; k <= length; ++k )
    {
        s_result[k] = s_str[k];
    }

    return s_result;
}

char *string_concat( char *s_1, char *s_2 )
{
    std::size_t length_1{string_length( s_1 )};
    std::size_t length_2{string_length( s_2 )};
    char *s_result{new char[length_1 + length_2 + 1]};

    std::size_t k{0};
    for ( std::size_t i{0}; i < length_1; ++i, ++k )
    {
        s_result[k] = s_1[i];
    }

    for ( std::size_t i{0}; i <= length_2; ++i, ++k )
    {
        s_result[k] = s_2[i];
    }

    return s_result;
}

int main();

int main()
{
    char *s_hi{(char *)"Hello world!"};

    std::cout << s_hi << std::endl;                             // if you  print "a pointer to a character", it prints a string. If you want the address printed, you must indicate that it is a generic address:
    std::cout << reinterpret_cast<void *>( s_hi ) << std::endl; // Reinterpret the pointer to a char as a generic address type: void *p_generic_address;


    char *s_str{(char *)"Hello world."};
    std::cout << s_str << std::endl;

    // s_str[12] = '!';                        //If we want to edit a string, it cannot be a literal string. This cause segmentation fault!!!
    char *s_copy{string_copy( s_str )};     // make a copy and then edit it
    s_copy[11] = '!';

    std::cout << s_copy << std::endl;

    delete[] s_copy;


    char *s_copy_1{string_copy( s_str )};     // Swap characters 7 and 8
    char ch{s_copy_1[8]};

    s_copy_1[8] = s_copy_1[7];
    s_copy_1[7] = ch;

    std::cout << s_copy_1 << std::endl;

    delete[] s_copy_1;


    char *s_copy_2{string_copy( s_str )};     // Remove the 5th character

    for ( std::size_t k{5}; s_str[k] != '\0'; ++k )
    {
        s_copy_2[k] = s_copy_2[k + 1];
    }

    std::cout << s_copy_2 << std::endl;

    delete[] s_copy_2;

    return 0;
}
