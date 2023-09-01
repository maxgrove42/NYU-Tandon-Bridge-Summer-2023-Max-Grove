//
//  main.cpp
//  mg6392_hw9_q4
//
//  Created by Max Grove on 9/1/23.
//

#include <iostream>

using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);
void printArray(int arr[], int arrSize);
void testArray(int arr[], int arrSize);

int main()
{
    const int arraySize = 6;
    int arr1[arraySize] = {5, 2, 4, 0, 6, 4};
    int arr2[arraySize] = {6, 3, 1, 1, 2, 9};
    int arr3[arraySize] = {1, 1, 4, 7, 6, 3};
    int arr4[arraySize] = {0, 6, 8, 5, 2, 4};
    
    testArray(arr1, arraySize);
    testArray(arr2, arraySize);
    testArray(arr3, arraySize);
    testArray(arr4, arraySize);
    
    return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize) {
    int start = 0;
    int end = arrSize - 1;
    int arrOutput[arrSize];
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 == 1) {
            arrOutput[start] = arr[i];
            start++;
        }
        else {
            arrOutput[end] = arr[i];
            end--;
        }
    }
    for (int i = 0; i < arrSize; i++) {
        arr[i] = arrOutput[i];
    }
}

void printArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void testArray(int arr[], int arrSize) {
    cout << "Original:\t";
    printArray(arr, arrSize);
    oddsKeepEvensFlip(arr, arrSize);
    cout << "Modified:\t";
    printArray(arr, arrSize);
    cout << endl;
}
