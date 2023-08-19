//
//  main.cpp
//  hw7q1
//
//  Created by Max Grove on 8/18/23.
//
/*
 Prints a yearly calendar.
 Subfunctions include printing a single month calendar,
    checking if a year is a leap year,
    taking in month number and printing month name,
    returning days in month from year and month input.
 Yearly Calendar inputs require year starting day of week
 Monthly calendar inputs require number of days in month and starting day of week
 
 Sample Year Calendar for 2016 and starting Day of week = 5 shown below:
 
 January 2016
 Mon Tue Wed Thr Fri Sat Sun
                 1   2   3
 4   5   6   7   8   9   10
 11  12  13  14  15  16  17
 18  19  20  21  22  23  24
 25  26  27  28  29  30  31
 
 February 2016
 Mon Tue Wed Thr Fri Sat Sun
 1   2   3   4   5   6   7
 8   9   10  11  12  13  14
 15  16  17  18  19  20  21
 22  23  24  25  26  27  28
 29
 ... through rest of year
 */
#include <iostream>
using namespace std;

const int JAN = 1;
const int FEB = 2;
const int MAR = 3;
const int APR = 4;
const int MAY = 5;
const int JUN = 6;
const int JUL = 7;
const int AUG = 8;
const int SEP = 9;
const int OCT = 10;
const int NOV = 11;
const int DEC = 12;

const int JAN_DAYS = 31;
const int FEB_DAYS = 28;
const int MAR_DAYS = 31;
const int APR_DAYS = 30;
const int MAY_DAYS = 31;
const int JUN_DAYS = 30;
const int JUL_DAYS = 31;
const int AUG_DAYS = 31;
const int SEP_DAYS = 30;
const int OCT_DAYS = 31;
const int NOV_DAYS = 30;
const int DEC_DAYS = 31;

int printMonthCalender(int numOfDays, int startingDay); //returns DOW of final day in month. Prints a single month's calendar
bool isLeapYear(int year); //returns true if leap year, false if not
void printYearCalender(int year, int startingDay); //prints 12 month calendars
void printMonthName(int monthNumber); //prints the month name based on 1= January, 12 = December
int daysInMonth(int year, int monthNumber); // return days in month, accounts for Feb Leap years

int main() {
    int year, dayOfWeek;
    
    cout << "Please enter the year you need a calendar for: ";
    cin >> year;
    cout << "Please enter the day of the week that " << year << " started on." << endl;
    cout << "(Monday = 1, Sunday = 7)" << endl;
    cin >> dayOfWeek;
    printYearCalender(year, dayOfWeek);
    return 0;
}

int printMonthCalender(int numOfDays, int startingDay) {
    int dayOfWeek = startingDay;
    
    cout << "Mon" << "\t" << "Tue" << "\t" << "Wed" << "\t" << "Thr" << "\t" << "Fri" << "\t" << "Sat" << "\t" << "Sun";
    if (dayOfWeek <= 7) {
        cout << endl;
    }
    
    for (int i = 1; i < startingDay; i++) {
        cout << "\t";
    }
    for (int i = 1; i <= numOfDays; i++) {
        if (dayOfWeek > 7) {
            cout << endl;
            dayOfWeek = 1;
        }
        cout << i << "\t";
        dayOfWeek++;
    }
    cout << endl;
    return (--dayOfWeek);
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

void printYearCalender(int year, int startingDay) {
    for (int i = JAN; i <= DEC; i++) {
        printMonthName(i);
        cout << " " << year << endl;
        int days = daysInMonth(year, i);
        startingDay = printMonthCalender(days, startingDay) + 1;
        cout << endl;
    }
}

void printMonthName(int monthNumber) {
    if (monthNumber == JAN) cout << "January";
    else if (monthNumber == FEB) cout << "February";
    else if (monthNumber == MAR) cout << "March";
    else if (monthNumber == APR) cout << "April";
    else if (monthNumber == MAY) cout << "May";
    else if (monthNumber == JUN) cout << "June";
    else if (monthNumber == JUL) cout << "July";
    else if (monthNumber == AUG) cout << "August";
    else if (monthNumber == SEP) cout << "September";
    else if (monthNumber == OCT) cout << "October";
    else if (monthNumber == NOV) cout << "November";
    else if (monthNumber == DEC) cout << "December";
    else cout << "error"; //error handling
}

int daysInMonth(int year, int monthNumber) {
    if (monthNumber == JAN) return JAN_DAYS;
    else if (monthNumber == FEB) {
        if (isLeapYear(year))
            return FEB_DAYS + 1;
        else
            return FEB_DAYS;
    }
    else if (monthNumber == MAR) return MAR_DAYS;
    else if (monthNumber == APR) return APR_DAYS;
    else if (monthNumber == MAY) return MAY_DAYS;
    else if (monthNumber == JUN) return JUN_DAYS;
    else if (monthNumber == JUL) return JUL_DAYS;
    else if (monthNumber == AUG) return AUG_DAYS;
    else if (monthNumber == SEP) return SEP_DAYS;
    else if (monthNumber == OCT) return OCT_DAYS;
    else if (monthNumber == NOV) return NOV_DAYS;
    else if (monthNumber == DEC) return DEC_DAYS;
    else cout << 100; //error handling to make it obvious
    return 0;
}
