#include <iostream>
#include "Polynomial.h"

/*struct poly_t
{
    double *a_coeffs;      // array of coefficients
    unsigned int degree;   // the degree of the polynomial
};*/

//Polynomial initialization
void init_poly( poly_t &p, double const init_coeffs[], unsigned int const init_degree )
{
    if (p.a_coeffs != nullptr)
    {
        delete [] p.a_coeffs;
        p.a_coeffs = nullptr;
    }
    p.degree = 0;
    
    p.a_coeffs = new double[init_degree+1];
    
    for (std::size_t i{0}; i < (init_degree + 1); i++ )
    {
        p.a_coeffs[i] = init_coeffs[i];
    }
    p.degree = init_degree;
    
}

//Polynomial destructor
void destroy_poly( poly_t &p )
{
    delete [] p.a_coeffs;
    p.a_coeffs = nullptr;
}

 //Polynomial degree
unsigned int poly_degree( poly_t const &p )
{
    if (p.a_coeffs == nullptr)
    {
        throw 0;
    }
    else
    {
        return p.degree;
    }
}

//Polynomial coefficient
double poly_coeff( poly_t const &p, unsigned int n )
{
    if (p.a_coeffs == nullptr)
    {
        throw 0;
    }
    else
    {
        return p.a_coeffs[n];
    }
}

//Polynomial evaluation
double poly_val( poly_t const &p, double const x )
{
    if (p.a_coeffs == nullptr)
    {
        throw 0;
    }
    else
    {
        double result{0};
        
        for (std::size_t i{p.degree+1}; i > 0; i--)
        {
            if (i == (p.degree+1))
            {
                result = x * p.a_coeffs[i] + p.a_coeffs[i-1];
            }
            else
            {
                result = result * x + p.a_coeffs[i-1];
            }
        }
        
        return result;
    }
}

//Polynomial addition
void poly_add( poly_t &p, poly_t const &q )
{
    if (p.a_coeffs == nullptr || q.a_coeffs == nullptr) // if any of the coefficient array is not initialized, throw 0
    {
        throw 0;
    }
    else
    {
        unsigned int new_degree{0}, small_degree{0};
        
        if (p.degree == q.degree) // if both polys have the same degree
        {
            new_degree = q.degree; // old degree, new degree, and small degree are the same
            small_degree = new_degree;
            for (std::size_t i{q.degree}; i >= 0 ; i--) // start from the highest degree to the 0
            {
                if (p.a_coeffs[i] + q.a_coeffs[i] == 0) // check if the sum of coeffs is zero
                {
                    new_degree--; // if the sum is zero, then the degree -1
                    small_degree = new_degree; // the small degree also -1
                }
                else
                {
                    break; // if the sum is not 0, then break
                }
            }
        }
        else
        {
            if (p.degree > q.degree)
            {
                new_degree = p.degree;
                small_degree = q.degree;
            }
            else
            {
                new_degree = q.degree;
                small_degree = p.degree;
            }
        }
        
        if (new_degree == 0)
        {
            if (p.a_coeffs[0] + q.a_coeffs[0] == 0 )
            {
                delete [] p.a_coeffs;
                p.a_coeffs = nullptr;
                p.degree = 0;
            }
            else
            {
                p.a_coeffs[0] = p.a_coeffs[0] + q.a_coeffs[0];
                p.degree = 0;
            }
        }
        else
        {
            double *a_new_coeffs{new double[new_degree+1]};
            
            for (std::size_t i{0}; i < new_degree+1; i++) // copy the coeffs to the new array, strat from the 0 to the hightest degree
            {
                if (i <= small_degree ) // if the current degree is smaller than or equal to the small degree
                {
                    a_new_coeffs[i] = p.a_coeffs[i] + q.a_coeffs[i]; // the new coeff is the sum of the two
                }
                else // if the current degree is bigger than small degree, to prevent access wrong memoery
                {
                    if (p.degree > q.degree) // the new coeff is only the one with higher degree
                    {
                        a_new_coeffs[i] = p.a_coeffs[i];
                    }
                    else
                    {
                        a_new_coeffs[i] = q.a_coeffs[i];
                    }
                }
            }
            
            delete [] p.a_coeffs;
            p.a_coeffs = a_new_coeffs;
            p.degree = new_degree;
        }
    }
}

//Polynomial subtraction
void poly_subtract( poly_t &p, poly_t const &q )
{
    if (p.a_coeffs == nullptr || q.a_coeffs == nullptr)
    {
        throw 0;
    }
    else
    {
        unsigned int new_degree{0}, small_degree{0};
        
        if (p.degree == q.degree)
        {
            new_degree = q.degree;
            small_degree = new_degree;
            for (std::size_t i{q.degree}; i >= 0 ; i--)
            {
                if (p.a_coeffs[i] - q.a_coeffs[i] == 0)
                {
                    new_degree--;
                    small_degree--;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            if (p.degree > q.degree)
            {
                new_degree = p.degree;
                small_degree = q.degree;
            }
            else
            {
                new_degree = q.degree;
                small_degree = p.degree;
            }
        }
        
        if (new_degree == 0)
        {
            if (p.a_coeffs[0] - q.a_coeffs[0] == 0 )
            {
                delete [] p.a_coeffs;
                p.a_coeffs = nullptr;
                p.degree = 0;
            }
            else
            {
                p.a_coeffs[0] = p.a_coeffs[0] - q.a_coeffs[0];
                p.degree = 0;
            }
        }
        else
        {
            double *a_new_coeffs{new double[new_degree+1]};
            
            for (std::size_t i{0}; i < new_degree+1; i++)
            {
                if (i <= small_degree )
                {
                    a_new_coeffs[i] = p.a_coeffs[i] - q.a_coeffs[i];
                }
                else
                {
                    if (p.degree > q.degree)
                    {
                        a_new_coeffs[i] = p.a_coeffs[i];
                    }
                    else
                    {
                        a_new_coeffs[i] = - q.a_coeffs[i];
                    }
                }
            }
            
            delete [] p.a_coeffs;
            p.a_coeffs = a_new_coeffs;
            p.degree = new_degree;
        }
    }
}

//Polynomial multiplication
void poly_multiply( poly_t &p, poly_t const &q )
{
    if (p.a_coeffs == nullptr || q.a_coeffs == nullptr)
    {
        throw 0;
    }
    else
    {
        if (p.degree == 0 || q.degree == 0)
        {
            if (p.a_coeffs[0] == 0 || q.a_coeffs[0] == 0 )
            {
                p.degree = 0;
                delete [] p.a_coeffs;
                p.a_coeffs = nullptr;
            }
            else
            {
                if (p.degree == 0 && q.degree != 0)
                {
                    double constant{p.a_coeffs[0]};
                    for (std::size_t i{0}; i < q.degree + 1; i++)
                    {
                        p.a_coeffs[i] = constant * q.a_coeffs[i];
                    }
                    p.degree = q.degree;
                }
                else if (q.degree == 0 && p.degree != 0)
                {
                    double constant{q.a_coeffs[0]};
                    for (std::size_t i{0}; i < p.degree + 1; i++)
                    {
                        p.a_coeffs[i] = constant * p.a_coeffs[i];
                    }
                }
                else if (p.degree == 0 && q.degree == 0)
                {
                    p.a_coeffs[0] = p.a_coeffs[0] * q.a_coeffs[0];
                }
            }
        }
        else
        {
            unsigned int new_degree{0};
            new_degree = p.degree + q.degree;
            
            double *a_new_coeffs{new double[new_degree+1]{}};
            
            for (int i{0}; i < new_degree + 1; i++)
            {
                a_new_coeffs[i] = 0;
            }
            
            // Multiply two polynomials term by term
            for (int i{0}; i < p.degree + 1; i++) // Take ever ith coeffs of first polynomial
            {
                for (int j{0}; j < q.degree + 1; j++) // Multiply ith coeffs of first polynomial with jth coeffs of the second polynomial.
                    a_new_coeffs[i+j] += p.a_coeffs[i] * q.a_coeffs[j];
            }
            
            delete [] p.a_coeffs;
            p.a_coeffs = a_new_coeffs;
            p.degree = new_degree;
        }
    }

}


//Polynomial division
double poly_divide( poly_t &p, double r )
{
    if (p.a_coeffs == nullptr)
    {
        throw 0;
    }
    else if (p.degree == 0)
    {
        double remainder{*p.a_coeffs};
        p.a_coeffs[0] = 0;
        
        return remainder;
    }
    else if (r == 0)
    {
        unsigned int new_degree = p.degree -1;
        double *a_new_coeffs {new double[new_degree+1]{}};
        double remainder{*p.a_coeffs};
        
        for (std::size_t i{0}; i < new_degree+1; i++)
        {
            a_new_coeffs[i] = p.a_coeffs[i+1];
        }
        
        delete [] p.a_coeffs;
        p.a_coeffs = a_new_coeffs;
        p.degree = new_degree;
        
        return remainder;
    }
    else
    {
        double remainder{0};
        unsigned int new_degree{p.degree-1};
        double *a_new_coeffs{new double [new_degree+1]};
        
        a_new_coeffs[new_degree] = p.a_coeffs[p.degree]; // the coeff of the highest degree doesn't change
        
        for (std::size_t i{new_degree}; i > 0; i--) // long division, start from the second highest degree, move to the lowest degree
        {
            a_new_coeffs[i-1] = r * a_new_coeffs[i] + p.a_coeffs[i];
        }
        
        remainder = p.a_coeffs[0] + r * a_new_coeffs[0];
        delete [] p.a_coeffs;
        p.a_coeffs = a_new_coeffs;
        p.degree = new_degree;
        
        return remainder;
    }
}

//Polynomial differentiation
void poly_diff( poly_t &p )
{
    if (p.a_coeffs == nullptr)
    {
        throw 0;
    }
    else if (p.degree == 0)
    {
        p.a_coeffs[0] = 0;
    }
    else
    {
        double *a_new_coeffs{new double[p.degree]{0}};
        
        for (std::size_t i{p.degree}; i > 0; i--)
        {
            a_new_coeffs[i-1] = i * p.a_coeffs[i];
        }
        
        p.degree --;
        delete [] p.a_coeffs;
        p.a_coeffs = a_new_coeffs;
    }
    
}

//Polynomial integral approximation
double poly_approx_int( poly_t const &p, double a, double b, unsigned int n )
{
    if (p.a_coeffs == nullptr)
    {
        throw 0;
    }
    else
    {
        double h{(b-a)/n};
        double x[n+1], y[n+1];
        double result{0};
        
        x[0] = a;
        for (std::size_t i{1}; i < n+1; i++)
        {
            x[i] = x[i-1] + h;
        }
        
        for (std::size_t i{0}; i < n+1; i++)
        {
            y[i] = poly_val(p, x[i]);
        }
        
        for (std::size_t i{1}; i < n; i++)
        {
            result += 2 * y[i];
        }
        
        result += y[0] +y[n];
        result *= h/2; 
        
        return result;
    }
}




#ifndef MARMOSET_TESTING
int main();
#endif

#ifndef MARMOSET_TESTING

int main()
{
    poly_t poly_a{nullptr, 0};
    double elem1[5] = {7, 6, 5, 4, 3};
    init_poly(poly_a, elem1, 4);
    
    std::cout << poly_approx_int(poly_a, 0, 10, 10) << std::endl;
    
}

#endif

