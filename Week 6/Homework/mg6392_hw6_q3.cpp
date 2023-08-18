//
//  main.cpp
//  hw6q3
//
//  Created by Max Grove on 8/17/23.
//

#include <iostream>
double eApprox(int n);
/*
 Approximates e using the infinite series definition:
 e = 1 + 1/1! + 1/2! + 1/3! + ... 1/n!
 Inputs: n
 Outputs: result of the sum from 1 to n of the above summation
 */

using namespace std;

int main() {
    cout.precision(30);
    for (int n = 1; n <= 15; n++) {
        cout << "n = " << n << "\t" << eApprox(n) << endl;
    }
    return 0;
}

double eApprox(int n) {
    double factorial = 1;
    double result = 1;
    for (int i = 1; i <= n; i++) {
        result += 1/factorial;
        factorial *= (1+i);
    }
    return result;
}
