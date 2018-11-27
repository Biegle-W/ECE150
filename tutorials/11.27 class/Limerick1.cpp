// This example code is an exercise in the mechanics of C++ classes.
// It demonstrates the use of multiple constructors, a destructor, and
// use of the implicit parameter (this).

#include <iostream>

class Limerick {
public :
    Limerick ();
    Limerick (std::string init_string);
    ~Limerick ();
    void output ();
    void set_line (std::string const & set_line);
    void copy_line (Limerick const & copy_limerick);
private :
    std::string line;
};

Limerick::Limerick()
{
    std::cout << "There was an odd fellow named Gus," << std::endl;

    // use of implicit parameter. equivalent to this->line
    line = "When travelling he made such a fuss.";
}

Limerick::Limerick(std::string init_string)
{
    // use of implicit parameter. equivalent to this->line
    line = init_string;
}

Limerick::~Limerick()
{
    // use of implicit parameter. equivalent to this->line
    std::cout << line << std::endl;
}

void Limerick::output ()
{
    // use of implicit parameter. equivalent to this->line
    std::cout << line << std::endl;
}

void Limerick::set_line (std::string const & set_line)
{
    // use of implicit parameter. equivalent to this->line
    line = set_line;
}

void Limerick::copy_line (Limerick const & copy_limerick)
{
    // can access the private member variable because copy_limerick
    // is of the same class that we are currently within
    line = copy_limerick.line;
}

int main();
int main()
{
    Limerick first_limerick{};
    Limerick * p_second_limerick{new Limerick{"He was banned from the train,"}};

    first_limerick.output();
    p_second_limerick->output();
    p_second_limerick->set_line("And now travels only by bus.");
    first_limerick.copy_line(*p_second_limerick);
    p_second_limerick->set_line("Not allowed on a plane,");

    delete p_second_limerick;
    p_second_limerick = nullptr;

    return 0;
}
