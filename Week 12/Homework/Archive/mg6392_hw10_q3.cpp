#include <iostream>
#include <vector>

using namespace std;

int main1();
int main2();

void resizeArray(int *&input, int &size);

int main()
{
    cout << "Testing Part 1:" << endl;
    int main1Return = main1();
    cout << endl << "Testing Part 2:" << endl;
    int main2Return = main2();
    return main1Return + main2Return;
}


int main1() {
    int size = 10;
    int *input = new int[size];
    int search, temp, inputSize = 0, foundSize = 0;
    
    cout << "Please enter a sequence of positive integers, each in a separate line." << endl << "End you input by typing -1." << endl;
    cin >> temp;
    while (temp != -1) {
        if(inputSize == size - 1) {
            resizeArray(input, size);
        }
        
        input[inputSize++] = temp;
        cin >> temp;
    }
    
    int *found = new int[inputSize];
    cout << "Please enter a number you want to search." << endl;
    cin >> search;
    
    for (int i = 0; i < inputSize; i++) {
        if (input[i] == search) {
            found[foundSize++] = i + 1;
        }
    }
    
    if (foundSize == 0) {
        cout << search << " was not found." << endl;
    }
    else {
        cout << search << " shows in line";
        if (foundSize > 1) cout << "s";
        cout << " ";
        for (int i = 0; i < foundSize; i++) {
            cout << found[i];
            if (i == foundSize - 1)
                cout << "." << endl;
            else
                cout << ", ";
        }
    }
    return 0;
}

int main2() {
    int temp, search;
    vector<int> input, found;
    cout << "Please enter a sequence of positive integers, each in a separate line." << endl << "End you input by typing -1." << endl;
    cin >> temp;
    while (temp != -1) {
        input.push_back(temp);
        cin >> temp;
    }
    cout << "Please enter a number you want to search." << endl;
    cin >> search;
    
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == search) found.push_back(i + 1);
    }
    if (found.size() == 0) {
        cout << search << " was not found." << endl;
    }
    else {
        cout << search << " shows in line";
        if (found.size() > 1) cout << "s";
        cout << " ";
        for (int i = 0; i < found.size(); i++) {
            cout << found[i];
            if (i == found.size() - 1)
                cout << "." << endl;
            else
                cout << ", ";
        }
    }
    return 0;
}

void resizeArray(int *&input, int &size) {
    size = 2 * size;
    int *outputArray = new int[size];
    for (int i = 0; i < size / 2; i++) {
        outputArray[i] = input[i];
    }
    delete [] input;
    input = outputArray;
}
