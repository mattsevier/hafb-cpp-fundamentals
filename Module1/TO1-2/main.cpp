#include <iostream>
#include "factor.h"
using namespace std;

int main()
{
    FactorMod3();
    FactorModX(5);
    FactorModXRange(5,500);
    unsigned int count = GetFactorModXRange(5,500);
    cout << "The count is " << count << endl;

    auto count2 = GetFactorModXRange(2,500); //don't worry about type of variable this way
    cout << "The count is " << count2 << endl;
    return 0;
}