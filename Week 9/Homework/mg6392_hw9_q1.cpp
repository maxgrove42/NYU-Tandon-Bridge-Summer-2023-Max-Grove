//
//  main.cpp
//  mg6392_hw4_q1
//
//  Created by Max Grove on 8/30/23.
//

#include <iostream>
#include <string>
using namespace std;

const int NUM_LETTERS = 26;

string getSingleWord(string str, int& startChar); //returns the first word after startChar as a string
void makeLower(string& str);
void initializeArrayToZero(int arr[], int arrSize);

int main() {
    
    string input, singleWord;
    int countWords = 0;
    bool insideWord = false;
    
    int letters[NUM_LETTERS];
    initializeArrayToZero(letters, NUM_LETTERS);
    
    cout << "Please enter a line of text: " << endl;
    getline(cin, input);
    makeLower(input);
    
    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];
        if (ch == ' ' || ch == ',' || ch == '.') {
            if (insideWord) {
                countWords++;
            }
            insideWord = false;
        }
        else {
            letters[input[i] - 'a']++;
            insideWord = true;
        }
    }
    //account for the case the sentence does not end in a period, comma or space
    if (insideWord)
        countWords++;
    
    cout << countWords << "\twords" << endl;

    for (int i = 0; i < NUM_LETTERS; i++) {
        if (letters[i] != 0)
            cout << letters[i] << "\t" << (char)('a' + i) << endl;
    }
    
    return 0;
}

void makeLower(string& str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] -= ('A' - 'a');
    }
}

void initializeArrayToZero(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        arr[i] = 0;
    }
}

