/**
 * @file my_array.cpp
 * @author your name (you@domain.com)
 * @brief Learn about C style arrays
 * @version 0.1
 * @date 2019-12-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <iostream>
using namespace std;

const int kMaxNum = 5;

int main()
{
    // C-style (still supported but not the best way)
    // Array notation: type name[elements];
    // to access elements use index notation which begins at 0
    //int grades[kMaxNum] = {10, 20, 30, 50, 20}; //an array of 5 integers,
    //int grades[kMaxNum] = {10, 20, 30}; //an array of 5 integers, where the last 2 are zero
    // int grades[] = {10, 20, 30, 50, 20}; //an array of 5 integers, let the compiler set size
    // float ExamAve = 0; //Be careful about truncation if only using integers, needs to be float
    // cout << "Enter you exam grades" << endl;
    // for (int num = 0; num < kMaxNum; ++num)
    // {
    //     // cout << "Enter exam " << num +1 << " grade: " << endl;
    //     // cin >> grades [num]; //access each element using []
    //     ExamAve += grades[num]; //to calculate the average you need the total, this adds them up

    // }
    // ExamAve = ExamAve/kMaxNum; //at least one float, see cast if only using integers
    // cout << "Your average is " << ExamAve << endl;
    
    // 2D array: type name[1D][2D]; [row][column]
    int bi_array[3][4] = {
        {2, 4, 6, 11, 67},
        {4, 5, 8, 15, 99},
        {8, 6, 45, 84, 25},
    };//3 rows by 4 columns
    // To print the elements of the 2D array

    for (int row = 0; row < 3 ; ++row)
    {
        for (int column = 0; column < 5; ++column)
         {
    cout << "Array element at [" << row << "]" <<
    "[" <<column << "]" << bi_array[row][column] << endl;

        }
    }
    return 0;
}