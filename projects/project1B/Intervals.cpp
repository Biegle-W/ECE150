#include <iostream>
#include <string>
#include <cmath>
int main();
void interval_calculator();

void interval_calculator()
{
    double a{1}, b{-1};
    double e{1}, f{-1};
    double c{0}, d{0};
    double x{1}, y{-1};
    double n{0};
    double useless{0};
    std::string str{};

    while (true)
    {
        std::cout << "input :> ";
        std::cin >> str;

        if (str == "enter") // initialized immediate interval
        {
            std::cin >> e >> f;
            if (e > f)
            {
                std::cout << "Error: invalid interval as " << e << " > " << f << std::endl;
                if ( (a==1) && (b==-1) )
                {
                    std::cout << "--" << std::endl;
                }
                else
                {
                    std::cout << "[" << a << ", " << b << "]" << std::endl;
                }
            }
            else
            {
                a=e;
                b=f;
                std::cout << "[" << a << ", " << b << "]" << std::endl;
            }
        }
        else if (str == "negate")
        {
            if ( (a==1) && (b==-1) )
            {
                std::cout << "--" << std::endl;
            }
            else
            {
                n = a;
                a = -b;
                b = -n;
                std::cout << "[" << a << ", " << b << "]" << std::endl;
            }
        }
        else if (str == "invert")
        {
            if ( (a==1) && (b==-1) )
            {
                std::cout << "--" << std::endl;
            }
            else
            {
                if ( (a * b) < 0 )
                {
                    std::cout << "Error: division by zero" << std::endl << "--" << std::endl;
                }
                else
                {
                    n = a;
                    a = 1/b;
                    b = 1/n;
                    std::cout << "[" << a << ", " << b << "]" << std::endl;
                }
            }
        }
        else if (str == "ms") // assign immediate interval to memory-stored interval; print the immediate interval
        {
            if ( (a==1) && (b==-1) )
            {
                std::cout << "--" << std::endl;
            }
            else
            {
                x = a;
                y = b;
                std::cout << "[" << a << ", " << b << "]" << std::endl;
            }
        }
        else if (str == "mr") // copy memory-stored interval to immediate interval; print the immediate interval
        {
            if ( (a==1) && (b==-1) )
            {
                std::cout << "--" << std::endl;
            }
            else
            {
                if ( (x!=1) && (y!=-1) )
                {
                    a = x;
                    b = y;
                }
                std::cout << "[" << a << ", " << b << "]" << std::endl;
            }
        }
        else if (str == "mc")
        {
            if ( (a==1) && (b==-1) )
            {
                std::cout << "--" << std::endl;
            }
            else
            {
                x = 1;
                y = -1;
                std::cout << "[" << a << ", " << b << "]" << std::endl;
            }
        }
        else if (str == "m+")
        {
            if ( (a==1) && (b==-1) )
            {
                std::cout << "--" << std::endl;
            }
            else
            {
                if ( (x!=1) || (y!=-1) )
                {
                    x = x + a;
                    y = y + b;
                }
                std::cout << "[" << a << ", " << b << "]" << std::endl;
            }
        }
        else if (str == "m-")
        {
            if ( (a==1) && (b==-1) )
            {
                std::cout << "--" << std::endl;
            }
            else
            {
                if ( (x!=1) || (y!=-1) )
                {
                    x = x - a;
                    y = y - b;
                }
                std::cout << "[" << a << ", " << b << "]" << std::endl;
            }
        }
        else if (str == "scalar_add")
        {
            if ( (a==1) && (b==-1) )
            {
                std::cin >> useless;
                std::cout << "--" << std::endl;
            }
            else
            {
                std::cin >> c;
                a = a + c;
                b = b + c;
                std::cout << "[" << a << ", " << b << "]" << std::endl;
            }
        }
        else if (str == "scalar_subtract")
        {
            if ( (a==1) && (b==-1) )
            {
                std::cin >> useless;
                std::cout << "--" << std::endl;
            }
            else
            {
                std::cin >> c;
                a = a - c;
                b = b - c;
                std::cout << "[" << a << ", " << b << "]" << std::endl;
            }
        }
        else if (str == "scalar_multiply")
        {
            if ( (a==1) && (b==-1) )
            {
                std::cin >> useless;
                std::cout << "--" << std::endl;
            }
            else
            {
                std::cin >> c;
                if (c > 0)
                {
                    a = a * c;
                    b = b * c;
                }
                else if (c < 0)
                {
                    n = a;
                    a = b * c;
                    b = n * c;
                }
                else
                {
                    a = 0;
                    b = 0;
                }
                std::cout << "[" << a << ", " << b << "]" << std::endl;
            }

        }
        else if (str == "scalar_divide")
        {
            if ( (a==1) && (b==-1) )
            {
                std::cin >> useless;
                std::cout << "--" << std::endl;
            }
            else
            {
                std::cin >> c;
                if (c > 0)
                {
                    a = a / c;
                    b = b / c;
                    std::cout << "[" << a << ", " << b << "]" << std::endl;
                }
                else if (c < 0)
                {
                    n = a;
                    a = b / c;
                    b = n / c;
                    std::cout << "[" << a << ", " << b << "]" << std::endl;
                }
                else
                {
                    std::cout << "Error: division by zero" << std::endl << "--" << std::endl;
                    a=1;
                    b=-1;
                }
            }
        }
        else if (str == "scalar_divided_by")
        {
            if ( (a==1) && (b==-1) )
            {
                std::cin >> useless;
                std::cout << "--" << std::endl;
            }
            else
            {
                std::cin >> c;
                if ( (a * b) <= 0)
                {
                    std::cout << "Error: division by zero" << std::endl << "--" << std::endl;
                    a=1;
                    b=-1;
                }
                else if (c >= 0)
                {
                    n = a;
                    a = c / b;
                    b = c / n;
                    std::cout << "[" << a << ", " << b << "]" << std::endl;
                }
                else if (c < 0)
                {
                    a = c / a;
                    b = c / b;
                    std::cout << "[" << a << ", " << b << "]" << std::endl;
                }
            }
        }
        else if (str == "interval_add")
        {
            std::cin >> c >> d;
            if (c > d)
            {
                std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;
                if ( (a==1) && (b==-1) )
                {
                    std::cout << "--" << std::endl;
                }
                else
                {
                    std::cout << "[" << a << ", " << b << "]" << std::endl;
                }
            }
            else
            {
                if ( (a==1) && (b==-1) )
                {
                    std::cout << "--" << std::endl;
                }
                else
                {
                    a = a + c;
                    b = b + d;
                    std::cout << "[" << a << ", " << b << "]" << std::endl;
                }
            }

        }
        else if (str == "interval_subtract")
        {
            std::cin >> c >> d;
            if (c > d)
            {
                std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;
                if ( (a==1) && (b==-1) )
                {
                    std::cout << "--" << std::endl;
                }
                else
                {
                    std::cout << "[" << a << ", " << b << "]" << std::endl;
                }
            }
            else
            {
                if ( (a==1) && (b==-1) )
                {
                    std::cout << "--" << std::endl;
                }
                else
                {
                    a = a - d;
                    b = b - c;
                    std::cout << "[" << a << ", " << b << "]" << std::endl;
                }
            }

        }
        else if (str == "interval_multiply")
        {
            std::cin >> c >> d;
            if (c > d)
            {
                std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;
                if ( (a==1) && (b==-1) )
                {
                    std::cout << "--" << std::endl;
                }
                else
                {
                    std::cout << "[" << a << ", " << b << "]" << std::endl;
                }
            }
            else
            {
                if ( (a==1) && (b==-1) )
                {
                    std::cout << "--" << std::endl;
                }
                else
                {
                    double max{0}, min{0};

                    if ( (a*c) > (a*d) )
                    {
                        max = (a*c);
                        min = (a*d);
                    }
                    else
                    {
                        max = (a*d);
                        min = (a*c);
                    }
                    if ( max < (b*c) )
                    {
                        max = (b*c);
                    }
                    else if ( min > (b*c) )
                    {
                        min = (b*c);
                    }
                    if ( max < (b*d))
                    {
                        max = (b*d);
                    }
                    else if ( min > (b*d) )
                    {
                        min = (b*d);
                    }
                    a = min;
                    b = max;
                    std::cout << "[" << a << ", " << b << "]" << std::endl;
                }
            }
        }
        else if (str == "interval_divide")
        {
            std::cin >> c >> d;
            if (c > d)
            {
                std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;
                if ( (a==1) && (b==-1) )
                {
                    std::cout << "--" << std::endl;
                }
                else
                {
                    std::cout << "[" << a << ", " << b << "]" << std::endl;
                }
            }
            else
            {
                if ( (c * d) <= 0)
                {
                    std::cout << "Error: division by zero" << std::endl << "--" << std::endl;
                    a=1;
                    b=-1;
                }
                else if ( (a==1) && (b==-1) )
                {
                    std::cout << "--" << std::endl;
                }
                else
                {
                    double max{0}, min{0};

                    if ( (a/c) > (a/d) )
                    {
                        max = (a/c);
                        min = (a/d);
                    }
                    else
                    {
                        max = (a/d);
                        min = (a/c);
                    }
                    if ( max < (b/c) )
                    {
                        max = (b/c);
                    }
                    else if ( min > (b/c) )
                    {
                        min = (b/c);
                    }
                    if ( max < (b/d))
                    {
                        max = (b/d);
                    }
                    else if ( min > (b/d) )
                    {
                        min = (b/d);
                    }
                    a = min;
                    b = max;
                    std::cout << "[" << a << ", " << b << "]" << std::endl;
                }
            }
        }
        else if (str == "intersect")
        {
            std::cin >> c >> d;
            if (c > d)
            {
                std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;
                if ( (a==1) && (b==-1) )
                {
                    std::cout << "--" << std::endl;
                }
                else
                {
                    std::cout << "[" << a << ", " << b << "]" << std::endl;
                }
            }
            else if ( (a==1) && (b==-1) )
            {
                std::cout << "--" << std::endl;
            }
            else
            {
                if ( (b < c) || (d < a) ) // not intersect
                {
                    std::cout << "--" << std::endl;
                    a=1;
                    b=-1;
                }
                else // intersect
                {
                    if ((a < c) && (c < b) && (b < d))
                    {
                        a = c;
                    }
                    else if ((c < a) && (a < d) && (d < b))
                    {
                        b = d;
                    }
                    else if ((c < a) && (b < d))
                    {
                        //do nothing
                    }
                    else if ((a < c) && (d < b))
                    {
                        a = c;
                        b = d;
                    }
                    std::cout << "[" << a << ", " << b << "]" << std::endl;
                }
            }
        }
        else if (str == "integers")
        {
            if ( (a==1) && (b==-1) )
            {
                std::cout << "--" << std::endl;
            }
            else
            {
                std::cout << ceil(a);
                for (double i{ceil(a) + 1}; i <= floor(b); i++)
                {
                    std::cout << ", " << i;
                }
                std::cout << std::endl;
                std::cout << "[" << a << ", " << b << "]" << std::endl;
            }
        }
        else if (str == "cartesian_integers")
        {
            std::cin >> c >> d;
            if (c > d)
            {
                std::cout << "Error: invalid interval as " << c << " > " << d << std::endl;
                if ( (a==1) && (b==-1) )
                {
                    std::cout << "--" << std::endl;
                }
                else
                {
                    std::cout << "[" << a << ", " << b << "]" << std::endl;
                }
            }
            else
            {
                if ( (a==1) && (b==-1) )
                {
                    std::cout << "--" << std::endl;
                }
                else
                {
                    if ( (ceil(a)>floor(b)) || (ceil(c)>floor(d)))
                    {
                        //do nothing
                    }
                    else
                    {
                        std::cout << "(" << ceil(a) << "," << ceil(c) << ")";
                        for (double i{ceil(a)}; i <= floor(b); i++)
                        {
                            for (double j{ceil(c)}; j <= floor(d); j++)
                            {
                                if ( (i==ceil(a)) && (j==ceil(c)) )
                                {
                                    //do nothing
                                }
                                else
                                {
                                    std::cout << ", " << "(" << i << "," << j << ")";
                                }
                            }
                        }
                        std::cout << std::endl;
                    }
                    std::cout << "[" << a << ", " << b << "]" << std::endl;
                }

            }
        }
        else if (str == "exit")
        {
            std::cout << "Bye bye: Terminating interval calculator program." << std::endl;
            break;
        }
        else
        {
            std::cout << "Error: illegal command" << std::endl;
        }
    }
}

int main()
{
    interval_calculator();
    return 0;
}
