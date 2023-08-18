//
//  main.cpp
//  hw2_q2
//
//  Created by Max Grove on 7/20/23.
/*
 This program asks the user to enter the dollar and cents value of money they have in the form 0 0 (i.e. separated by a space).
 The program will calculate the smallest amount of coins this would be in quarters, dimes, nickels, and dimes.
 To do this, it takes the total value, uses div of integers to find the whole number of quarters. We then set total value to the remiainder of that. We calculate how many dimes using div of integers. We continue the remainder and div process down to pennies.
 */

#include <iostream>

using namespace std;

//Setting how much each coin is worth.
const int QUARTER_VALUE = 25;
const int DIME_VALUE = 10;
const int NICKEL_VALUE = 5;
const int PENNY_VALUE = 1;
const int CENTS_PER_DOLLAR = 100;

int main()
{
    int quarters, dimes, nickels, pennies;
    int totalValue, dollars, cents;
    
    cout<<"Please enter your amount in the format of dollars and cents separated by a space:" << endl;
    
    cin >> dollars >> cents;
    
    //calculate total value in cents.
    totalValue = dollars * CENTS_PER_DOLLAR + cents;
    
    //calculate how many quarters there are using division of integers. Then set totalvalue to the remainder for use for dimes.
    quarters = totalValue / QUARTER_VALUE;
    totalValue = totalValue % QUARTER_VALUE;
    
    //calculate dimes using division of integers. Use remainder for nickels
    dimes = totalValue / DIME_VALUE;
    totalValue = totalValue % DIME_VALUE;
    
    //calculate nickels using division of integers. Use remainder for pennies
    nickels = totalValue / NICKEL_VALUE;
    totalValue = totalValue % NICKEL_VALUE;
    
    //calculate pennies
    pennies = totalValue / PENNY_VALUE;
    
    //output
    cout << dollars << " dollars and " << cents << " cents are:" << endl;
    cout << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, and " << pennies << " pennies" << endl;
    

    return 0;
}
