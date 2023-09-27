//
//  main.cpp
//  Chap10
//
//  Created by Max Grove on 9/25/23.
//

#include <iostream>
using namespace std;

struct CDAccount {
    double balance;
    double rate;
    int term;
};

struct Date {
    int month;
    int day;
    int year;
};
struct PersonInfo {
    double height; //in inches
    int weight; //in pounds
    Date birthday; //you can have structs as part of structs
};

CDAccount createCDAccount(double balance, double rate, int term);

int main(int argc, const char * argv[]) {
    CDAccount account;
    account.balance = 1000;
    account.rate = 0.05;
    account.term = 12;
    cout << account.balance << endl;
    
    CDAccount myAccount;
    myAccount = createCDAccount(100, 0.02, 12);
    cout << myAccount.balance << endl;
    
    PersonInfo me = {72, 150, {06, 22, 1998}};
    cout << me.height << endl;
    cout << me.birthday.day << endl;
    
    return 0;
}

CDAccount createCDAccount(double newBalance, double newRate, int newTerm) {
    CDAccount temp;
    temp.balance = newBalance;
    temp.rate = newRate;
    temp.term = newTerm;
    return temp;
}
