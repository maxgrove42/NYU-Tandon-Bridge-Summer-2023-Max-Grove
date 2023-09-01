//
//  main.cpp
//  hw3q6
//
//  Created by Max Grove on 7/23/23.
//  Long distance call cost calculator.
/*
 This program computes cost of a long-distance call (which should be free in today's day and age).
 These are the cost compute rules:
  - Call started Mon - Fri 8AM - 6PM incl. = $0.40 / minute
  - Call started Mon - Fri 6PM - 8AM excl. = $0.25 / minute
  - Call started Sat or Sun = $0.15 / minute
 
 Inputs: Day of week, time call started, length of call.
    - Time call started to be input in 24HR notation
    - Day of week to be input as 2-letter abbreviation (mo, tu, we, th)
    - number of minutes to be positive integer
 Outputs: Cost of call based on above rules.
 
 Note: cost to be determined in cents to use integers for memory mgmt, then output as double of type $0.00
        Times will be handled as doubles once input by user. I.e. 13:30 will become 13.5, to allow for time comparisons
 */

#include <iostream>
#include <string>

const int WEEKDAY_PEAK_RATE = 40;
const int WEEKDAY_OFFPEAK_RATE = 25;
const int WEEKEND_RATE = 15;

//below times are in 24-hour time (i.e. 6PM = hour 18, minute 0)
const int WEEKDAY_PEAK_START_HOUR = 8; //hour when weekday peak starts. Peak rate will include this time
const int WEEKDAY_PEAK_START_MINUTE = 0; //minute of hour when weekday peak starts. Peak rate will include this time.
const int WEEKDAY_PEAK_END_HOUR = 18; //hour when weekday peak ends. Peak rate will include this time
const int WEEKDAY_PEAK_END_MINUTE = 0; //minute of hour when weekday peak ends. Peak rate will include this time

const double MINUTES_PER_HOUR = 60.0;

using namespace std;

int main() {
    int callHourStart, callMinuteStart, callLength, costCents;
    char colon; // temp variable used for colon in time input
    string dayOfWeek;
    double callStartTime; //decimal version of callHourStart + callMinuteStart / 60
    
    //initialization of when weekday peak starts and ends. Using double to allow for simpler comparisons later
    double weekdayPeakStartTime = WEEKDAY_PEAK_START_HOUR + (WEEKDAY_PEAK_START_MINUTE / MINUTES_PER_HOUR);
    double weekdayPeakEndTime = WEEKDAY_PEAK_END_HOUR + (WEEKDAY_PEAK_END_MINUTE / MINUTES_PER_HOUR);
    
    cout << "Please enter the time of day the call started (24-Hour format - i.e. 13:30): ";
    cin >> callHourStart >> colon >> callMinuteStart;
    cout << "Please enter the day of week (two-letter abbreviation i.e. Mo, Tu, etc): ";
    cin >> dayOfWeek;
    cout << "Please enter the call length (in minutes): ";
    cin >> callLength;
    
    callStartTime = callHourStart + (callMinuteStart / (double)60.0);
    
    //check if we are on a weekend. Use weekend rate if so.
    if (dayOfWeek == "Sa" || dayOfWeek == "Su" || dayOfWeek == "sa" || dayOfWeek == "su" || dayOfWeek == "SA" || dayOfWeek == "SU") {
        costCents = callLength * WEEKEND_RATE;
    }
    //if we are not on a weekend, check if we are starting in a peak time.
    //Use peak rate if so. Otherwise, use nonpeak rate.
    else {
        if (callStartTime >= weekdayPeakStartTime && callStartTime <= weekdayPeakEndTime)
            costCents = callLength * WEEKDAY_PEAK_RATE;
        else
            costCents = callLength * WEEKDAY_OFFPEAK_RATE;
    }
    
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "Call cost is: $" << costCents / (double)100.0 << endl;
    
    return 0;
}
