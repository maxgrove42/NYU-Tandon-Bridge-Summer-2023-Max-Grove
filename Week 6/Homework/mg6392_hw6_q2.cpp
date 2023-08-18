//
//  main.cpp
//  hw6q2
//
//  Created by Max Grove on 8/17/23.
//

#include <iostream>

void printShiftedTriangle(int n, int m, char symbol);
/* Prints a shifted triangle. Prints n rows of symbol, shifted m spaces from left margin.
 Inputs: n = num lines, m = shift from margin, symbol = symbol to print.
 Output example: printShiftedTriangle(3, 4, '+');
       +
      +++
     +++++
 */

void printPineTree(int n, char symbol);
/* Prints a pine tree of n parts consisting of n symbols
 Output example: printPineTree(3, '#');
 
    #
   ### //this and above is part one
    #
   ###
  ##### //from part one to here is part two
    #
   ###
  #####
 ####### //from part two to here is part three
 
 */

using namespace std;
int main() {
    char symbol;
    int n;
    
    cout << "Please enter the number of parts you want the pine tree to have: ";
    cin >> n;
    cout << "Please enter the symbol you want the pine tree to be made of: ";
    cin >> symbol;
    printPineTree(n, symbol);
    return 0;
}

void printShiftedTriangle(int n, int m, char symbol) {
    for (int i = 1; i <= n; i++) {
        int spaces = n - i;
        int symbols = 2*i - 1;
        for (int j = 1; j <= m; j++) {
            cout << " ";
        }
        for (int j = 1; j <= spaces; j++) {
            cout << " ";
        }
        for (int j = 1; j <= symbols; j++) {
            cout << symbol;
        }
        cout << endl;
    }
}

void printPineTree(int n, char symbol) {
    int rows = 2;
    int m = n - 1;
    for (int i = 1; i <= n; i++) {
        printShiftedTriangle(rows, m, symbol);
        rows++;
        m--;
    }
}
