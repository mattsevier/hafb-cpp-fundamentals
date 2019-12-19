#include <iostream>
#include "distance.h"
using namespace std;

// Main Function
int main() 
{
  Distance d1(10,6);
  // d1.ShowDist();

  Distance d2(1,6);
  
  //Distance d3;
  // d2.ShowDist();

  // d3 = d1 + d2;
  // d3.ShowDist();

  // Distance d4;
  // d4 = d1 + d2 + d3;
  // d4.ShowDist();

  // std::cout << d4 << std::endl;

  // Distance d5;
  // d5 = d1 - d2;
  // d5.ShowDist();

  // if(d1 < d2)
  // {
  //   std::cout << "They are the same distance" << std::endl;
  // }

  d2=d1;//assignment operation invoked
  std ::cout << d2 << " and " << d1 << std::endl;
  //initialization is not assignment, they are not the same thing
  Distance d3 = d2;//assignment operator not invoked
  std ::cout << d3 << " and " << d2 << std::endl;

    Distance d4(d2);//assignment operator not invoked
  std ::cout << d4 << " and " << d2 << std::endl;

  return 0;
}