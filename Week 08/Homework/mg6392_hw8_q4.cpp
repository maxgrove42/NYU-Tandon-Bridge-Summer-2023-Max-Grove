//
//  main.cpp
//  mg6392_hw8_q4
//
//  Created by Max Grove on 8/25/23.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

const int MAX_NUM_HIDER = 3; //maximum value we can use to hide the PIN
const int PIN[5] = {1,1,3,7,7};

void printArray(int arr[], int arrSize);
void printHider(int arr[], int arrSize);
int mapPin(int hiddenDigits[]);

int main() {
    int hiddenDigits[10];
    int possibleDigits[10] = {0,1,2,3,4,5,6,7,8,9};
    int input, mappedPIN;
    
    cout << "Please enter your PIN according to the following mapping: " << endl;
    cout << "PIN: ";
    printArray(possibleDigits, 10);
    printHider(hiddenDigits, 10);
    
    mappedPIN = mapPin(hiddenDigits);
    cin >> input;
    
    if (mappedPIN == input)
        cout << "Your PIN is correct." << endl;
    else
        cout << "Your PIN is not correct." << endl;
    
    return 0;
}

void printArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void printHider(int arr[], int arrSize) {
    srand(time(0));
    for (int i = 0; i < arrSize; i++){
        arr[i] = rand() % (MAX_NUM_HIDER) + 1;
    }
    cout << "NUM: ";
    printArray(arr, arrSize);
}

int mapPin(int hiddenDigits[]) {
    int output = 0;
    for (int i = 0; i < 5; i++) {
        output += pow(10,4-i)*hiddenDigits[PIN[i]];
    }
    return output;
}

