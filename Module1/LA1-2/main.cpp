/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Global versus local variables
 * @version 0.1
 * @date 2019-12-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <iostream>
using namespace std;
int global_variable = 1000; //global variable

int main()
{
    int global_variable = 2000;
    // :: scope operator, it will look locally first, then go globally
    cout << "global" << ::global_variable << endl;
    cout << "local" << global_variable << endl;
    return 0;
}
