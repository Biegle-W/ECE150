#include <iostream>
#include <cmath>

#ifndef MARMOSET_TESTING
int main();
#endif

int pascal_triangle( int n);
int pascal_triangle_recursive( int n);

int pascal_triangle( int n)
{
    int a[n+1][n+1];
    std::size_t i,j;
    for( i=0;i<=n;i++)
    {
        for( j=0;j<=i;j++)
        {
            if(j==0||j==i)
            {
                a[i][j]=1;
            }
            else
            {
                a[i][j]=a[i-1][j-1]+a[i-1][j];
            }
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return (n+1)*(n+2)/2;
}

int recursive_help(int row, int column)
{
    if (column == 1 || column == row + 1)
    {
        return 1;
    }
    else
    {
        return recursive_help(row - 1, column - 1) + recursive_help(row - 1, column);
    }
}

int pascal_triangle_recursive(int n)
{
    for (std::size_t i = 0; i <= n; ++i){
        for (std::size_t j = 1; j <= i + 1; ++j)
        {
            std::cout << recursive_help(i, j);
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    return (n+2)*(n+1)/2;
}

#ifndef MARMOSET_TESTING
int main()
{
    int n=0;
    std::cin >> n;
    std::cout << pascal_triangle(n) << std::endl;

    return 0;
}
#endif
