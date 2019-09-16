#include <iostream>
using namespace std;

//Passes a 2D array without using global variables

void printMatrix(int *array, int rows, int cols) {

    for(int i = 0; i < rows; i++) { //counter for rows
        
        for(int j = 0; j < cols; j++) { //counter for columns

            cout << *(array+i*cols+j) << ", ";

        }

        cout << endl; //start a new line at the end of a row

    }

}

int main() {

    int array[][2] = {{1, 2}, {3, 4}};
    printMatrix(*array, 2, 2); //uses a pointer

}