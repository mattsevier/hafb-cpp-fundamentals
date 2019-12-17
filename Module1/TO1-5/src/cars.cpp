#include <iostream>
#include "cars.h"

int HorsePower() //nameless namespace
{
    return 150;
}

// using namespace lamborghini;

int lamborghini::HorsePower()
{
    return 760;
}

// using namespace porsche;

int porsche::HorsePower()
{
    return 700;
}
