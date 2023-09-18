//
//  main.cpp
//  examprep2
//
//  Created by Max Grove on 9/17/23.
//

#include <iostream>
#include <vector>
using namespace std;

int palindromeDistance(int* arr, int n);
void testPalindromeDistance();


int main() {
    testPalindromeDistance();
    
    
    int studentIDTemp, gradeTemp, maxGrade;
    vector<int> studentIDs;
    vector<int> grades;
    
    cout << "Please enter a non-empty sequence of lines." << endl;
    cout << "Each line should have a student ID and their grade (0-100), separated by a space." << endl;
    cout << "To indicate the end of the input, enter -1 as a student ID:" << endl;
    cin >> studentIDTemp;
    while (studentIDTemp != -1) {
        cin >> gradeTemp;
        studentIDs.push_back(studentIDTemp);
        grades.push_back(gradeTemp);
        cin >> studentIDTemp;
    }
    maxGrade = grades[0];
    for (int i = 1; i < studentIDs.size(); i++) {
        if (grades[i] > maxGrade) maxGrade = grades[i];
    }
    cout << "The highest grade is " << maxGrade << "." << endl;
    cout << "The students with grade " << maxGrade << " are:";
    for (int i = 0; i < studentIDs.size(); i++) {
        if (grades[i] == maxGrade) {
            cout << " " << studentIDs[i];
        }
    }
    cout << "." << endl;
    return 0;
}

int palindromeDistance(int* arr, int n) {
    if (n <= 1) return 0;
    if (n == 2) return (*arr != *(arr + n - 1));
    else return (*arr != *(arr + n - 1)) + palindromeDistance(arr + 1, n - 2);
    return 0;
}

void testPalindromeDistance() {
    int *test1 = new int[6] {1, 2, 3, 3, 2, 1}; //palDist = 0
    int *test2 = new int[6] {1, 2, 4, 3, 2, 1}; //palDist = 1
    int *test3 = new int[2] {1, 2}; //palDist = 1
    int *test4 = new int[2] {1, 1}; //palDist = 0
    int *test5 = new int[10] {1, 2, 3, 4, 5, 5, 4, 3, 2, 1}; //palDist = 0
    int *test6 = new int[10] {1, 2, 5, 8, 5, 5, 4, 3, 2, 1}; //palDist = 2
    
    cout << "Should be 0: " << palindromeDistance(test1, 6) << endl;
    cout << "Should be 1: " << palindromeDistance(test2, 6) << endl;
    cout << "Should be 1: " << palindromeDistance(test3, 2) << endl;
    cout << "Should be 0: " << palindromeDistance(test4, 2) << endl;
    cout << "Should be 0: " << palindromeDistance(test5, 10) << endl;
    cout << "Should be 2: " << palindromeDistance(test6, 10) << endl;
    
    delete [] test1;
    delete [] test2;
    delete [] test3;
    delete [] test4;
    delete [] test5;
    delete [] test6;
}
