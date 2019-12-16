#include <iostream>
using namespace std;

int main()
{
    int age;  // int: signed integers
    // cout is for system output
    std::cout << "Hello World" << std::endl;
    cout << "Second Line" << endl;
    cout << "Wildcats "<<"WSU "<<"Ogden"<<endl;
    // cin is for system/user input
    cout << "What is your age?" <<endl;
    cin >> age;
    cout << "I see you are: " << age <<endl;
    // get the size of the variable using sizeof()
    cout << "Integers are: " <<sizeof(int) << " bytes." << endl;
    cout << "Min Integer value " << INT32_MIN << "Max Integer value " <<INT32_MAX << "bytes" << endl;
    return 0;
    }

