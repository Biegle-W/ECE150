#include <iostream>

int main()
{
    int x{42};
    int y{33};
    int *p_x{&x};           // ALLOWED: Change value of variable x via p_x.

    std::cout << *p_x << " : " << x << std::endl;
    *p_x = 22;
    std::cout << *p_x << " : " << x << std::endl;


    int const *p_x_1{&x};   // READ: Pointer to constant integer.
                            // DISALLOWED: Change value of variable x via p_x.

    std::cout << *p_x_1 << " : " << x << std::endl;
    *p_x_1 = 22;
    std::cout << *p_x_1 << " : " << x << std::endl;



    int *const p_x{&x};     // DISALLOWED: Change the address held in p_x.

    std::cout << p_x << " : " << &x << std::endl;
    p_x = &y;
    std::cout << p_x << " : " << &y << std::endl;



    // READ: Constant pointer to constant integer.
    int const *const p_x{&x};

    // DISALLOWED: Change the address held in p_x.
    std::cout << p_x << " : " << &x << std::endl;
    p_x = &y;
    std::cout << p_x << " : " << &y << std::endl;

    // DISALLOWED: Change the value of variable pointed to by p_x.
    std::cout << p_x << " : " << &x << std::endl;
    *p_x = 22;
    std::cout << p_x << " : " << &x << std::endl;


    return 0;
}
