//
//  main.cpp
//  mg6392_hw8_q3
//
//  Created by Max Grove on 8/21/23.
//

#include <iostream>
using namespace std;

void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);
void swap(int& a, int& b);
void printArray(int arr[], int arrSize);

int main(int argc, const char * argv[]) {
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;
   
    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;
   
    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;
   
    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);
    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);
    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);
    return 0;
}

void reverseArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize / 2; i++) {
        swap(arr[i], arr[arrSize - i - 1]);
    }
}

void removeOdd(int arr[], int& arrSize) {
    int evenTracker = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 == 0) {
            arr[evenTracker] = arr[i];
            evenTracker++;
        }
    }
    arrSize = evenTracker;
}

void splitParity(int arr[], int arrSize) {
    int i = 0, j = arrSize - 1;
    while (i < j) {
        if (arr[i] % 2 == 1) {
            i++;
        }
        if (arr[j] % 2 == 0) {
            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void printArray(int arr[], int arrSize){
    int i;
    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}
