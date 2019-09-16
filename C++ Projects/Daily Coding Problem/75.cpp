#include <iostream>
using namespace std;

int bestPath(int arr[], int start, int end, int threshhold) {

    int best = 0;
    int current;
    for(int i = start; i < end; i++) {

        if(arr[i] > threshhold) {
            current = 1 + bestPath(arr, i + 1, end, arr[i]);
            if(current > best)
                best = current;
        }

    }

    return best;

}

int main() {

    int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << bestPath(arr, 0, size, -1) << endl;

}