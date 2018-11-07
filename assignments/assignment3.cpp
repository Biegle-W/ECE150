#include <iostream>
#include <cmath>

int max( int data[], std::size_t capacity ); // question 1
int max( int data[], std::size_t capacity )
{
    int max_num=0;
    for (std::size_t i=0; i < capacity; i++)
    {
        if (data[i] > max_num)
        {
            max_num = data[i];
        }
    }

    return max_num;
}

unsigned int ones( bool binary_string[], std::size_t capacity ); // question 2
unsigned int ones( bool binary_string[], std::size_t capacity )
{
    int num_ones=0;
    for (std::size_t i=0; i < capacity;i++ )
    {
        if (binary_string[i] == 1)
        {
            num_ones++;
        }
    }

    return num_ones;
}

int bin2dec( bool binary_string[16] ); // question 3
int bin2dec( bool binary_string[16] )
{
    int decimal=0;

    if (binary_string[0] == 1)
    {

    }

    if (binary_string[0] == 0)
    {
        for (std::size_t i=0; i < 16; i++)
        {
            for (std::size_t j=15; j >= 0; j--)
            {
                    decimal += binary_string[i] * pow(2, j);
            }
        }
    }

    return decimal;
}

void reverse( int data[], std::size_t capacity); // question 4
void reverse( int data[], std::size_t capacity)
{
    std::size_t i = 0;
    std::size_t j = capacity - 1;
    while ( i <= j )
    {
        int temp{0};
        temp = data[i];
        data[i] = data[j];
        data[j] = temp;
        i++;
        j--;
    }
}

void rotate(int data[], std::size_t capacity, unsigned int rotate_by); //question 5
void rotate(int data[], std::size_t capacity, unsigned int rotate_by)
{
       //store data elements into a temprary array
       int temprary[capacity];
       for (int index{ 0 }; index < capacity; index++)
       {
           temprary[index] = data[index];
       }
       for (int index{ 0 }; index < capacity; index++)
       {
           int new_index = index + rotate_by;
           new_index = new_index % capacity;
           data[new_index] = temprary[index];
       }
}

bool palindrome(char data[], std::size_t capacity); //question 6
bool palindrome(char data[], std::size_t capacity)
{
    for (int index = 0; index < capacity; index++)
    {
        if (!(data[index] == data[capacity - index - 1]))

        return false;
    }

    return true;
}

struct personalAddress //question 7
{
    std::string address_line_1;
    std::string address_line_2;
    std::string country;
    std::string province;
    std::string postal_code;
};


struct three_ints_t //question 8
{
       int integer1;
       int integer2;
       int integer3;
};

three_ints_t largest_three(int data[], std::size_t capacity);
three_ints_t largest_three(int data[], std::size_t capacity)
{
    int max1{ 0 };
    int max2{ 0 };
    int max3{ 0 };
    for (int index{ 0 }; index < capacity; index++)
    {
        if (data[index] > max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = data[index];
        }
        else if (data[index] > max2)
        {
            max3 = max2;
            max2 = data[index];
        }
        else if (data[index] > max3)
        {
            max3 = data[index];
        }
    }

three_ints_t three_largest
{
    max1,
    max2,
    max3
};

    return three_largest;
}

struct point_t // question 9
{
    double x;
    double y;
};

double distance(point_t u, point_t v);
double distance(point_t u, point_t v)
{
    return std::sqrt((u.x - v.x)*(u.x - v.x) + (u.y - v.y)*(u.y - v.y));
}

int main();
int main()
{

    return 0;
}
