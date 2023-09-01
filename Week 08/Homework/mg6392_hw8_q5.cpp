//
//  main.cpp
//  mg6392_hw8_q5
//
//  Created by Max Grove on 8/26/23.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string firstName, middleName, lastName, middleInitial;
    cout << "Please enter your name in the format First Middle Last or First M. Last:" << endl;
    cin >> firstName >> middleName >> lastName;
    middleInitial = middleName[0];
    cout << lastName << ", " << firstName << " " << middleInitial << ". " << endl;
    return 0;
}
