#include <iostream>

// Class declaration
class String;

// Function declaration
int main();

// Class definition
class String {
    public:
        // Constructor
        String( std::size_t max_length = 32 );
        // Destructor
       ~String();

       // Member function declarations
       char get_char( std::size_t n ) const;
       std::size_t length() const;
       std::size_t max_length() const;
       char const *get_character_array() const;
       char       *copy_character_array() const;
       void        set_char( std::size_t n, char ch );


    private:
        std::size_t array_capacity;
        std::size_t string_length;
        char *character_array;
};

// Constructor definition
String::String( std::size_t max_length ):
array_capacity{max_length + 1},
string_length{0},
character_array{new char[array_capacity]} {
    character_array[0] = '\0';
    std::cout << "Finished calling 'String( "
              << max_length << " )" << std::endl;
}

// Destructor definition
String::~String() {
    std::cout << "Calling ~String() with " << array_capacity
              << std::endl;
    delete[] character_array;
    character_array = nullptr;
}

char String::get_char( std::size_t n ) const {
    return ( n < string_length ) ? character_array[n] : '\0';
}

void String::set_char( std::size_t n, char ch ) {
    if ( n < string_length ) {
        character_array[n] = ch;
    } else if ( n < array_capacity ) {
        // Set all entries after the last to 'ch'
        for ( std::size_t k{string_length}; k <= n; ++k ) {
            character_array[k] = ch;
        }

        string_length = n + 1;
        character_array[string_length] = '\0';
    } else {
        throw n;
    }
}

std::size_t String::length() const {
    return string_length;
}

std::size_t String::max_length() const {
    return array_capacity - 1;
}

char const *String::get_character_array() const {
    return character_array;
}

char *String::copy_character_array() const {
    char *return_array{new char[string_length + 1]};

    for ( std::size_t k{0}; k <= string_length; ++k ) {
        return_array[k] = character_array[k];
    }

    return return_array;
}

int main() {
    String str{256};
    String *p_str{new String{}};

    str.set_char( 0, 'H' );
    str.set_char( 1, 'i' );

    std::cout << "The array length is now " << str.length() << std::endl;
    std::cout << str.get_character_array() << std::endl;

    p_str->set_char( 0, 'B' );
    p_str->set_char( 1, 'y' );
    p_str->set_char( 2, 'e' );

    std::cout << "The array length is now " << p_str->length() << std::endl;
    std::cout << p_str->get_character_array() << std::endl;

    delete p_str;
    p_str = nullptr;
    return 0;
}
