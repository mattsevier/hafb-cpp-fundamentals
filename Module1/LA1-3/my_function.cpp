#include "my_function.h"
#include <iostream>
using namespace std;

//Function definition
int Sum(int num1, int num2) //pass both parameters by value (make your own copy)
{
  return num1 + num2;
}

/**
 * @brief increments the value of step by 1
 * 
 */

void UpdateStep(int& step)// take the address of the parameter
{
    cout << "Current step: " << step << endl;
    //step++;
    //step = step +=1;
    step += 1;
    cout << "New step: " << step << endl;
}