//
//  main.cpp
//  hw2 - Q4
//  Max Grove
//  mg6392
//  This program reads in two integers from the user
//  It will print out the results of adding, multiplying,
//  multiplying, dividing, along with div and mod them.
//  To divide, it will cast the integers as doubles.
//  Div and mod refer to the integer calculations.

#include <iostream>

using namespace std;

int main() {
    
    int firstInteger;
    int secondInteger;
    
    cout << "Please enter two positive integers, separated by a space:" << endl;
    cin >> firstInteger >> secondInteger;
    
    //addition
    cout << firstInteger << " + " << secondInteger << " = ";
    cout << firstInteger + secondInteger << endl;
    
    //subtraction
    cout << firstInteger << " - " << secondInteger << " = ";
    cout << firstInteger - secondInteger << endl;
    
    //multiply
    cout << firstInteger << " * " << secondInteger << " = ";
    cout << firstInteger * secondInteger << endl;
    
    //divide (result in decimal). Casting as double for decimal divide
    cout << firstInteger << " / " << secondInteger << " = ";
    cout << (double)firstInteger / (double)secondInteger << endl;
    
    //div (divide and remove remainder)
    cout << firstInteger << " div " << secondInteger << " = ";
    cout << firstInteger / secondInteger << endl;
    
    //mod (divide and only keep remainder)
    cout << firstInteger << " mod " << secondInteger << " = ";
    cout << firstInteger % secondInteger << endl;
    
    return 0;
}
