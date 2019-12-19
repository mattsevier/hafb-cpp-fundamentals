#pragma once
#include <iostream>

class Distance
{
private:
int feet_;
float inches_;

public:
Distance() : feet_(0), inches_(0) {}
Distance(int feet, float inches) : feet_(feet), inches_(inches) {}
~Distance() {std::cout <<"Bye\n";}
//setter and getter
int feet() const {return feet_;}
void set_feet(int feet) {feet_ = feet;}

float inches() const {return inches_;}
void set_inches(float inches) {inches_ = inches;}

Distance operator +(Distance d2) const;//only need one input since a distance 
//is calling this, it is calling it on itself.  Constant so it can't change d1 and d2 in main by accident


//Other methods
void ShowDist() const;

};