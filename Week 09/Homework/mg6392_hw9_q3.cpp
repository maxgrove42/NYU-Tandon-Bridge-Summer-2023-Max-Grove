//
//  main.cpp
//  mg6392_hw9_q3
//
//  Created by Max Grove on 9/1/23.
//

#include <iostream>

using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSize);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
void printArray(int arr[], int arrSize);


int main()
{
    const int arrSize = 5;
    int arr[arrSize] = { 10, -7, 15, -3, 11 };

    cout << "Tests should output: " << endl << "10 15 11" << endl << endl;
    /********* TESTING PART A *****************/
    cout << "Testing getPosNums1" << endl;
    int outPosArrSize;
    int* posNums = getPosNums1(arr, arrSize, outPosArrSize);
    printArray(posNums, outPosArrSize);
    delete [] posNums;
    
    /********* TESTING PART B *****************/
    cout << "Testing getPosNums2" << endl;
    int *posNums2 = getPosNums2(arr, arrSize, &outPosArrSize);
    printArray(posNums2, outPosArrSize);
    delete [] posNums2;
    
    /********* TESTING PART C *****************/
    cout << "Testing getPosNums3" << endl;
    int *posNums3 = new int[arrSize];
    getPosNums3(arr, arrSize, posNums3, outPosArrSize);
    printArray(posNums3, outPosArrSize);
    delete [] posNums3;
    
    
    /********* TESTING PART D *****************/
    cout << "Testing getPosNums4" << endl;
    int *posNums4 = new int[arrSize];
    getPosNums4(arr, arrSize, &posNums4, &outPosArrSize);
    printArray(posNums4, outPosArrSize);
    delete [] posNums4;
    
    /********* END OF TESTING *****************/
    return 0;
}

void printArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
    int* posNums = new int[arrSize];
    outPosArrSize = 0;
    for (int i = 0; i < arrSize; i++) {
        if (*(arr + i) >= 0) {
            *(posNums + outPosArrSize) = arr[i];
            outPosArrSize++;
        }
    }
    return posNums;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {
    int* posNums = new int [arrSize];
    *outPosArrSizePtr = 0;
    for (int i = 0; i < arrSize; i++) {
        if (*(arr + i) >= 0) {
            *(posNums + *outPosArrSizePtr) = arr[i];
            (*outPosArrSizePtr)++;
        }
    }
    return posNums;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    outPosArrSize = 0;
    for (int i = 0; i < arrSize; i++) {
        if (*(arr + i) >= 0) {
            *(outPosArr + outPosArrSize) = *(arr + i);
            outPosArrSize++;
        }
    }
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    *outPosArrSizePtr = 0;
    for (int i = 0; i < arrSize; i++) {
        if (*(arr + i) >= 0) {
            *(*outPosArrPtr + *outPosArrSizePtr) = *(arr + i);
            (*outPosArrSizePtr)++;
        }
    }
}
