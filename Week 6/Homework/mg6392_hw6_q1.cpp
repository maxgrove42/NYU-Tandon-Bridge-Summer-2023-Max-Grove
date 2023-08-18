//
//  main.cpp
//  hw6q1
//
//  Created by Max Grove on 8/17/23.
//

#include <iostream>

int fib(int n);

using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    cout << "Please enter a positive integer: ";
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}

int fib(int n) {
    int fib = 0, onePrevious = 1, twoPrevious = 1;
    
    if (n == 1 || n == 2)
        return 1;
    for (int i = 3; i <= n; i++) {
        fib = onePrevious + twoPrevious;
        twoPrevious = onePrevious;
        onePrevious = fib;
    }
    return fib;
}
