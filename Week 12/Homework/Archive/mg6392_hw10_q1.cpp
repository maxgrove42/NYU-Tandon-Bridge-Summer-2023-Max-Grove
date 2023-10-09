// HW 10 Q 1
#include <iostream>
#include <string>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);
void printArray(string *str, int arrSize);

int main()
{
    string sentence;
    int outWordsArrSize = 0;
    cout << "Enter your sentence followed by enter:" << endl;
    getline(cin, sentence);
    
    string* wordsArray = createWordsArray(sentence, outWordsArrSize);
    cout << "Word count: " << outWordsArrSize << endl;
    printArray(wordsArray, outWordsArrSize);
    delete [] wordsArray;
    return 0;
}

string* createWordsArray(string sentence, int& outWordsArrSize) {
    outWordsArrSize = 1;
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == ' ') outWordsArrSize++;
    }
    
    string *outputArray = new string[outWordsArrSize];
    for (int i = 0, j = 0; i < sentence.length(); i++) {
        if (sentence[i] == ' ') j++;
        else {
            outputArray[j].push_back(sentence[i]);
        }
        
    }
    
    return outputArray;
}

void printArray(string *str, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << "Word " << i+1 << ": ";
        cout << *(str + i) << endl;
    }
}
