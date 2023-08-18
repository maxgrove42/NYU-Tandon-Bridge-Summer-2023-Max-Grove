#include <iostream>
using namespace std;

const int OUNCES_PER_POUND = 16;
int main() {
    int item1Pounds, item1Ounces;
    int item2Pounds, item2Ounces;
    int totalPounds, totalOunces;
    int sumOfOunces, carriedOverPounds;
    
    cout<<"Please enter the weights of two items"<<endl;
    cout<<"For each item, give its weight in pounds and ounces, ";
    cout<<"separated by a space"<<endl;
    cout<<"Item #1: ";
    cin>>item1Pounds>>item1Ounces;
    cout<<"Item #2: ";
    cin>>item2Pounds>>item2Ounces;
    
    sumOfOunces = item1Ounces + item2Ounces;
    totalOunces = sumOfOunces % OUNCES_PER_POUND;
    carriedOverPounds = sumOfOunces / OUNCES_PER_POUND;
    totalPounds = carriedOverPounds + item1Pounds + item2Pounds;
    
    cout<<"The combined weight is "<<totalPounds<<" pounds and ";
    cout<<totalOunces<<" ounces"<<endl;
    
    return 0;
}
