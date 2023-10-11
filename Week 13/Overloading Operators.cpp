//
//  main.cpp
//  chap11sec3 overload operators
//
//  Created by Max Grove on 9/25/23.
//

#include <iostream>
using namespace std;
/* Syntax for overloading operators:

friend Money operator +(const Money& amount1, const Money& amount2);
friend bool operator ==(const Money& amount1, const Money& amount2);

*/

class MyClass {
public:
    MyClass(int newValue);
    MyClass();
    int getValue();
    void setValue(int newValue);
    friend bool operator ==(const MyClass &item1, const MyClass &item2);
    //friend bool operator ==(const MyClass &item1, const int item2);
private:
    int value;
};
int main(int argc, const char * argv[]) {
    MyClass item1, item2;
    item1.setValue(8);
    item2.setValue(8);
    cout << (item1 == 8) << endl;
    return 0;
}

MyClass::MyClass() {
    cout << ("constructor blank running") << endl;
}
MyClass::MyClass(int newValue) {
    cout << ("constructor with a value running") << endl;
    value = newValue;
}
int MyClass::getValue() {
    return value;
}
void MyClass::setValue(int newValue) {
    value = newValue;
}

bool operator ==(const MyClass &item1, const MyClass &item2) {
    cout << "using overloaded operator with two classes" << endl;
    return (item1.value == item2.value);
}
/*
bool operator ==(const MyClass &item1, const int item2) {
    cout << "using overloaded operator with int" << endl;
    return (item1.value == item2);
}
*/
