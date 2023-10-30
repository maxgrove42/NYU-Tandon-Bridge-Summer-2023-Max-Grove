/*

(Weiss 7.40): The following divide-and-conquer algorithm is proposed for finding
    the simultaneous maximum and minimum: If there is one item, it is the maximum
    and minimum, and if there are two items, then compare them, and in one
    comparison you can find the maximum and minimum. Otherwise, split the input
    into two halves, divided as evenly as possibly (if N is odd, one of the two
    halves will have one more element than the other). Recursively find the
    maximum and minimum of each half, and then in two additional comparisons
    produce the maximum and minimum for the entire problem.

Write the above function which will take in a vector and solve the problem,
    producing a vector of two elements, the min and max.

*/
#include <iostream>
#include <vector>
using namespace std;
void printVector(const vector<int>& input);

//assumes start at index 0 and sort the whole way through
vector<int> findMinAndMax(const vector<int>& input);

//driver function for above function
vector<int> findMinAndMax(const vector<int>& input, int start, int end);

int main()
{
    vector<int> input{3, 1, 5, 2, 8, 9, 3, 2, 9, 0, 3};
    vector<int> minMax = findMinAndMax(input);
    cout << "Input: ";
    printVector(input);
    cout << "(Min, Max): ";
    printVector(minMax);
   
    vector<int> input1{-100, -254, 5, 0, 0, 5, 524895, 524895, 1000000, -500, 50, 65};
    vector<int> minMax1 = findMinAndMax(input1);
    cout << "Input: ";
    printVector(input1);
    cout << "(Min, Max): ";
    printVector(minMax1);

    return 0;
}

vector<int> findMinAndMax(const vector<int>& input) {
    return findMinAndMax(input, 0, input.size() - 1);
}

vector<int> findMinAndMax(const vector<int>& input, int start, int end) {
    vector<int> output;
    if (end == start) {
        for (int i = 0; i < 2; i++) {
            output.push_back(input[start]);
        }
    }
    else if (end == start + 1) {
        if (input[start] < input[end]) {
            output.push_back(input[start]);
            output.push_back(input[end]);
        }
        else {
            output.push_back(input[end]);
            output.push_back(input[start]);
        }
    }
    else {
        vector<int> temp1 = findMinAndMax(input, start, (start + end) / 2);
        vector<int> temp2 = findMinAndMax(input, (start + end) / 2 + 1, end);
       
        if (temp1[0] < temp2[0])
            output.push_back(temp1[0]);
        else
            output.push_back(temp2[0]);
           
        if (temp1[1] > temp2[1])
            output.push_back(temp1[1]);
        else
            output.push_back(temp2[1]);
    }
    return output;
}
void printVector(const vector<int>& input) {
    cout << "(";
    for (int i = 0; i < input.size(); i++) {
        cout << input[i];
        if (i != input.size() - 1) cout << ", ";
    }
    cout << ")" << endl;
}
