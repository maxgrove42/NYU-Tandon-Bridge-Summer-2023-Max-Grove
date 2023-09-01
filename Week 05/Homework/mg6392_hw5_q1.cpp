//
//  main.cpp
//  mg6392_hw5_q1
//
//  Created by Max Grove on 8/11/23.
//

#include <iostream>
using namespace std;

int main() {
    int input;
    cout << "Please enter a positive integer: " << endl;
    cin >> input;
    
    for (int i = 1; i <= input; i++) {
        for (int j = 1; j <= input; j++) {
            cout << i * j << "\t";
        }
        cout << endl;
    }
    
    return 0;
}
