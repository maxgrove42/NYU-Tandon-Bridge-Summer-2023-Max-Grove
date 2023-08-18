//
//  main.cpp
//  mg6392_q13.cpp
//
//  Created by Max Grove on 8/10/23.
//

#include <iostream>
using namespace std;
int main() {
    int input;
    cout << "Please enter a positive integer:" << endl;
    cin >> input;
    
    int rows = 2*input + 1;
    int spaces = input;
    int asterisks = 1;
    int topHalf = input + 1;
    
    //total number of rows is 2*input + 1
    //print the spaces, then the asterisks
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= spaces; j++) {
            cout << " ";
        }
        for (int j = 1; j <= asterisks; j++) {
            cout << "*";
        }
        cout << endl;
        if (i < topHalf) {
            spaces--;
            asterisks += 2;
        }
        else {
            spaces++;
            asterisks -= 2;
        }
    }
    
    return 0;
}
