#pragma once
#include <iostream>

class Counter
{
private:
unsigned int count_;

public:
Counter() : count_(0) {}
Counter(unsigned int count) : count_(count){}
~Counter() {std::cout <<"Bye\n";}
//setter and getter
unsigned int count() {return count_;}
void set_cont(unsigned int count){count_=count;}

//operator overloads
//void operator ++(){++count_;}
Counter operator ++(); //only for the prefix, no parameter
Counter operator ++(int); //for postfix because it takes a parameter

};