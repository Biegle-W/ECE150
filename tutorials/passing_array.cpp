#include <iostream>
#include <cmath>

int main();
void sort_array(int to_sort[3]);

void sort_array(int to_sort[3])
{
    int n{0};
    if (to_sort[0] > to_sort[1])
    {
        n = to_sort[0];
        to_sort[0] = to_sort[1];
        to_sort[1] = n;
    }
    if (to_sort[1] > to_sort[2])
    {
        n = to_sort[1];
        to_sort[1] = to_sort[2];
        to_sort[2] = n;
    }
    if (to_sort[0] > to_sort[1])
    {
        n = to_sort[0];
        to_sort[0] = to_sort[1];
        to_sort[1] = n;
    }
}
int main()
{
    int array[3]{};
    std::cin >> array[0] >> array[1] >> array[2];
    sort_array(array);
    std::cout << array[0] << " "<< array[1] << " " << array[2] << std::endl;
}

