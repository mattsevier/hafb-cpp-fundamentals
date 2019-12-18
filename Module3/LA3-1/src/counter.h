# pragma once

class Counter
{
private:
unsigned int count_;

public:
Counter() : count_(0) {}
Counter(undigned int count) : count_(count){}
~Counter() {}
//setter and getter
unsigned int count() {return count_;}
void set_cont(unsigned int count){count_=count;}

//operator overloads
//void operator ++(){++count_;}
Counter operator ++(); //only for the prefix

};