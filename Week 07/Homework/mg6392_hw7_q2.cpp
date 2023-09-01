//
//  main.cpp
//  hw7q2
//
//  Created by Max Grove on 8/18/23.
//

#include <iostream>
#include <cmath>
void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);
void printPerfectNumbers(int start, int end);
void printAmicablePairs(int start, int end);

const int START = 2;

using namespace std;

int main() {
    int input;
    cout << "Please enter an integer greater than " << START << ": ";
    cin >> input;
    printPerfectNumbers(START, input);
    cout << endl;
    printAmicablePairs(START, input);
    cout << endl;
    return 0;
}

void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs) {
    outCountDivs = 1;
    outSumDivs = 1;
    
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            outCountDivs += 2;
            outSumDivs += (i + num / i);
        }
    }
    
    //account for perfect squares having double counted divisors of the sqrt
    if ((int)sqrt(num) == sqrt(num)) {
        outCountDivs--;
        outSumDivs -= sqrt(num);
    }
}

bool isPerfect(int num) {
    int sumDivs, temp;
    analyzeDivisors(num, temp, sumDivs);
    return (sumDivs == num);
}

void printPerfectNumbers(int start, int end) {
    cout << "Perfect Numbers between " << start << " and " << end << ":" << endl;
    for (int i = start; i <= end; i++) {
        if (isPerfect(i))
            cout << i << endl;
    }
}

void printAmicablePairs(int start, int end) {
    int sum1, sum2, temp;
    cout << "Amicable Pairs between " << start << " and " << end << ":" << endl;
    for (int i = start; i <= end; i++) {
        analyzeDivisors(i, temp, sum1); //220 x 284
        analyzeDivisors(sum1, temp, sum2); //284 x 220
        
        if (i == sum2 && i < sum1 && sum1 >= start && sum1 <= end)
            cout << "(" << i << ", " << sum1 << ")" << endl;
    }
}
