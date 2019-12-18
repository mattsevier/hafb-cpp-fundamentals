#include "counter.h"

Counter Counter::operator ++()
{
    // ++count_;
    // Counter temp;   //create dummy object
    // temp.count_ = count_;   //set the value
    // return temp;    //return the object

    return Counter(++count_);//unnamed temp object
}

Counter Counter::operator ++(int) //for postfix because it takes a parameter
{
    return Counter(count_++);
}
