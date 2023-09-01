//
//  main.cpp
//  hw4q1
//
//  Created by Max Grove on 7/30/23.
//
/*
 Reads a positive integer from the user. Prints that many even numbers starting from 2.
 Section a uses a while loop.
 Section b uses a for loop
 */

#include <iostream>
using namespace std;

int main() {
    // while loop implementation
    cout << "Section a" << endl;
    int n, counter = 1;
    cout << "Please enter a positive integer: ";
    cin >> n;
    while (counter <= n) {
        cout << 2 * (counter++) << endl;
    }
    cout << endl;
    
    //for loop implementation
    cout << "Section b" << endl;
    cout << "Please enter a positive integer: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << 2 * i << endl;
    }
    return 0;
}
