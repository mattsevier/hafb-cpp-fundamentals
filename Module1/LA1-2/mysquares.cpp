/**
 * @file mysquares.cpp
 * @author your name (you@domain.com)
 * @brief Print multiple numbers square
 * @version 0.1
 * @date 2019-12-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <iostream>
#include <cmath> // for sqrt() function
#include <iomanip> // for formatting output
using namespace std;

const int kMaxCount = 5;

int main()
{
    cout << "number    square root" << endl;
    cout << "------    -----------" << endl;
    cout << setiosflags(ios::showpoint);
    for(int count=1; count < kMaxCount; ++count)
    {
        cout << setw(4) << count << setw(15) << sqrt(count) << endl; //setw is set width
    }
    // cout << 81 << "      " << sqrt(81) << endl;
    cout << "Done" << endl;
    return 0;
}