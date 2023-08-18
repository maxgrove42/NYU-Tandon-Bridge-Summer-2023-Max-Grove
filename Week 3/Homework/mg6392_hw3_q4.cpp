//
//  main.cpp
//  hw3q4
//
//  Created by Max Grove on 7/23/23.
//  Rounding program
/*
 This program rounds a user-inputted number up, down, or to nearest whole number.
 Inputs: real number, choice of rounding method
 Output: rounded number
 Implementation: Casting. Round down = (int)input. Round up = (int)(input + 1).
    Nearest whole number -> subtract the whole number from input. if >= 0.5, round up, otherwise, round down.
    Switch method for choosing which rounding method.
 */

#include <iostream>

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

using namespace std;

int main(int argc, const char * argv[]) {
    double input;
    int roundingMethod;
    bool isPositive;
    
    cout << "Please enter a Real number: " << endl;
    cin >> input;
    cout << "Choose your rounding method." << endl;
    cout << "1. Floor round" << endl << "2. Ceiling round" << endl << "3. Round to the nearest whole number" << endl;
    cin >> roundingMethod;
    
    isPositive = (input >= 0);
    
    switch (roundingMethod) {
        case FLOOR_ROUND:
            if (isPositive) {
                cout << (int)(input) << endl;
            }
            else { //if negative
                //if a whole number, output number. otherwise round down to negative inf.
                if (input == (int)input) {
                    cout << (int)input << endl;
                }
                else {
                    cout << (int)(input - 1) << endl;
                }
            }
            break;
        case CEILING_ROUND:
            if (isPositive) {
                if ((int)input == input) //used to account for case where input is already a whole num
                    cout << (int)input << endl;
                else
                    cout << (int)(input+1) << endl;
            }
            else { //if negative
                cout << (int)(input) << endl;
            }

            break;
        case ROUND:
            if (isPositive) {
                //if input - (int)input (i.e. the decimal portion of input) >= 0.5, round up, otherwise round down.
                if ((input - (int)input) >= 0.5)
                    cout << (int)(input + 1) << endl;
                else
                    cout << (int)input << endl;
            }
            else {
                if ((input - (int)input) <= -0.5)
                    cout << (int)(input - 1) << endl;
                else
                    cout << (int)input << endl;
            }
            break;
        default:
            cout << "Invalid rounding method entered. Please try again." << endl;
            break;
    }
    
    return 0;
}
