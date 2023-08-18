//
//  main.cpp
//  module6
//
//  Created by Max Grove on 7/28/23.
// reads grades of students in class and prints the average

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int temp;
    int students = 0, sum = 0;
    

    cout << "Enter the students' grades separated by a space, ending with a -1: ";
    cin >> temp;
    while (temp >= 0) {
        sum += temp;
        cin >> temp;
        students++;
    }
    
    cout << "The average is " << (double)sum / students << endl;
    
    return 0;
}
