/**
 * @file case.cpp
 * @author your name (you@domain.com)
 * @brief Multiple if-statement and case
 * @version 0.1
 * @date 2019-12-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <iostream>
using namespace std;

int main()
{
    char code;
    cout <<"Enter the specification code ";
    cin >> code;

    //if(code == 'S') //character uses single tick 
    //equal is 2 equal signs, one equal sign is assignment
    // {
    //     cout << "The item is space exploration grade" << endl;
    // }

    //Use a switch statement (good for more than 3 items)
    switch (code) //use with int, char, long, short, any integer type 
    {
        case 'S': //Like an IF statement
        case 's': //by repeating it's like an OR case (||)
        cout << "The item is space exploration grade" << endl;
        break; //Exit you switch statement

          case 'M': //Like an IF statement
        cout << "The item is military grade" << endl;
        break; //Exit you switch statement

          case 'C': //Like an IF statement
        cout << "The item is commercial grade" << endl;
        break; //Exit you switch statement

        default: //Like an ELSE statement
        cout << "The item is not supported" << endl;
        break;
    }
    return 0;
}