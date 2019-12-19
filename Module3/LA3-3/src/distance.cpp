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