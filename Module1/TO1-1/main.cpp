#include <iostream>
//#include "factor.h"
using namespace std;

// Function Prototype
void FactorMod3();

// Main Function
int main()
{
  FactorMod3();
  return 0;
}

//Function Definition
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