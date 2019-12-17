#include <iostream>
#include "my_function.h"
using namespace std;




// Main Function
int main()
{
  int number1 = 5, number2 = 10;
  cout << "The sum of " <<number1 << " and " 
  << number2 << " is " << Sum(number1, number2) << endl;
  
  cout << "Number before step update: " << number1 << endl;
  UpdateStep(number1);
  UpdateStep(number1);
  UpdateStep(number1);
  cout << "Number after step update: " << number1 << endl;
  return 0;

  
}


