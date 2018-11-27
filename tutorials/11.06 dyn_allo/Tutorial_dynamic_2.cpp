#include <iostream>

int main();
void pointer_mechanics_2();

int main()
{
    pointer_mechanics_2();

    return 0;
}

void pointer_mechanics_2()
{
    // TODO - declare an int variable and initialize its value to 99
    // TODO - declare a pointer to an int and initialize it to nullptr
    int data{99};
    int * p_data{nullptr};


    // TODO - assign the pointer to the address of the local int variable
    p_data = &data;


    // TODO - dereference the pointer and change its value to 43
    *p_data = 43;


    // TODO - modify the following two statements to output the value
    // of the local int variable and the value of the dereferenced pointer

    std::cout << "value of local int variable: " << data << std::endl;
    std::cout << "value of dereferenced pointer: " << *p_data << std::endl;

    // TODO - using the local int variable, assign it a new value of 77

    data = 77;
    // TODO - modify the following two statements to output the value
    // of the local int variable and the value of the dereferenced pointer

    std::cout << "value of local int variable: " << data << std::endl;
    std::cout << "value of dereferenced pointer: " << *p_data << std::endl;

    // TODO - draw and label a diagram illustrating the state of memory
}
