#include <iostream>
#include <cmath>

int main();
int reverse_a_number(int in);
bool is_palindrome(int in);

int reverse_a_number(int in)
{
    int out{0}; // the return value
    int unreversed{0}; // the number with left over digits which haven't been reversed
    int reversed{0}; // the digits have been reversed
    int i = log10(in); // point to the position where the current last digit should be placed

    unreversed = in;

    while (unreversed > 0) // no number left over, when all digits have been reversed
    {
        reversed = unreversed % 10; // calculate the current last digit
        out = out + (reversed * pow(10, i)); // reverse the last digit
        unreversed = unreversed / 10; // last digit moves one digit forward
        i--; // pointer moves one digit backward
    }
    return  out;
}

bool is_palindrome(int in)
{
    bool judge{false};

    if (in == reverse_a_number(in))
    {
        judge = true;
    }
    return judge;
}


int main()
{
    int in{0};
    std::cout << "Enter a Number" << std::endl;
    std::cin >> in;
    std::cout << reverse_a_number(in) << std::endl;
    if (is_palindrome(in) == true)
    {
        std::cout << in << " is palindrome." << std::endl;
    }
    else
    {
        std::cout << in << " is not palindrome." << std::endl;
    }
    return 0;
}
