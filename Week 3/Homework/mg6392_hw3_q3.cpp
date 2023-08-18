//
//  main.cpp
//  hw3q3
//
//  Created by Max Grove on 7/23/23.
//  Quadratic Equation Solver Program
/*
 This program solves quadratic equations of the type:
    ax^2 + bx + c = 0
 User inputs a, b, and c.
 Program uses b^2 - 4ac to determine num of solutions
 Uses quadratic formula to solve.
 Output: number of real solutions and the solutions
 */

#include <iostream>
#include <cmath> //for sqrt function

using namespace std;

int main() {
    double a, b, c; //inputs
    double determinant; // (b^2 - 4ac)
    double solution1, solution2;
    
    cout << "Please enter value of a: ";
    cin >> a;
    cout << "Please enter value of b: ";
    cin >> b;
    cout << "Please enter value of c: ";
    cin >> c;
    
    determinant = (b * b) - (4 * a * c);
    
    //if a,b,c are 0, there are infinite solutions.
    //if determinant is positive, 2 solutions.
    //if determinant is negative, 0 solutions.
    //if determinant is 0, 1 solution
    
    if (a == 0) {
        if (b == 0) {
            if (c == 0) { //0x^2 + 0x + 0 = 0
                cout << "This equation has infinite real solutions." << endl;
            }
            else { //0x^2 + 0x + c = 0
                cout << "This equation has no real solutions." << endl;
            }
        }
        else { //0x^2 + bx + c = 0
            solution1 = -c / b;
            cout << "This equation has 1 real solution: x=" << solution1 << endl;
        }
    }
    else if (determinant > 0) {
        solution1 = ((-1 * b) + sqrt(determinant)) / (2 * a);
        solution2 = ((-1 * b) - sqrt(determinant)) / (2 * a);
        cout << "This equation has two real solutions: x=";
        cout << solution1;
        cout << " and x=";
        cout << solution2 << endl;
    }
    else if (determinant == 0) {
        solution1 = (-1 * b) / (2 * a);
        cout << "This equation has a single real solution: x=";
        cout << solution1 << endl;
    }
    else { //determinant < 0
        cout << "This equation has 0 real solutions." << endl;
    }
    
    return 0;
}
