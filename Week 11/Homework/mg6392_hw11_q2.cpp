//
//  main.cpp
//  hw11_q2
//
//  Created by Max Grove on 9/11/23.
//

#include <iostream>
using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main() {
    int arr1[] = {3, 2, 2, 8};
    int arr2[] = {1, 4, 5, 6};
    int sum1 = sumOfSquares(arr1, 4);
    int sum2 = sumOfSquares(arr2, 4);
    bool isSorted1 = isSorted(arr1, 4);
    bool isSorted2 = isSorted(arr2, 4);
    cout << "sum of squares 1: " << sum1 << endl;
    if (isSorted1) cout << "isSorted 1: True" << endl;
    else cout << "isSorted 1: False" << endl;
    cout << "Sum of squares 2: " << sum2 << endl;
    if (isSorted2) cout << "isSorted 2: True" << endl;
    else cout << "isSorted 2: False" << endl;
    return 0;
}

int sumOfSquares(int arr[], int arrSize) {
    if (arrSize <= 0) return 0;
    else if (arrSize == 1) {
        return arr[arrSize - 1] * arr[arrSize - 1];
    }
    else {
        return arr[arrSize - 1] * arr[arrSize - 1] + sumOfSquares(arr, arrSize-1);
    }
    return 0;
}

bool isSorted(int arr[], int arrSize) {
    if (arrSize <= 1) {
        return true;
    }
    else {
        if (arr[arrSize - 2] > arr[arrSize - 1])
            return false;
        else
            return isSorted(arr, arrSize - 1);
    }
}
