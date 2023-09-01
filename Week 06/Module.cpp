//
//  main.cpp
//  modeule 8
//
//  Created by Max Grove on 8/11/23.
//


#include <iostream>
#include <cmath>

int determinant(int a, int b, int c);
int quadratic(double a, double b, double c, double& outSol1, double& outSol2);

int const ZERO_SOLN = 0;
int const ONE_SOLN = 1;
int const TWO_SOLN = 2;
int const ALL_SOLN = 3;

using namespace std;
int main() {
    double a, b, c, sol1, sol2;
    cout << "Please enter coefficients: " << endl;
    cin >> a >> b >> c;
    
    int quadraticType = quadratic(a, b, c, sol1, sol2);
    switch (quadraticType) {
        case ZERO_SOLN:
            cout << "0 solutions." << endl;
            break;
        case ONE_SOLN:
            cout << "1 solution: " << sol1;
            break;
        case TWO_SOLN:
            cout << "2 solutions: " << sol1 << " and " << sol2 << endl;
            break;
        case ALL_SOLN:
            cout << "Infinite real solutions." << endl;
            break;
        default:
            cout << "Error." << endl;
            break;
    }
    
    
    return 0;
}

int determinant(int a, int b, int c) {
    return (b*b) - (4 * a * c);
}

int quadratic(double a, double b, double c, double& outSol1, double& outSol2) {
    int determ;
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                return ALL_SOLN;
            }
            else {
                return ZERO_SOLN;
            }
        }
        else {
            outSol1 = (-1 * c) / b;
            return ONE_SOLN;
        }
    }
    else {
        determ = determinant(a, b, c);
        if (determ < 0) {
            return ZERO_SOLN;
        }
        else if (determ == 0) {
            outSol1 = (-1 * b) / (2 * a);
            return ONE_SOLN;
        }
        else {
            outSol1 = (-1 * b + sqrt(determ)) / (2 * a);
            outSol2 = (-1 * b - sqrt(determ)) / (2 * a);
            return TWO_SOLN;
        }
    }
}
