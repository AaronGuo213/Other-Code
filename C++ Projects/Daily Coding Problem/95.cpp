#include <iostream>
using namespace std;

void swap(int perm[], int a, int b) { //swaps the values of two locations in an array

    int hold = perm[a];
    perm[a] = perm[b];
    perm[b] = hold;

}

void sort(int perm[], int begin, int end) { //sorts a part of an array from least to greatest

    if(begin != end) {

        int lowestPlace = begin;
        for(int i = begin + 1; i <= end; i++) //finds lowest value in the part of the array
            if(perm[lowestPlace] > perm[i])
                lowestPlace = i;

        swap(perm, lowestPlace, begin); //puts the lowest value on the first place
        sort(perm, begin + 1, end); //then runs the algorithm again for the rest of the array

    }

}

void nextPerm(int perm[], int size) { //returns the next permutation of a given permutation

    int i, j;
    for(i = size - 1; perm[i] < perm[i - 1]; i--) //finds the place to be swapped
        ; //(the rightmost place with a value greater than the place to the left)
    i --;

    int lowestSwitch = i + 1; //adjusts i
    for(j = i + 1; j < size; j++) { //finds the value left of i that is closest but greater than the value at i
        if(perm[j] < perm[lowestSwitch] && perm[j] > perm[i])
            lowestSwitch = j;
    }

    swap(perm, i, lowestSwitch); //swaps the two values
    sort(perm, i + 1, size - 1); //organizes the rest of the values

}

int main() {

    int perm[] = {1, 3, 5, 4, 2};
    int size = sizeof(perm) / sizeof(perm[0]);
    nextPerm(perm, size);
    for(int i = 0; i < size; i++)
        cout << perm[i] << endl;

}