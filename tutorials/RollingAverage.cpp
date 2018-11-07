#include <iostream>

#ifndef MARMOSET_TESTING
int main();
#endif

float rolling_average(float a, float b, float c);

float rolling_average(float a, float b, float c)
{
    return (a+b+c)/3;
}

#ifndef MARMOSET_TESTING
int main()
{
    float x{0}; // input
    int i{0}; // count the number of input in the subset, start at 0
    int j{0}; // point the position of input in the subset, start at the first position
    float subset[3]={0, 0, 0}; // subset of 3
    while (true)
    {
        std::cout << "Enter a number." << std::endl;
        std::cin >> x; // input value
        if (x<0)
        {
            break; // if enter a negative number exist the loop
        }
        if (j==3) // if enter another positive number to the subset when the subset already have 3 positive number in it
        {
            j--; // point the input to the last position of the subset
            subset[0]=subset[1]; // the first two numbers in the subset roll forward one place
            subset[1]=subset[2];
        }
        subset[j] = x; // input the value to the subset where the pointer is located
        i++;// count the number of input
        j++;// point to the next position of the subset
        if (i>=3) // if have input more than 3 positive numbers
        {
            std::cout <<"rolling average is: " << rolling_average(subset[0], subset[1], subset[2]) << std::endl;
            // calculate the rooling average of the subset
        }
        
    }
    return 0;
    
}
#endif
