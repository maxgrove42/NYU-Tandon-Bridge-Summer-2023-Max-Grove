//
//  main.cpp
//  hw4q6
//
//  Created by Max Grove on 7/31/23.
//
/*
This program asks the user to input a positive integer.
It will output all of the numbers up and including that number
where the number has more even digits than odd digits.
Ties of odd and even digits will not print.
*/

#include <iostream>

using namespace std;

int main()
{
    int input;
    cout << "Please enter a positive integer: ";
    cin >> input;
    
    //test all numbers up to input
    for (int i = 1; i <= input; i++) {
        int current = i, numEven = 0, numOdd = 0;
        
        //test each digit in current
        while (current > 0) {
            //get the ones digit of current
            int digit = current % 10;
            if (digit % 2 == 0) {
                numEven++;
            }
            else {
                numOdd++;
            }
            
            //prepare to test the next digit to the left in current
            current /= 10;
        }
        
        //print i if number of even digits > number of odd digits
        if (numEven > numOdd) {
            cout << i << endl;
        }
    }

    return 0;
}
