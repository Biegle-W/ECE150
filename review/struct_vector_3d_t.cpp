#include <iostream>
#include <cmath>

// vector library

// Structure declaration
struct vector_3d_t;

// Structure definition
struct vector_3d_t
{
    double x;
    double y;
    double z;
};

// Function declarations
// Declarations for Boolean-valued functions
bool is_unit( vector_3d_t const &v );
bool is_zero( vector_3d_t const &v );

// Declarations for scalar-valued functions
double          norm( vector_3d_t const &v );
double        norm_1( vector_3d_t const &v );
double      norm_inf( vector_3d_t const &v );
double dot_product( vector_3d_t const &u, vector_3d_t const &v );

// Declarations for vector-valued functions
vector_3d_t      vector_add( vector_3d_t const &u, vector_3d_t const &v );
vector_3d_t scalar_multiply( vector_3d_t const &v, double const s );
vector_3d_t   cross_product( vector_3d_t const &u, vector_3d_t const &v );

// Declarations for functions manipulating vectors
void          normalize( vector_3d_t &v );
void      vector_add_to( vector_3d_t &v, vector_3d_t const &u );
void scalar_multiply_by( vector_3d_t &v, double const s );
void       project_onto( vector_3d_t &v, vector_3d_t const &u );

//others
vector_3d_t   project( vector_3d_t u, vector_3d_t v );
double        distance( vector_3d_t u, vector_3d_t v );
void          print_vector( vector_3d_t v );
void          print_normalized( vector_3d_t v );

// Function definitions
bool is_unit( vector_3d_t const &v )
{
    return ( norm( v ) == 1.0 );
}

bool is_zero( vector_3d_t const &v )
{
    return (v.x == 0.0) && (v.y == 0.0) && (v.z == 0.0);
}

double norm( vector_3d_t v )
{
    return std::sqrt( dot_product( v, v ) );
}

double norm_1( vector_3d_t const &v )
{
    return std::abs( v.x ) + std::abs( v.y ) + std::abs( v.z );
}

double norm_inf( vector_3d_t const &v )
{
    double result{std::abs( v.x )};
    result = std::max( result, std::abs( v.y ) );
    return std::max( result, std::abs( v.z ) );
}

double dot_product( vector_3d_t u, vector_3d_t v )
{
    return u.x*v.x + u.y*v.y + u.z*v.z;
}

vector_3d_t vector_add( vector_3d_t u, vector_3d_t v )
{
    vector_3d_t result;
    result.x = u.x + v.x;
    result.y = u.y + v.y;
    result.z = u.z + v.z;
    return result;
}

vector_3d_t scalar_multiply( vector_3d_t v, double a )
{
    vector_3d_t result;
    result.x = a*v.x;
    result.y = a*v.y;
    result.z = a*v.z;
    return result;
}

vector_3d_t cross_product( vector_3d_t u, vector_3d_t v )
{
    vector_3d_t result;

    result.x = u.y*v.z - u.z*v.y;
    result.y = u.z*v.x - u.x*v.z;
    result.z = u.x*v.y - u.y*v.x;

    return result;
}

void noramlize( vector_3d_t &v )
{
    double norm_v{norm( v )};

    if ( norm_v != 0.0 )
    {
        v.x /= norm_v;
        v.y /= norm_v;
        v.z /= norm_v;
    }
}

void add_vector_to( vector_3d_t &v, vector_3d_t const &u )
{
    v.x += u.x;
    v.y += u.y;
    v.z += u.z;
}

void scalar_multiply_by( vector_3d_t &v, double a )
{
    v.x *= a;
    v.y *= a;
    v.z *= a;
}

void project_onto( vector_3d_t &v, vector_3d_t const &u )
{
    double s{dot_product( u, v )/dot_product( u, u )};
    v.x = s*u.x;
    v.y = s*u.y;
    v.z = s*u.z;
}

// others
double distance( vector_3d_t u, vector_3d_t v )
{
    vector_3d_t difference;

    difference.x = u.x - v.x;
    difference.y = u.y - v.y;
    difference.z = u.z - v.z;

    return norm( difference );
}

vector_3d_t project( vector_3d_t u, vector_3d_t v )
{
    double denom{dot_product( v, v )};

    if ( denom == 0.0 ) // If 'v' is the zero vector, return the zero vector
    {
        return v;
    }
    else
    {
        double scalar{dot_product( v, u )/denom};
        return scalar_multiply( v, scalar );
    }
}

void print_vector( vector_3d_t v )
{
    std::cout << "(" << v.x << "," << v.y << "," << v.z << ")" << std::endl;
}

void print_normalized( vector_3d_t v )
{
    double norm_v{norm( v )};

    if ( norm_v != 0.0 )
    {
        v.x /= norm_v;
        v.y /= norm_v;
        v.z /= norm_v;
    }

    print_vector( v );
}

// main function
int main();
int main()
{
    vector_3d_t p1{3.275, 2.983, -0.235}, p2, p3;

    p2.x = -5.235;
    p2.y =  4.523;
    p2.z =  3.543;

    p3 = cross_product( p1, p2 );
    print_vector( p3 );
    std::cout << dot_product( p1, p3 ) << std::endl;
    std::cout << dot_product( p2, p3 ) << std::endl;
    return 0;
}
