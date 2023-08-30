//
//  main.cpp
//  mg6392_hw8_q6
//
//  Created by Max Grove on 8/26/23.
//

#include <iostream>
#include <string>
using namespace std;

bool isAllDigits(string str);
string getSingleWord(string str, int& startChar); //returns the first word after startChar as a string
void convertWordToHidden(string& str);

int main() {
    string lineOfText, word;
    int startChar = 0;
    
    cout << "Please enter a line of text:" << endl;
    getline(cin, lineOfText);
    
    do {
        word = getSingleWord(lineOfText, startChar);
        if (isAllDigits(word))
            convertWordToHidden(word);
        cout << word << ' ';
    } while (startChar > 0);
    cout << endl;

    return 0;
}

bool isAllDigits(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

string getSingleWord(string str, int& startChar) {
    int firstSpace = str.find(' ', startChar);
    string word = str.substr(startChar,firstSpace - startChar);
    startChar = firstSpace + 1;
    return word;
}

void convertWordToHidden(string& str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = 'x';
    }
}
