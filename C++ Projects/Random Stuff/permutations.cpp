#include <iostream>
using namespace std;

//This program is faster, but a simpler program can be found in Daily Coding Problem, 95.cpp

void swap(int *i, int *j) {

    *i ^= *j;
    *j ^= *i;
    *i ^= *j;

}

int split(int num[], int low, int high) {

    if(low >= high)
        return 0;

    else {
        int i = low;
        for(int j = low; j < high; j++) {
            if(num[j] <= num[high]) {
                swap(num[i], num[j]);
                i ++;
            }
        }
        swap(num[i], num[high]);
        return i;
    }

}

int splitReverse(int num[], int low, int high) {

    if(low >= high)
        return 0;

    else {
        int i = low;
        for(int j = low; j < high; j++) {
            if(num[j] >= num[high]) {
                swap(num[i], num[j]);
                i ++;
            }
        }
        swap(num[i], num[high]);
        return i;
    }

}

void sort(int num[], int low, int high) {

    if(low < high) {
        int divide;
        divide = split(num, low, high);
        sort(num, low, divide - 1);
        sort(num, divide + 1, high);
    }

}

void sortReverse(int num[], int low, int high) {

    if(low < high) {
        int divide;
        divide = splitReverse(num, low, high);
        sortReverse(num, low, divide - 1);
        sortReverse(num, divide + 1, high);
    }

}

bool nextPerm(int perm[], int elements) {

    bool switchFound = false;
    int suspect, switcher, switchID, i;
    for(i = elements - 2; !switchFound; i--) {
        if(perm[i] < perm[i + 1]) {
            switchFound = true;
            suspect = perm[i];
            switcher = suspect + 100;
            for(int j = i; j < elements; j++) {
                if(perm[j] > suspect && perm[j] < switcher) {
                    switcher = perm[j];
                    switchID = j;
                }
            }
            swap(perm[i], perm[switchID]);
            break;
        }
    }

    if(!switchFound)
        return 0;

    else {    
        sort(perm, i + 1, elements - 1);
        return 1;
    }

}

bool prevPerm(int perm[], int elements) {

    bool switchFound = false;
    int suspect, switcher, switchID, i;
    for(i = elements - 2; !switchFound; i--) {
        if(perm[i] > perm[i + 1]) {
            switchFound = true;
            suspect = perm[i];
            switcher = suspect - 100;
            for(int j = i; j < elements; j++) {
                if(perm[j] < suspect && perm[j] > switcher) {
                    switcher = perm[j];
                    switchID = j;
                }
            }
            swap(perm[i], perm[switchID]);
            break;
        }
    }

    if(!switchFound)
        return 0;

    else {    
        sortReverse(perm, i + 1, elements - 1);
        return 1;
    }

}

int main() {

    int perm[5] = {1, 2, 3, 4, 5};
    do{
        for(int i = 0; i < 5; i++) {
            cout << perm[i] << ", ";
        }
        cout << endl;
    }while(nextPerm(perm, 5));

}