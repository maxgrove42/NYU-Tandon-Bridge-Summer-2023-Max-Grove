//
//  main.cpp
//  examprep
//
//  Created by Max Grove on 9/13/23.
//

#include <iostream>
using namespace std;

double findMedian(int arr[], int n);
int findFirstPosition(int arr[], int arrSize, int elem);
int f(int* n, int m);
void moveZerosToEnd(int arr[], int arrSize);
int maxZeroLength(int arr[], int arrSize, int numToSearch);

int main() {
    int arr[] = {3, 5, 3, 7, 1, 7, 6};
    cout << findMedian(arr, 7) << endl;
    cout << findFirstPosition(arr, 7, 1) << endl;
    
    int n = 5;
    int m = 5;
    int res = f(&n, m);
    cout << res + n + m << endl;
    
    int arr2[] = {  3, 0, 1, 0, 2, 0};
    moveZerosToEnd(arr2, 6);
    for (int i = 0; i < 6; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    
    int arr3[] = {0, 0, 0, 0, 1, 0, 0, 0};
    cout << maxZeroLength(arr3, 8, 0) << endl;
    
    return 0;
}

double findMedian(int arr[], int n) {
    double output;
    double *countValues = new double[n+1];
    int midway = (double)(n+1) / 2;
    
    for (int i = 0; i < n+1; i++) {
        *(countValues + 1) = 0;
    }
    
    for (int i = 0; i < n; i++) {
        (*(countValues + arr[i]))++;
    }
    
    int counter = 0;
    for (int i = 0; i < n + 1; i++) {
        counter += *(countValues + i);
        if (counter >= midway) {
            output = i;
            break;
        }
        output = -1;
    }
    delete [] countValues;
    countValues = nullptr;
    return output;
    
    return 0;
}

int findFirstPosition(int arr[], int arrSize, int elem) {
    if (arrSize <= 1) {
        if (arr[0] == elem)
            return 0;
        else return -1;
    }
    else {
        if (arr[arrSize - 1] == elem) {
            int posFound = arrSize - 1;
            int nextPos = findFirstPosition(arr, arrSize - 1, elem);
            if (nextPos == -1)
                return posFound;
            else
                return nextPos;
        }
        else {
            return findFirstPosition(arr, arrSize - 1, elem);
        }
            
    }
}
int f(int* n, int m){
    *n = 10;
    m = 10;
    return *n + m;
}

void moveZerosToEnd(int arr[], int arrSize) {
    int zerosStartHere = 0;
    for (int i = 0; i < arrSize - 1; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[zerosStartHere++]);
        }
    }
}

int maxZeroLength(int arr[], int arrSize, int numToSearch) {
    int currentSet = 0;
    int currentTest = arr[arrSize - 1];
    if (currentTest == numToSearch) {
        currentTest++;
        
    }
    
    
    
    if (arrSize <= 1) {
        if (arr[arrSize - 1] == numToSearch) return 1;
        else return 0;
    }
    else {
        int thisInt = arr[arrSize - 1];
        int currentSet = 0;
        int nextSet = 0;
        if (thisInt == numToSearch) {
            currentSet++;
            currentSet += maxZeroLength(arr, arrSize - 1, numToSearch);
        }
        else
            return 0;
        nextSet = maxZeroLength(arr, arrSize - 1, numToSearch);
        return max(currentSet, nextSet);
        }
}
