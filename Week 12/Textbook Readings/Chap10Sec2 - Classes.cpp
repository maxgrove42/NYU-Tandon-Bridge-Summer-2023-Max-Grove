//
//  main.cpp
//  chap10sec2 classes
//
//  Created by Max Grove on 9/25/23.
//

#include <iostream>
using namespace std;

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

int main() {
    DayOfYear myBirthday;
    myBirthday.setMonth(6);
    myBirthday.setDay(22);
    myBirthday.output();
    
    myBirthday.setMonth(13);
    myBirthday.setDay(23);
    myBirthday.output();
    
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
