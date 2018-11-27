#include <iostream>

#ifndef MARMOSET_TESTING
int main();
#endif

struct Student;
struct Student
{
    float grade;
    int studentID;
};

void stats(int num_students, Student students[],
           float &max_grade, int &max_studentID,
           float &min_grade, int &min_studentID);

void stats(int num_students, Student students[],
           float &max_grade, int &max_studentID,
           float &min_grade, int &min_studentID)
{
    for (int student_index{0}; student_index < num_students; student_index++)
    {
        if (students[student_index].grade > max_grade)
        {
            max_grade = students[student_index].grade;
            max_studentID = students[student_index].studentID;
        }
        if (students[student_index].grade < min_grade)
        {
            min_grade = students[student_index].grade;
            min_studentID = students[student_index].studentID;
        }
    }
}

#ifndef MARMOSET_TESING
int main()
{
    Student input_students[6]
    {
        {92.0, 1230292},
        {19, 948421},
        {54.3, 34922},
        {21, 178234},
        {94.7, 392020},
        {58.2, 746821}
    };
    
    int num_students = 6;
    float output_max_grade{0};
    int output_max_studentID{0};
    float output_min_grade{100};
    int output_min_studentID{0};
    
    stats(num_students, input_students, output_max_grade, output_max_studentID, output_min_grade, output_min_studentID);
    
    std::cout << "Max Grade: " << output_max_grade <<std::endl;
    std::cout << "student with max grade: " << output_max_studentID << std::endl;
    std::cout << "Min Grade: " << output_min_grade <<std::endl;
    std::cout << "student with min grade: " << output_min_studentID << std::endl;
    return 0;
}
#endif
