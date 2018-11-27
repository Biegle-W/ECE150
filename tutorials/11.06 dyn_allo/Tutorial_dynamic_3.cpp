// This exercise is intended to show the persistence of a dynamically
// allocated variable outside the scope of the function in which it was
// allocated. The variable is allocated in create_double() and
// returned, passed to print_double() and outputted, then passed to
// dealloc_double() to be deallocated.

#include <iostream>

int main();
void pointer_mechanics_3();
double * create_double(double const initial_value);
void print_double(double * p_double);
void dealloc_double(double * & p_double);

int main()
{
    pointer_mechanics_3();

    return 0;
}

// TODO - complete the following function definition to do the following:
//      - dynamically allocate memory to store a double
//      - initializes the values stored in the double to the passed initial_value
//      - returns a pointer to this newly allocated memory location
double * create_double(double const initial_value)
{
  double * p_temp = new double{initial_value};

  return p_temp;
}

// TODO - complete the following function definition to do the following:
//      - if p_double is pointing to nullptr
//          - output a message indicating it is pointing to nullptr
//      - else
//          - dereference the pointer and output the value
void print_double(double * p_double)
{
    if (p_double == nullptr)
    {
        std::cout << "pointer is nullptr." << std::endl;
    }
    else
    {
        std::cout << "p_double value: " << *p_double << std::endl;
    }
}

// TODO - complete the following function definition to do the following:
//      - deallocate the memory location where p_double is pointing
//      - assign p_double to point to nullptr
void dealloc_double(double * & p_double)
{
    delete p_double;
    p_double = nullptr;
}

void pointer_mechanics_3()
{
    double * p_1 = {create_double(7.13)};
    double * p_2{nullptr};

    print_double(p_1);
    print_double(p_2);

    dealloc_double(p_1);
    dealloc_double(p_2);

    print_double(p_1);
}
