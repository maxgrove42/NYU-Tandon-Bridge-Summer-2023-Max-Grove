//
//  main.cpp
//  mg6392_q6
//
//  Created by Max Grove on 9/22/23.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool checkAllZerosAndOnes(string str, int &countDeleted);
void printVectorOfStrings(vector<string> strings);

int main() {
    string temp;
    int countDeleted = 0;
    vector<string> strings;
    
    cout << "Please enter a non-empty sequence of Strings. Each string should be in a separate line and consists of only decimal digit characters. To indicate the end of the input, enter an empty string in one line." << endl;
    
    getline(cin, temp);
    
    while (temp != "") {
        bool allZerosAndOnes = checkAllZerosAndOnes(temp, countDeleted);
        
        if (allZerosAndOnes) {
            strings.push_back(temp);
        }
        
        getline(cin, temp);
    }
    
    printVectorOfStrings(strings);
    cout << "Count of Number of Strings in the input sequence that get deleted for containing at least one character which is not 0 or 1: " << countDeleted << endl;
    
    return 0;
}

bool checkAllZerosAndOnes(string str, int &countDeleted) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != '0' && str[i] != '1') {
            countDeleted++;
            return false;
        }
    }
    return true;
}

void printVectorOfStrings(vector<string> strings) {
    for (int i = 0; i < strings.size(); i++) {
        cout << strings[i] << endl;
    }
}
