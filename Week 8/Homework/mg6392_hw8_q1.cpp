//
//  main.cpp
//  mg6392_hw8_q1
//
//  Created by Max Grove on 8/21/23.
//

#include <iostream>
using namespace std;

int minInArray(int arr[], int arrSize);
void printIndices(int arr[], int arrSize, int numToFind);
const int SIZE = 20;

int main() {
    int list[SIZE];
    
    cout << "Please enter a list of 20 integers separated by a space. Press enter when finished." << endl;
    
    for (int i = 0; i < SIZE; i++) {
        cin >> list[i];
    }
    int min = minInArray(list, SIZE);
    cout << "The minimum value is " << min << " and it is located in the following indices: ";
    printIndices(list, SIZE, min);
    return 0;
}

int minInArray(int arr[], int arrSize) {
    int min = arr[0];
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

void printIndices(int arr[], int arrSize, int numToFind) {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == numToFind)
            cout << i << " ";
    }
    cout << endl;
}
