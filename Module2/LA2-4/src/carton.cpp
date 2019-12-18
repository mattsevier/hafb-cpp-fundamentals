
#include <iostream>
#include "carton.h"
#include <string>

    //const double Carton::kMaxSize = 100;//do not use static keyword
    const double Carton::kMinLength = 6;
    const double Carton::kMinWidth = 3;
    const double Carton::kMinHeight = 0.25;

//Constructors have access to private data members
//Default constructor
Carton::Carton()
{
    height_ = 0;
    width_ = 0;
    length_ = 0;
}
//second constructor
Carton::Carton(double length, double width, double height)
{
    // height_=height;
    // width_=width;
    // length_=length;

    try{
    SetMeasurements(length, width, height);
    }
    catch (std::out_of_range e)
    {
        std::cerr << e.what() << '\n';
    }
}

Carton::~Carton()
{

}

void Carton::SetMeasurements(double length, double width, double height)
{
    if (length <= 0 || width <= 0 || height <=0)
    {
        throw std::out_of_range ("All measurements must be positive");
    }
    //Good to go
    height_=height;
    width_=width;
    length_=length;
}

 double Carton::length()
 {
     return length_;
 }
     
double Carton::width()
{
return width_;
}

double Carton::height()
{
    return height_;
}

void Carton::set_length(double length)
{
    if(length < kMinLength)
    {
        std::string error_msg = "Length must be greater than " + std::to_string(kMinLength);// to cast
        //so they can be cacatonated
        throw std::out_of_range(error_msg);
    }
    length_ = length;
}
void Carton::set_width(double width)
{
   width_ = width;
}
void Carton::set_height(double height)
{
    height_ = height;
}

void Carton::ShowInfo()
{
    std::cout << "Box height " << height() << std::endl;
  std::cout << "Box width " << width() << std::endl;
  std::cout << "Box length " << length() << std::endl;
  std::cout << "Box Volume " << Volume() << std::endl;
}

double Carton::Volume() const{
    return length_*width_*height_;
}