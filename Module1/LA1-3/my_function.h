#pragma once
#include <array> 
using namespace std;

//prototype
int Sum(int num1, int num2);

void UpdateStep(int& step);//Pass by reference (address in memory)

void ClearElements(std::array<int,10> &nums);