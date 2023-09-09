#include <iostream>

using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);
void printArray(int arr[], int arrSize);
void fillArrayZeros(int arr[], int arrSize);

int main()
{
    int arr[] = {3,1,3,0,6,4};
    int n = 6;
    int resArrSize;
    int *missingValues = findMissing(arr, n, resArrSize);
    cout << "Original: ";
    printArray(arr, n);
    cout << endl;
    cout << "Modified: ";
    printArray(missingValues, resArrSize);
    cout << endl;
    delete [] missingValues;
    
    int arr2[] = {3,1,3,0,6,4,4,8,9,10};
    int n2 = 10;
    int resArrSize2;
    int *missingValues2 = findMissing(arr2, n2, resArrSize2);
    cout << "Original: ";
    printArray(arr2, n2);
    cout << endl;
    cout << "Modified: ";
    printArray(missingValues2, resArrSize2);
    cout << endl;
    delete [] missingValues2;
    
    int arr3[] = {0,0,0,0};
    int n3 = 4;
    int resArrSize3;
    int *missingValues3 = findMissing(arr3, n3, resArrSize3);
    cout << "Original: ";
    printArray(arr3, n3);
    cout << endl;
    cout << "Modified: ";
    printArray(missingValues3, resArrSize3);
    cout << endl;
    delete [] missingValues3;
    
    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize) {
    int countValues[n+1];
    fillArrayZeros(countValues, n+1);
    resArrSize = n+1;
    for (int i = 0; i < n; i++) {
        if (countValues[arr[i]] == 0) resArrSize--;
        countValues[arr[i]]++;
    }
    int *outputArray = new int[resArrSize];
    for (int i = 0, j = 0; i < n + 1; i++) {
        if (countValues[i] == 0) {
            outputArray[j++] = i;
        }
    }
    return outputArray;
}

void printArray(int arr[], int arrSize) {
    cout << "[";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i];
        if (i != arrSize - 1) cout << ", ";
    }
    cout << "]";
}

void fillArrayZeros(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        arr[i] = 0;
    }
}
