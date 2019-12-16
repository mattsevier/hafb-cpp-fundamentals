/**
 * @file multitables.cpp
 * @author your name (you@domain.com)
 * @brief display multiplication tables based on user input
 * @version 0.1
 * @date 2019-12-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <iostream>
#include <iomanip>
using namespace std;

const int kMax = 10;

int main()
{
    int number;
    cout << "Enter a value to print multiplication tables: " << endl;//This is how many rows
    cin >> number;
    for(int num1 = 1; num1<= number; ++num1) //rows
    {
        for (int count=1;count <=kMax; ++count) //columns
        {
            cout << setw(3) << num1*count << " ";
        }
        cout << endl;
    }
    return 0;
}


