#include <iostream>
using namespace std;

int main()
{
    // Calculate BMI: weight (kg) / [height (m)]^2
    // Floating point variables are either float or double
    float weight, height, BMI; // to initialize the variable float weight = 0, etc
    cout << "Enter you weight in kg" << endl; //You can delete the endl so the text is placed at the end of the input question
    cin >> weight;
    cout << "Enter you height in meters" << endl; //You can delete the endl so the text is placed at the end of the input question
    cin >> height;
    // Calculate BMI
    BMI = weight/(height*height);
    cout << "Your BMI is: " << BMI << endl;

    return 0;
}