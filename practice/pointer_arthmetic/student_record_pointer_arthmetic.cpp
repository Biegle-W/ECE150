#include <iostream>

struct student_record_t
{
    unsigned int id;
    double cgpa;
};

int main()
{
    student_record_t *p_bart{new student_record_t {1234, 99.80}};
    std::cout << p_bart << std::endl;
    
    std::cout << p_bart-> id << std::endl;
    unsigned int *p_id{&p_bart->id};
    std::cout << p_id <<std::endl;
    
    std::cout << p_bart-> cgpa << std::endl;
    double *p_cgpa{&p_bart->cgpa};
    std::cout << p_cgpa << std::endl; 
    
    
    
    return 0;
}

