#include <iostream>
using namespace std;

const float kMeterToInches = 39.37; //These are globally defined variables
const float kKiloToPound = 2.204; //No magic numbers, i.e. only variables in the code
const float kBMIImperial = 703;

int main()
{
    // Calculate BMI: weight (kg) / [height (m)]^2
    // Floating point variables are either float or double
    float weight, height, BMI; // to initialize the variable float weight = 0, etc
    cout << "Enter you weight in kg" << endl; //You can delete the endl so the text is placed at the end of the input question
    cin >> weight;
    cout << "Enter you height in meters" << endl; //You can delete the endl so the text is placed at the end of the input question
    cin >> height;
    //convert units from metric
    weight = weight * kKiloToPound; //convert to pounds
    height = height * kMeterToInches; //convert to inches
    // Calculate BMI
    BMI = (weight*kBMIImperial)/(height*height); //BMI calculation in standard units
    cout << "Your BMI is: " << BMI << endl;

    return 0;
}