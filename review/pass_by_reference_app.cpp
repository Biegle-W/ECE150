//multiple returns
void min_max( int a, int b, int c, int &min, int &max )
{
    if ( a < b )
    {
        min = a;
        max = b;
    }
    else
    {
        min = b;
        max = a;
    }

    if ( c < min )
    {
        min = c;
    }
    else if ( c > max )
    {
        max = c;
    }
}

//check overflow
int add( int a, int b, bool &invalid_result )
{
    int result{ a + b };
    // The result is invalid if
    //           'a' and 'b' are positive yet 'a + b' is negative, or
    //           'a' and 'b' are negative yet 'a + b' is positive
    invalid_result = ( ((a > 0) && (b > 0) && (result <= 0)) || ((a < 0) && (b < 0) && (result >= 0)) );

    return result;
}

int multiply( int a, int b, bool &invalid_result )
{
    int result{ a*b };
    // The result is invalid if '(a*b)/b != a' for a non-zero 'b'
    //  - a*0 = 0 for all possible values of 'a'
    invalid_result = ( (b != 0) && (result/b != a) );

    return result;
}

int main();
int main()
{
    return 0; 
}
