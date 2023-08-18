//
//  main.cpp
//  hw4q3
//
//  Created by Max Grove on 7/30/23.
//
/*
 Reads an positive integer input from user and outputs the base 2 representation.
            
 */

#include <iostream>

using namespace std;

int main() {
    int input;
    int comparison = 1, counter = 1;
    cout << "Enter decimal number:" << endl;
    cin >> input;
    cout << "The binary representation of " << input << " is ";
    //find the first power of 2 that is greater than n.
    //this will determine where we need to start our digit output from left to right.
    //compare 2^(counter) to n. increase counter until 2^(counter) is > n.
    while (comparison < input) {
        comparison = 2 * comparison;
        counter++;
    }
    
    //cout starting with counter - 1. continue until counter is 0
    //handle the first iteration outside of loop to prevent first number being a 0
    if (input >= comparison) {
        cout << 1;
        input -= comparison;
    }
    comparison = comparison / 2;
    counter--;

    //loop back down until counter is back to 0.
    // If input is > comparison, we know 2^(counter) would be a 1.
    while (counter > 0) {
        if (input >= comparison) {
            cout << 1;
            input -= comparison;
        }
        else
            cout << 0;
        //cut comparison down a power of 2 and counter down 1.
        comparison = comparison / 2;
        counter--;
    }
    cout << endl;
    return 0;
}
