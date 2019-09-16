#include <iostream>
using namespace std;

int sumOfNonAdjacent(int arr[], int size) {

    int previous = 0, greatest = 0, current;
    for(int i = 0; i < size; i++) {
        current = greatest + arr[i];
        greatest = previous >= greatest ? previous : greatest;
        previous = current;
    }
    greatest = previous >= greatest ? previous : greatest;

    return greatest;

}

int main() {

    int arr[] = {2, 4, 5, -1, 6, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int greatestSum = sumOfNonAdjacent(arr, size);
    cout << "The greatest sum of non-adjacent numbers in the set is " << greatestSum << ".\n";

}