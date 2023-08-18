//
//  main.cpp
//  hw4q2
//
//  Created by Max Grove on 7/30/23.
//
/*
 Using a simplified version of the roman numeral system to represent positive integers.
 I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1,000
 They are monotonically non-increasing.
 D,L,V can appear up to 1x
 C, X, I can appear up to 4x
 */

#include <iostream>
using namespace std;

const int I = 1;
const int V = 5;
const int X = 10;
const int L = 50;
const int C = 100;
const int D = 500;
const int M = 1000;

int main(int argc, const char * argv[]) {
    int n;
    cout << "Enter decimal number: " << endl;
    cin >> n;
    
    cout << n << " is ";
    while (n > 0) {
        if (n >= M) {
            cout << "M";
            n -= M;
        }
        else if (n >= D) {
            cout << "D";
            n -= D;
        }
        else if (n >= C) {
            cout << "C";
            n -= C;
        }
        else if (n >= L) {
            cout << "L";
            n -= L;
        }
        else if (n >= X) {
            cout << "X";
            n -= X;
        }
        else if (n >= V) {
            cout << "V";
            n -= V;
        }
        else {
            cout << "I";
            n -= I;
        }
    }
    cout << endl;
    return 0;
}
