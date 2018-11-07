#include <iostream>

int main();
void pointer_mechanics_1();

int main()
{
    pointer_mechanics_1();

    return 0;
}

void pointer_mechanics_1()
{
    // TODO - declare a pointer to an int and initialize it to nullptr


    int * p_data {nullptr};
    // TODO - Allocate memory to store an int and use the declared
    // pointer to reference this newly allocated memory location.
    // Initialize the value in this memory location to 25.


    p_data = new int{25};
    // TODO - modify the following statement to output
    // the address of the dynamic int variable

    std::cout << "address of the dynamic int variable: " << p_data << std::endl;

    // TODO - modify the following statement to output
    // the address of the pointer

    std::cout << "address of the pointer: " << & p_data << std::endl;

    // TODO - modify the following statement to output
    // the value stored in the dynamic int variable

    std::cout << "value stored in the dynamic int variable: " << * p_data << std::endl;

    // TODO - modify the following statement to output
    // the value stored in the pointer

    std::cout << "value stored in the pointer: " << std::endl;

    // TODO - draw and label a diagram illustrating the state of memory

    // TODO - deallocate the dynamic int variable
    // TODO - set the pointer to nullptr

    delete p_data;
    p_data = nullptr;

    // TODO - modify the following statement to output
    // the value stored in the pointer

    std::cout << std::endl;
    std::cout << "after de-allocation and setting to nullptr" << std::endl;
    std::cout << "value stored in the pointer: " << p_data << std::endl;
}
