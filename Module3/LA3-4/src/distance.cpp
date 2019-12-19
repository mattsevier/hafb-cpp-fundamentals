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
    Distance operator -(Distance lhs, Distance rhs)
    {
    int ft = lhs.feet_ - rhs.feet_;
    float in = 0;
    if (lhs.inches_ < rhs.inches_)
    {
        ft -= 1;
        in = (lhs.inches_ + 12) - rhs.inches_;
        
    }
    return Distance(ft, in);
}


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

    bool Distance::operator < (Distance rhs) const
    {
        float ft1 = feet_ + inches_ /12.0;
        float ft2 = rhs.feet_ + rhs.inches_ /12.0;
        if (ft1<ft2)
        {
            return true;
        }
        else
        {
            return false;
        }
        
        
    }

    bool Distance::operator == (Distance rhs) const //compare object
    {
        float ft1 = feet_ + inches_ /12.0;
        float ft2 = rhs.feet_ + rhs.inches_ /12.0;
        return (ft1 == ft2) ? true : false;//form of if / else
    }

    Distance Distance::operator =(Distance& rhs)
    {
        std::cout<<"assignment operator invoked!" << std::endl;
        feet_ = rhs.feet_;
        inches_ = rhs.inches_;
        return Distance(feet_, inches_);
    }

//copy constructor
    Distance::Distance(const Distance& dist)
    {
        std::cout << "Copy constructor invoked" << std::endl;
        feet_ = dist.feet_;
        inches_ = dist.inches_;
    }