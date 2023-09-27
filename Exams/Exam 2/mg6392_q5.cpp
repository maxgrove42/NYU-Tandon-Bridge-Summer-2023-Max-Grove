//
//  main.cpp
//  mg6392_q5
//
//  Created by Max Grove on 9/22/23.
//
// Exam 2: Q5

#include <iostream>
using namespace std;

int findOddIntegersAndSum(int S[], int length, int &sumOdds);

int main() {
    int S1[] = {10, -5, -20, 0, 7, -15, -5, -100};
    int S2[] = {-1, -5, -70, -15, -26, -44, 0, 25, -14, -3};
    int S3[] = {9, 0, 13, 17, 29, -14, -60, 9, -9};
    int S4[] = {1, 5, 20, 0, -40};
    int sumOdds = 0, oddCount = 0;
    
    oddCount = findOddIntegersAndSum(S1, 8, sumOdds);
    cout << "S1 Odd Count: " << oddCount << endl << "S1 OddSum: " << sumOdds << endl;
    sumOdds = 0;
    
    oddCount = findOddIntegersAndSum(S2, 10, sumOdds);
    cout << "S2 Odd Count: " << oddCount << endl << "S2 OddSum: " << sumOdds << endl;
    sumOdds = 0;
    
    oddCount = findOddIntegersAndSum(S3, 9, sumOdds);
    cout << "S3 Odd Count: " << oddCount << endl << "S3 OddSum: " << sumOdds << endl;
    sumOdds = 0;
    
    oddCount = findOddIntegersAndSum(S4, 5, sumOdds);
    cout << "S4 Odd Count: " << oddCount << endl << "S4 OddSum: " << sumOdds << endl;
    sumOdds = 0;
    
    return 0;
}

int findOddIntegersAndSum(int S[], int length, int &sumOdds) {
    if (length < 1) return 0;
    else if (length == 1) {
        if (S[length - 1] % 2 == 1 || S[length - 1] % 2 == -1) {
            sumOdds += S[length - 1];
            return 1;
        }
        else return 0;
    }
    else {
        if (S[length - 1] % 2 == 1 || S[length - 1] % 2 == -1) {
            sumOdds += S[length - 1];
            return 1 + findOddIntegersAndSum(S, length - 1, sumOdds);
        }
        else {
            return findOddIntegersAndSum(S, length - 1, sumOdds);
        }
    }
}
