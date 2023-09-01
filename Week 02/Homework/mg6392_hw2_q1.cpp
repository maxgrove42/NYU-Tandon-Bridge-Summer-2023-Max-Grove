//
//  main.cpp
//  hw2_q1
//
//  Created by Max Grove on 7/20/23.
/*
 This program asks the user to input the number of
 quarters, dimes, nickels and pennies they have.
 It will output the dollar value they have in the form x dollars and x cents.
 */

#include <iostream>

using namespace std;

//constants defining how much a given coin is worth
const int QUARTER_VALUE = 25;
const int DIME_VALUE = 10;
const int NICKEL_VALUE = 5;
const int PENNY_VALUE = 1;
const int CENTS_PER_DOLLAR = 100;

int main()
{
    int quarters, dimes, nickels, pennies;
    int totalValue, dollars, cents;
    
    cout<<"Please enter number of coins:" << endl;
    
    cout << "# of quarters: ";
    cin >> quarters;
    cout << "# of dimes: ";
    cin >> dimes;
    cout << "# of nickels: ";
    cin >> nickels;
    cout << "# of pennies: ";
    cin >> pennies;
    
    //calculate the total value.
    totalValue = quarters * QUARTER_VALUE + dimes * DIME_VALUE + nickels * NICKEL_VALUE + pennies * PENNY_VALUE;
    dollars = totalValue / CENTS_PER_DOLLAR;
    cents = totalValue % CENTS_PER_DOLLAR;
    
    //output the total value in dollars and cents
    cout << "The total is " << dollars << " dollars and " << cents << " cents." << endl;

    return 0;
}
