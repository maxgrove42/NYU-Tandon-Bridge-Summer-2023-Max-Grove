//
//  main.cpp
//  hw2_q3
//
//  Created by Max Grove on 7/20/23.
/*
 This program reads from the user the number of days, hours, minutes each of two people
 worked, and prints the total time both of them worked together as
 days, hours, minutes.
 */

#include <iostream>

using namespace std;

const int MINUTES_PER_HOUR = 60;
const int HOURS_PER_DAY = 24;

int main()
{
    int johnDays, johnHours, johnMinutes;
    int billDays, billHours, billMinutes;
    int combinedDays, combinedHours, combinedMinutes;
    int outputDays, outputHours, outputMinutes;
    
    //Input the number of hours person 1 worked.
    cout << "Please enter the number of days John has worked:" << endl;
    cin >> johnDays;
    cout << "Please enter the number of hours John has worked:" << endl;
    cin >> johnHours;
    cout << "Please enter the number of minutes John has worked:" << endl;
    cin >> johnMinutes;
    cout << endl;
    
    //Input the number of hours person 2 worked
    cout << "Please enter the number of days Bill has worked:" << endl;
    cin >> billDays;
    cout << "Please enter the number of hours Bill has worked:" << endl;
    cin >> billHours;
    cout << "Please enter the number of minutes Bill has worked:" << endl;
    cin >> billMinutes;
    cout << endl;
    
    //calculate the absolute sum of minutes, hours and days.
    combinedMinutes = (johnMinutes + billMinutes);
    combinedHours = (johnHours + billHours);
    combinedDays = johnDays + billDays;
    
    //account for any extra overages over standard minutes per hour and hours per day
    combinedHours += combinedMinutes / MINUTES_PER_HOUR;
    combinedMinutes %= MINUTES_PER_HOUR;
    combinedDays += combinedHours / HOURS_PER_DAY;
    combinedHours %= HOURS_PER_DAY;
    
    cout << "The total time both of them worked together is: ";
    cout << combinedDays << " days, ";
    cout << combinedHours << " hours, and ";
    cout << combinedMinutes << " minutes." << endl;
    
    
    
    return 0;
}
