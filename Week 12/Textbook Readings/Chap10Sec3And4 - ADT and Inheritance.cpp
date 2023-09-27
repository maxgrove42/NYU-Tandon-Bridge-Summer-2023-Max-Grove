//
//  main.cpp
//  chap10sec3-abstractdatatypes
//
//  Created by Max Grove on 9/25/23.
//

#include <iostream>
using namespace std;
/* Best practices for ensuring a class is an Abstract Data Type:
    - Make all member variable private
    - Make necessary functions public.
    - Make any helper functions as private
 */

class DayOfYear {
public:
    DayOfYear(int newMonth, int newDay);
    DayOfYear();
    void setDate(int newMonth, int newDay);
    void output();
    int getMonth();
    int getDay();
    void setMonth(int newMonth);
    void setDay(int newDay);
private:
    bool checkDate();
    int month;
    int day;
};

//derived class of DayOfYear
class Date : public DayOfYear {
public:
    Date(int newMonth, int newDay, int newYear);
    Date(int newMonth, int newDay);
    Date();
    void setYear(int newYear);
    int getYear();
private:
    int year;
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

DayOfYear::DayOfYear(int newMonth, int newDay) {
    month = newMonth;
    day = newDay;
}
DayOfYear::DayOfYear() {
    month = 1;
    day = 1;
}

void DayOfYear::setDate(int newMonth, int newDay) {
    setMonth(newMonth);
    setDay(newDay);
}

void DayOfYear::output() {
    cout << month << "/" << day << endl;
}

int DayOfYear::getMonth() {
    return month;
}
int DayOfYear::getDay() {
    return day;
}
void DayOfYear::setMonth(int newMonth) {
    month = newMonth;
    checkDate();
}
void DayOfYear::setDay(int newDay) {
    day = newDay;
    checkDate();
}

bool DayOfYear::checkDate() {
    if (month < 1 || month > 12) {
        cout << "Invalid Month. Setting Month to default value of 1." << endl;
        month = 1;
        return false;
    }
    else {
        if (month == 2) {
            if (day < 1 || day > 29) {
                cout << "Invalid Day of Month. Setting Day to default value of 1." << endl;
                day = 1;
                return false;
            }
        }
        else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            if (day < 1 || day > 31) {
                cout << "Invalid Day of Month. Setting Day to default value of 1." << endl;
                day = 1;
                return false;
            }
        }
        else {
            if (day < 1 || day > 30) {
                cout << "Invalid Day of Month. Setting Day to default value of 1." << endl;
                day = 1;
                return false;
            }
        }
    }
    return true;
}

Date::Date(int newMonth, int newDay, int newYear) {
    setMonth(newMonth);
    setDay(newDay);
    year = newYear;
}
Date::Date(int newMonth, int newDay) {
    setMonth(newMonth);
    setDay(newDay);
}
Date::Date() {
    setMonth(1);
    setDay(1);
    year = 1900;
}

void Date::setYear(int newYear) {
    year = newYear;
}
int Date::getYear() {
    return year;
}
