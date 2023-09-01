//
//  main.cpp
//  hw4q4
//
//  Created by Max Grove on 7/30/23.
//
/*
 Calculate the geometric mean of a sequence of positive integers.
 The first sectoin will ask the user for length of the sequence and then the sequence itself.
 The second section will ask the user to enter a sequence ending in -1 to determine the end of the sequence.
 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Section a" << endl;
    
    int length, product = 1;
    double geometricMean;
    
    cout << "Please enter the length of the sequence: ";
    cin >> length;
    
    cout << "Please enter your sequence: " << endl;
    for (int i = 0; i < length; i++) {
        int tempA;
        cin >> tempA;
        product *= tempA;
    }

    geometricMean = pow(product, (double)1.0/length); //including (double) for clarification
    cout << "The geometric mean is: " << geometricMean << endl;
    
    /*--------------------------------------------------------------------*/
    /*--------------------------------------------------------------------*/
    cout << endl << "Section b" << endl;
    int tempB;
    length = 0;
    product = 1;
    
    cout << " Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1:" << endl;
    cin >> tempB;
    
    while (tempB >= 0) {
        product *= tempB;
        length++;
        cin >> tempB;
    }
    
    geometricMean = pow(product, (double)1.0/length); //including (double) for clarification
    cout << "The geometric mean is: " << geometricMean << endl;
    
    return 0;
}
