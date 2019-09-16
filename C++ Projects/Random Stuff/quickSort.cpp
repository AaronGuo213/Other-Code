#include <iostream>
using namespace std;

void swap(int *a, int *b) {

    *a ^= *b;
    *b ^= *a;
    *a ^= *b;

}

int place(int array[], int low, int high) {

    if(low >= high)
        return 0;

    else {

        int i = low;
        for(int j = low; j < high; j++) {

            if(array[j] <= array[high]) {
                swap(array[i], array[j]);
                i++;
            }

        }
        swap(array[i], array[high]);

        return i;

    }

}

void quickSort(int array[], int low, int high) {

    if(low < high) {

        int split = place(array, low, high);

        quickSort(array, low, split - 1);
        quickSort(array, split + 1, high);

    }

}

int main() {

    int array[] = {10, 7, 8, 9, 1, 5};
    quickSort(array, 0, 6);
    for(int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
        cout << array[i] << " | ";

}