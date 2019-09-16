/*Given an array of integers, there is a sliding filter of size s, gliding from
the left to right. At each time, only the s numbers in the filter are
considered for computation. At each iteration, move the filter 1 step to the
right. Find the minimum at each iteration and return all the minimums as
an array of integers.*/

#include <iostream>

using namespace std;

int main() {

    int smplSize, filterSize, filters, min;
    
    cin >> smplSize;
    int input[smplSize];

    for(int i = 0; i < smplSize; i++) {
        
        cin >> input[i];

    }
    cin >> filterSize;
    filters = smplSize - filterSize + 1;
    int output[filters];

    for(int i = 0; i < filters; i++) {

        min = input[i];

        for(int j = 1; j < filterSize; j++) {

            if(input[i + j] < min) 
                min = input[i + j];

        }

        output[i] = min;

    }

    cout << "{" << output[0] << " ";

    for(int i = 1; i < filters - 1; i++) {

        cout << output[i] << " ";

    }

    cout << output[filters - 1] << "}\n";

}