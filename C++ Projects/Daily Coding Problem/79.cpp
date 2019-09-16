#include <iostream>
using namespace std;

bool canBeNonDecresing(int arr[], int size) {

    bool canChange = true;
    for(int i = 0; i < size - 1; i++) { //comparing every element and the next

        if(arr[i] > arr[i + 1]) {
            if(!canChange) //the single change has already been used
                return false;

            canChange = false; //the single change has been used

            if(i + 2 < size) { //comparing the ith element with the second one after it
                if(arr[i + 2] < arr[i + 1]) //if the i + 2 element is lower than the element i + 1, one change cannot fix everything
                    return false;

                else //if the i + 2 element is inclusively between the i + 1 element and the ith element, the ith element can change to fix,
                    //if the i + 2 element is greater than the ith element, the i + 1 element can change to fix
                    i++;
            }
        }

    }

    return true;

}

int main() {

    int arr[] = {1, 4, 3, 5, 6, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << canBeNonDecresing(arr, size);

}