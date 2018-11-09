#include <iostream>

void Illegal_interval (double a, double b);
void illegal_interval (double a, double b)
{
    if (a > b)
    {
        throw -1;
    }
}

int main();
int main()
{
    int a{0}, b{0};
    std::cin >> a >> b;
    try
    {
        illegal_interval(a, b);
    }
    catch (int illegal)
    {
        std::cout << "Illegal interval [" << a << ", " << b << " identified. ";
        int temp{a};
        a = b;
        b = temp;
        std::cout << "Corrected to [" << a << ", " << b << "]. " << std::endl;
    }

    return 0;
}
