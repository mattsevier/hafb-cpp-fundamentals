#include "height.h"
#include <iostream>

// Height::Height() //replace these commands with parameters in .h file
// {
//     inches_ = 0;
// }

// Height::~Height()
// {

// }
//friend functions have access to private data members
//when writing definition do not include the friend keyword, nor the class :: scope
//Just a regular function with special access
void print_feet(Height h1)
{
    std::cout << "your height in inches is: " << 
        h1.inches_ << std::endl;
    std::cout << "your height in feet is: " << 
        h1.inches_/12 << std::endl;
}
