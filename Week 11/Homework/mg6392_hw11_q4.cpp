//
//  main.cpp
//  hw11_q4
//
//  Created by Max Grove on 9/18/23.
//

#include <iostream>
using namespace std;

int cheapestCost(int arr[], int arrSize);
int getMin(int input1, int input2);
void printArray(int arr[], int arrSize);

int main()
{
    int arr[] = {0,3,80,6,57,10};
    int cheapest = cheapestCost(arr, 6);
    cout << "Cheapest Cost of ";
    printArray(arr, 6);
    cout << " is: " << cheapest << endl;
    
    int arr2[] = {0,73,24,51,8,25,10};
    int cheapest2 = cheapestCost(arr2, 7);
    cout << "Cheapest Cost of ";
    printArray(arr2, 7);
    cout << " is: " << cheapest2 << endl;
    
    int arr3[] = {0,80,5,100,20,74,41,25};
    int cheapest3 = cheapestCost(arr3, 8);
    cout << "Cheapest Cost of ";
    printArray(arr3, 8);
    cout << " is: " << cheapest3 << endl;
    return 0;
}

int cheapestCost(int arr[], int arrSize) {
    if (arrSize <= 2)
        return arr[arrSize - 1];
    else {
        int compare1 = arr[arrSize - 1] + cheapestCost(arr, arrSize - 1);
        int compare2 = arr[arrSize - 1] + cheapestCost(arr, arrSize - 2);
        return getMin(compare1, compare2);
    }
}

int getMin(int input1, int input2) {
    if (input1 > input2)
        return input2;
    else
        return input1;
}

void printArray(int arr[], int arrSize) {
    cout << "[";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i];
        if (i != arrSize - 1)
            cout << ", ";
    }
    cout << "]";
}
