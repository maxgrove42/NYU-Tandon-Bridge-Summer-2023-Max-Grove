//
//  main.cpp
//  mg6392_q14
//
//  Created by Max Grove on 8/10/23.
// Each integer input is greater than 1 and does not lead with 0.

#include <iostream>
using namespace std;

int main() {
    int input;
    int countPerfectSquares = 0;
    int countPerfectNumbers = 0;
    cout << "Please enter a sequence of integers (with at least 1-digit and at most 9-digits), each one in a separate line. End your sequence by typing -1:" << endl;
    cin >> input;
    
    while (input != -1) {
        int squareFlag = 0;
        int divisorSum = 0;
        
        //perfect square tester. test up to input / 2 + 1 (to account for the case where the input is 1 - this is a perfect square
        //if i*i == input, then it is a square.
        for (int i = 1; i <= input / 2 + 1; i++) {
            if (i * i == input) {
                squareFlag = 1;
                break;
            }
        }
        if (squareFlag == 1)
            countPerfectSquares++;
        
        //perfect number tester. test all integers up to input / 2.
        //if input divided by that number divided has no remainder it is a divisor.
        //add that to divisorSum. if divisorSum == input, then it is perfect number.
        //not going up to input/2 + 1 here, as 1 is not a perfect number (the sum of divisors of 1 excludes 1 as that is the original number)
        for (int i = 1; i <= input / 2; i++) {
            if (input % i == 0) {
                divisorSum += i;
            }
        }
        if (divisorSum == input)
            countPerfectNumbers++;
        
        //get next input
        cin >> input;
    }
    //output
    cout << "Total count of Perfect Squares in the given sequence: " << countPerfectSquares << endl;
    cout << "Total count of Perfect Numbers in the given sequence: " << countPerfectNumbers << endl;
    
    return 0;
}
