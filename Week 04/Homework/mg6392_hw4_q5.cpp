//
//  main.cpp
//  hw4q5
//
//  Created by Max Grove on 7/30/23.
//
/*
 Write a program that asks the user to input a positive integer n,
 and prints a textual image of an hourglass made of 2n lines with asterisks.
 I.e. if n = 3, the below will be output:
 *****
  ***
   *
   *
  ***
 *****
 */

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Please enter a positive integer: ";
    cin >> n;
    
    //counter variable used to print the right number of 2n-1 asterisks while still maintaining integrity of original input n variable
    int counter = n;
    
    //print top half of the hourglass
    for (int i = 0; i < n; i++) {
        //print i spaces
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        //print 2(counter) - 1 asterisks
        for (int j = 0; j < (2*counter - 1); j++) {
            cout << "*";
        }
        counter--;
        cout << endl;
    }
    
    //print bottom half of the hourglass
    for (int i = n-1; i >= 0; i--) {
        counter++;
        //print i spaces
        for (int j = i; j > 0; j--) {
            cout << " ";
        }
        //print 2(counter) - 1 asterisks
        for (int j = 0; j < (2*counter - 1); j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
