//
//  main.cpp
//  hw6q4
//
//  Created by Max Grove on 8/17/23.
//

#include <iostream>
#include <cmath>
using namespace std;

void printDivisors(int num);
/*
 Given a positive integer num, prints all of num's divisors in asc. order
 Example: printDivisors(100);
 1 2 4 5 10 20 25 50 100
 */
int main() {
    int num;
    cout << "Please enter a positive integer >= 2: ";
    cin >> num;
    printDivisors(num);
    return 0;
}

void printDivisors(int num) {
    for (int i = 1; i <= sqrt(num); i++) {
        if (num % i == 0) {
            cout << i << " ";
        }
    }
    
    for (int i = sqrt(num) - 1; i >= 1; i--) {
        if (num % i == 0) {
            cout << num / i << " ";
        }
    }
    cout << endl;
    
}
