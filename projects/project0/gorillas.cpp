#include <iostream>
#include <cmath>
//function declarations

#ifndef MARMOSET_TESTING

int main();

#endif

double horizontal_velocity(double launch_velocity, double launch_angle);
double vertical_velocity(double launch_velocity, double launch_angle);
double gravity();
double computed_range(double launch_velocity, double launch_angle, double height);

//function definitions
double horizontal_velocity(double launch_velocity, double launch_angle)
{
    return launch_velocity * cos(launch_angle/180.0*(M_PI));
}

double vertical_velocity(double launch_velocity, double launch_angle)
{
    return launch_velocity * sin(launch_angle/180.0*(M_PI));
}

double gravity()
{
    return 9.80665;
}

double computed_range(double launch_velocity, double launch_angle, double height)
{
    double v_x= horizontal_velocity(launch_velocity, launch_angle);
    double v_y= vertical_velocity(launch_velocity, launch_angle);
    double d= v_x * v_y / gravity () + v_x * sqrt(v_y * v_y + 2 * gravity() * height) / gravity();
    return d;
}

//main function
#ifndef MARMOSET_TESTING

int main()
{
    double launch_angle [12] = {10, 20, 25.5, 30, 40, 50, 55.5, 60, 70, 75.5, 80, 90};
    for (int i=0; i<12;i++) {
        std::cout << "The range the banana reaches for the launch angle of "
        << launch_angle[i]
        << " degrees is "
        << computed_range(600, launch_angle[i], 10)
        << std::endl;
    }
    
    return 0;
}

#endif
