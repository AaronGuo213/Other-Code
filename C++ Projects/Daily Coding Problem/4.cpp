#include <iostream>
using namespace std;

void swap(int *a, int *b) {

    int holder = *a;
    *a = *b;
    *b = holder;

}

int separate(int n[], int size) {

    int j = 0;

    for(int i = 0; i < size; i++) {

        if(n[i] <= 0) {
            swap(&n[i], &n[j]);
            j++;
        }

    }

    return j;

}

int findSmallNum(int n[], int size) {

    for(int i = 0; i < size; i++) {

        if(abs(n[i]) - 1 < size && n[abs(n[i]) - 1] > 0)
            n[abs(n[i]) - 1] *= -1;

    }

    for(int i = 0; i < size; i++) {

        if(n[i] > 0)
            return i + 1;

    }

    return size + 1;

}

int main() {

    int n[] = {1, 3, 4, 2};
    int size = sizeof(n) / sizeof(n[0]);
    int shift = separate(n, size);
    int smallNum = findSmallNum(n + shift, size - shift);
    cout << "The smallest positive number not in the array is " << smallNum << endl;

}