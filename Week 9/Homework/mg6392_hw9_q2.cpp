//
//  main.cpp
//  mg6392_hw9_q2
//
//  Created by Max Grove on 9/1/23.
//

#include <iostream>
#include <string>
using namespace std;

void makeLower(string& str);
int* countLetters(string str);
void printLetterArray(int arr[], int arrSize);
bool compareArrays(int arr1[], int arrSize1, int arr2[], int arrSize2);

int main() {
    string str1, str2;
    
    cout << "Enter your 1st sentence followed by enter: " << endl;
    getline(cin, str1);
    cout << "Enter your 2nd sentence followed by enter: " << endl;
    getline(cin, str2);
    
    makeLower(str1);
    makeLower(str2);
    int* letterCounts1 = countLetters(str1);
    int* letterCounts2 = countLetters(str2);
    bool anagrams = compareArrays(letterCounts1, 26, letterCounts2, 26);
    
    if (anagrams)
        cout << "The two sentences are anagrams." << endl;
    else
        cout << "The two sentences are NOT anagrams." << endl;
    
    delete [] letterCounts1;
    delete [] letterCounts2;
    return 0;
}

void makeLower(string& str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] -= ('A' - 'a');
    }
}

int* countLetters(string str) {
    int *countLetters = new int[26];
    for (int i = 0; i < 26; i++) {
        *(countLetters + i) = 0;
    }
    
    for (int i = 0; i < str.length(); i++) {
        (*(countLetters + str[i] - 'a'))++;
    }
    
    return countLetters;
}

void printLetterArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            cout << (char)('a' + i) << "\t";
            cout << arr[i] << endl;
        }
    }
    cout << endl;
}

bool compareArrays(int arr1[], int arrSize1, int arr2[], int arrSize2) {
    if (arrSize1 != arrSize2) return false;
    for (int i = 0; i < arrSize1; i++) {
        if (arr1[i] != arr2[i]) return false;
    }
    return true;
}
