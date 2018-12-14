#include <iostream>
#include <cmath>

double PI{3.1415926535897932};
double PI_BY_2{PI/2.0};
double TWO_PI{2.0*PI};

// describe the behavior between 0 and pi/2
double fast_sin_1( double x )
{
      if ( (x >= 0) && (x <= PI_BY_2) )
      {
          // Minimize the worst-case relative error
          return ( (-0.12982726700166469*x - 0.031041616418863258)*x + 1.0034924244212799 )*x;
      }
      else
      {
          return std::nan( "" );
      }
  }

// sin is an odd function
  double fast_sin_2( double x )
  {
        if ( x < 0 )
        {
            return -fast_sin_2(-x);
        }
        else if ( x <= PI_BY_2)
        {
            // Minimize the worst-case relative error
            return ( (-0.12982726700166469*x - 0.031041616418863258)*x + 1.0034924244212799 )*x;
        }
        else
        {
            return std::nan( "" );
        }
    }

// sin is symmetrical to pi/2
double fast_sin_3( double x )
{
      if ( x < 0 )
      {
          return -fast_sin_3(-x);
      }
      else if ( x <= PI_BY_2 )
      {
          // Minimize the worst-case relative error
          return ( (-0.12982726700166469*x - 0.031041616418863258)*x + 1.0034924244212799 )*x;
      }
      else if ( x <= PI )
      {
          return fast_sin_3( PI - x );
      }
      else
      {
          return std::nan( "" );
      }
  }

  // if pi < x <= 2pi, then sin(x) = -sin(x-pi)
  // sin is a peroidic function with period of 2pi
  double fast_sin_4( double x )
  {
    if ( x < 0 )
    {
        return -fast_sin_4(-x);
    }
    else if ( x <= PI_BY_2 )
    {
        // Minimize the worst-case relative error
        return ( (-0.12982726700166469*x - 0.031041616418863258)*x + 1.0034924244212799 )*x;
    }
    else if ( x <= PI )
    {
        return fast_sin_4( PI - x );
    }
    else if ( x <= TWO_PI )
    {
        return fast_sin_4( x - PI );
    }
    else
    {
        double n{std::floor(x/TWO_PI)};
        return fast_sin_4( x - TWO_PI*n );
    }
}

int main()
{
    double input{0};

    std::cin >> input;
    std::cout << fast_sin_4(input) << std::endl;

    return 0;
}
