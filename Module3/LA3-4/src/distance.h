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
Distance(const Distance& dist);//copy constructor
~Distance() {}//could include std::cout <<"Bye\n"; in curly brackets
//setter and getter
int feet() const {return feet_;}
void set_feet(int feet) {feet_ = feet;}

float inches() const {return inches_;}
void set_inches(float inches) {inches_ = inches;}

Distance operator +(Distance d2) const;//only need one input since a distance 
//is calling this, it is calling it on itself.  Constant so it can't change d1 and d2 in main by accident

friend std::ostream &operator <<(std::ostream& os, const Distance& distance); //const makes it read only
//for safety but pass by reference for speed
//this is a friend that is returning the address for an output stream,  not the actual stream

//Distance operator -(Distance d2) const;
friend Distance operator -(Distance lhs, Distance rhs); //friend operator
void update_distance(int ft, float in);

//Other methods
void ShowDist() const;

bool operator < (Distance rhs) const; //compare object
bool operator == (Distance rhs) const; //compare object

Distance operator =(Distance& rhs);
};