#include "factor.h"
#include <iostream>
using namespace std;

/**
 * @brief Calculate the number of instances divisible by 3 in the range 1 through 30
 * 
 */

void FactorMod3()
{
    unsigned int count = 0;
    for(unsigned int x = 1; x <= 30; ++x)
    {
        if (x % 3 == 0)
        {
            count++;
        }
    }
        cout << "Result is: " << count << endl;
    
} 
/**
 * @brief Calculate the number of instances divisible by input parameter
 * 
 * @param mod_number The divisible number
 */
void FactorModX(int mod_number)
{
    //Anything in this function already knows about mod_number
     unsigned int count = 0;
    for(unsigned int x = 1; x <= 30; ++x)
    {
        if (x % mod_number == 0)
        {
            count++;
        }
    }
        cout << "Result is: " << count << endl;
}

/**
 * @brief Calculate the number of instances of divisible by in a specified range
 * 
 */

void FactorModXRange(int mod_number, int max_range)

{
    //Anything in this function already knows about mod_number and max_range
     unsigned int count = 0;
    for(unsigned int x = 1; x <= max_range; ++x)
    {
        if (x % mod_number == 0)
        {
            count++;
        }
    }
        cout << "Result is: " << count << endl;
}