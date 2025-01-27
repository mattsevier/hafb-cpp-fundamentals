// countpp3.cpp
// increment counter variable with ++ operator
// uses unnamed temporary object
#include <iostream>
using namespace std;
#include "distance.h"

/**
 * @brief show the distance in feet and inches
 * 
 */

void Distance::ShowDist() const
{
    std::cout << feet() << "\' - " << inches() << "\"" << std::endl;
}
/**
 * @brief add two distances in feet and inches using + operator
 * self + d2 object
 * 
 */
Distance Distance::operator +(Distance d2) const
{
    int feet = feet_ + d2.feet_;//remember who is calling this so d1 is already here, could 
            //have been this.feet_ for d1, but that is not optional
    float inches = inches_ + d2.inches_;
    //if inches are greater than a foot you need to increment feet
    if (inches >= 12.0)
    {
        inches -=12.0;
        feet++;
    }
    // Distance temp(feet, inches);
    // return temp;
    return Distance(feet, inches); //rewrite previous two lines
}
// Distance Distance::operator -(Distance d2) const
// {
//     int feet = feet_ - d2.feet_;
//     float inches = inches_ - d2.inches_;
//     if (inches < 0)
//     {
//         inches +=12.0;
//         feet = feet - 1;
//     }
//     return Distance(feet, inches);
// }

// Distance Distance::operator -(Distance d2) const //class solution
// {
//     int ft = feet_ - d2.feet_;
//     float in = 0;
//     if (inches_ < d2.inches)
//     {
//         ft -= 1;
//         in = (inches_ + 12) - d2.inches_;
        
//     }
//     return Distance(ft, in);
// }
    std::ostream &operator <<(std::ostream& os, const Distance& distance)//friend keyword not needed
    {
        //note: it is recommended not to include a "\n" or endl character, let the user 
        //decide if they want it, don't put it in by default
        os << "feet " <<distance.feet_ << " inches " << distance.inches_;
        return os;

    }

    void Distance::update_distance(int ft, float in)
    {
        set_feet(ft);
        set_inches(in);
    }