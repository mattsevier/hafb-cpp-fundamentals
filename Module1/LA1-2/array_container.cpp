/**
 * @file array_container.cpp
 * @author your name (you@domain.com)
 * @brief Learn C++ container
 * @version 0.1
 * @date 2019-12-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <iostream>
#include <array> //array container
using namespace std;

int main()
{
    //to create arrays with library:
    //array<type, NumberOfElements> name;
    array<double,5> grades {52,65.2,552.2,8,12};
    // cout<<"Size of array: "<<grades.size()<<endl;
    // cout<<"array empty: "<<grades.empty()<<endl;

    for(int index = 0; index < grades.size(); ++index)
    {
        cout << grades[index] << endl;
    }

    //for each loop
    cout << "For Each: " << endl;
    for(auto grade : grades)
    {
            cout << grade << endl;
    }
    return 0;
}