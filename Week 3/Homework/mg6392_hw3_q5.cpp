//
//  main.cpp
//  hw3q5
//
//  Created by Max Grove on 7/23/23.
//  BMI calculation program
/*
 This program takes in weight in lb and height in inches, and outputs BMI.
 Method used: (weight in kg) / (height in meters)^2
 */

#include <iostream>

using namespace std;

const double LB_TO_KG = 0.453592;
const double IN_TO_METER = 0.0254;

const double BMI_UNDERWEIGHT_CEILING = 18.5;
const int BMI_NORMAL_CEILING = 25;
const int BMI_OVERWEIGHT_CEILING = 30;

int main() {
    double lbWeight, inchHeight;
    double kgWeight, meterHeight;
    double BMI;
    
    cout << "Please enter weight (in pounds): ";
    cin >> lbWeight;
    cout << "Please enter height (in inches): ";
    cin >> inchHeight;
    
    kgWeight = lbWeight * LB_TO_KG;
    meterHeight = inchHeight * IN_TO_METER;
    BMI = kgWeight / (meterHeight * meterHeight);
    
    if (BMI < BMI_UNDERWEIGHT_CEILING) {
        cout << "The weight status is: Underweight" << endl;
    }
    else if (BMI < BMI_NORMAL_CEILING) {
        cout << "The weight status is: Normal" << endl;
    }
    else if (BMI < BMI_OVERWEIGHT_CEILING) {
        cout << "The weight status is: Overweight" << endl;
    }
    else {
        cout << "The weight status is: Obese" << endl;
    }
    return 0;
}
