//
//  main.cpp
//  hw11_q1
//
//  Created by Max Grove on 9/18/23.
//

#include <iostream>
using namespace std;

void printTriangle(int n);
void printOppositeTriangles(int n);
void printRuler(int n);

int main() {
    printTriangle(5);
    cout << endl;
    printOppositeTriangles(5);
    cout << endl;
    printRuler(5);
    return 0;
}

void printTriangle(int n) {
    if (n <= 0) return;
    else {
        printTriangle(n-1);
        for (int i = 0; i < n; i++) {
            cout << "*";
        }
        cout << endl;
    }
}

void printOppositeTriangles(int n) {
    if (n <= 0) return;
    else {
        for (int i = 0; i < n; i++) {
            cout << "*";
        }
        cout << endl;
        printOppositeTriangles(n-1);
        for (int i = 0; i < n; i++) {
            cout << "*";
        }
        cout << endl;
    }
}

void printRuler(int n) {
    if (n <= 0) return;
    else {
        printRuler(n-1);
        for (int i = 0; i < n; i++) {
            cout << "-";
        }
        cout << endl;
        printRuler(n-1);
    }
    
}
