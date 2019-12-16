/**
 * @file Age.cpp
 * @author your name (you@domain.com)
 * @brief Print user rights based on age
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
int age;
cout << "Enter you age " ;
cin >> age;
// Display rights by age:
// under 18 must go to school
if (age<18)
{
    cout << "You should be in school" << endl;
}
// over 18 you can vote
else if(age >= 18 && age < 21)
{
    cout << "You can vote" << endl;
}
// over 21 you can buy alcohol
else if(age >= 21 && age < 65)
{
    cout << "You can buy alcohol" << endl;
}
// over 65 you can retire
else if(age >= 65)
{
    cout << "You can retire" << endl;
}

    return 0;
}