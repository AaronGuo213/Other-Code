#include <iostream>
#include <string>
using namespace std;

const int m = 2, n = 4;

void printPossibilities(char digitMap[m][n], string num) { //only works for this situation

    for(int i = 1; i < n; i++) {

        for(int j = 1; j < n; j++) { //nested for loop to print all combinations

            cout << digitMap[0][i] << digitMap[1][j] << endl;

        }

    }

}

int main() {

    char digitMap[m][n] = {{'2', 'a', 'b', 'c'}, {'3', 'd', 'e', 'f'}};
    printPossibilities(digitMap, "23");

}