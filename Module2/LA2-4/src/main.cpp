#include <iostream>
#include "carton.h"
#include <array>
#include "carton_fileio.h"



//using namespace std;
//const int kMaxSize = 10;

int main() {
  
  Carton box;
  // std::cout << "Box height " << box.height() << std::endl;
  // std::cout << "Box width " << box.width() << std::endl;
  // std::cout << "Box length " << box.length() << std::endl;

  box.ShowInfo(); //display object info

  
  box.set_width(12.5);
  box.set_length(10.9);
  box.set_height(23);

box.ShowInfo(); //display object info
  
  // create a Carton object using the default constructor
  Carton box2(34,89,11);
  box2.ShowInfo();

  Carton box3(5,6,2); //example of negative number to throw an exception
  box3.ShowInfo();

  // create a Carton object using the other constructor
  // create an array of Cartons
  std::array < Carton, kMaxArraySize> boxes;
  

  

  // add some valid elements to the array

  boxes[0]=Carton(12,21,52);

  //read data from a file
  std::string message;
  int record_size = 0;
  message = ReadDataFormatFromFile("../carton_data.txt", boxes, record_size);
  std::cout << message << std::endl;

  // loop through the array
  for(auto box : boxes)
  {
    box.ShowInfo();
  }


//something isn't working but had to move on

  // print out the volume of packages

  // print out the girth of packages

  // print out the length plus girth of packages

  // check if package is sized to ship

  // define a package that is too big to ship

  // define a package that is too small to ship

  // print if sized to ship

  // write carton data and information

  // read data from file

  // write data to file

  return 0;
}