//
//  main.cpp
//  mg6392_hw8_q2
//
//  Created by Max Grove on 8/21/23.
//

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);
string makeLower(string str);
string removePunctuation(string str);
string cleanString(string str);

const string PUNCTUATION = ",;:.?!'\" "; //includes space

int main() {
    string word;
    cout << "Please enter a word: ";
    cin >> word;
    word = cleanString(word);
    if (isPalindrome(word))
        cout << word << " is a palindrome" << endl;
    else
        cout << word << " is not a palindrome" << endl;
    return 0;
}

bool isPalindrome(string str) {
    for (int i = 0; i < str.length() / 2; i++) {
        int j = (int)(str.length() - i - 1);
        char start = str[i];
        char end = str[j];
        if (start != end) {
            return false;
        }
    }
    return true;
}

string makeLower(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] -= ('A' - 'a');
    }
    return str;
}

string removePunctuation(string str) {
    string output = "";
    for (int i = 0; i < str.length(); i++) {
        int loc = PUNCTUATION.find(str[i]);
        if (loc < 0 && loc > str.length()) { //if loc is not explicitly inside the string
            output += str[i];
        }
    }
    return output;
}

string cleanString(string str) {
    return makeLower(removePunctuation(str));
}
