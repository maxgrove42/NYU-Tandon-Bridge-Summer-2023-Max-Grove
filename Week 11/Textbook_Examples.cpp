//
//  main.cpp
//  chap14_recursion
//
//  Created by Max Grove on 9/1/23.
//

#include <iostream>
using namespace std;

void asteriskPrinter(int asterisks);
void printBackward(int input);
void printOneToN(int n);
void printNToOne(int n);
int mystery(int n);
double power(int x, int n);


int main() {
    cout << "should be *****: ";
    asteriskPrinter(5);
    cout << endl;
    
    cout << "should be 4321: ";
    printBackward(1234);
    cout << endl;
    
    cout << "should be 1 2 3 4 5: ";
    printOneToN(5);
    cout << endl;
    
    cout << "should be 5 4 3 2 1: ";
    printNToOne(5);
    cout << endl;
    
    cout << "should be 15: ";
    cout << mystery(5) << endl;
    
    cout << "should be 64: ";
    cout << power(4,3) << endl;
    
    cout << "should be 1/64 = 0.015625: ";
    cout << power(4, -3) << endl;
    
    return 0;
}

void asteriskPrinter(int asterisks) {
    if (asterisks <= 1) {
        cout << "*";
    }
    else {
        asteriskPrinter(--asterisks);
        cout << "*";
    }
}

void printBackward(int input) {
    if (input < 10)
        cout << input % 10;
    else {
        cout << input % 10;
        printBackward(input / 10);
    }
}

void printOneToN(int n) {
    if (n == 1) cout << 1 << " ";
    else {
        printOneToN(--n);
        cout << n + 1 << " ";
    }
}

void printNToOne(int n) {
    if (n == 1) cout << 1 << " ";
    else {
        cout << n << " ";
        printNToOne(--n);
    }
}

int mystery(int n) {
    if (n <= 1) return 1;
    else return (mystery(n-1)+n);
}

double power(int x, int n) {
    if (n < 0) {
        return (1.0/x * power(x, n+1));
    }
    else if (n > 0)
        return (x * power(x, n-1));
    else
        return 1;
}
