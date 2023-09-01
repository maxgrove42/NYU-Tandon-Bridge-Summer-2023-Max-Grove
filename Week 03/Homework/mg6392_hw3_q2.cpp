//
//  main.cpp
//  week3q2
//
//  Created by Max Grove on 7/23/23.
//
/*
 This program asks for a user's name, graduation year, and current year.
 It will display their current status (Freshman, sophomore, etc.)
 
 */

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    string name;
    int graduationYear, currentYear, yearDifference;
    
    cout << "Please enter your name: ";
    cin >> name;
    cout << "Please enter your graduation year: ";
    cin >> graduationYear;
    cout << "Please enter current year: ";
    cin >> currentYear;
    
    yearDifference = graduationYear - currentYear;
    //if yeardiff = 0, senior. if yeardiff = 1, junior...
    //if yeardiff > 4, not yet in college
    // if yeardiff < 0, graduated. (i.e. current year > grad year)
    
    if (yearDifference <= 0) {
        cout << name << ", you are graduated" << endl;
    }
    else if (yearDifference == 1) {
        cout << name << ", you are a Senior" << endl;
    }
    else if (yearDifference == 2) {
        cout << name << ", you are a Junior" << endl;
    }
    else if (yearDifference == 3) {
        cout << name << ", you are a Sophomore" << endl;
    }
    else if (yearDifference == 4) {
        cout << name << ", you are a Freshman" << endl;
    }
    else {
        cout << name << ", you are not in college yet" << endl;
    }
    
    return 0;
}
