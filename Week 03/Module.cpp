//
//  main.cpp
//  week 3
//
//  Created by Max Grove on 7/21/23.
//

#include <iostream>
using namespace std;

int main() {
    double arg1, arg2, result;
    char op;
    
    cout << "Please input a math expr of form: arg1 op arg2" << endl;
    cin >> arg1 >> op >> arg2;
    
    switch (op) {
        case '+':
            result = arg1 + arg2;
            cout << result << endl;
            break;
        case '-':
            result = arg1 - arg2;
            cout << result << endl;
            break;
        case '*':
            result = arg1 * arg2;
            cout << result << endl;
            break;
        case '/':
            if (arg2 != 0) {
                result = arg1 / arg2;
                cout << result << endl;
            }
            else
                cout << "This is an illegal expression." << endl;
            break;
        default:
            cout << "This is an illegal expression." << endl;
            break;
    }
    return 0;
}
