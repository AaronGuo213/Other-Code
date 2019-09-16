#include <iostream>
using namespace std;

bool canSum(int arr[], int start, int size, int goal) {

    bool tempAns = false;
    for(int i = start; i < size && !tempAns; i++) {

        if(goal - arr[i] == 0)
            return true;

        else if(goal - arr[i] > 0)
            tempAns = canSum(arr, i + 1, size, goal - arr[i]);

    }
    return tempAns;

}

bool canSplit(int arr[], int size) {

    int sum = 0;
    for(int i = 0; i < size; i++)
        sum += arr[i];
    if(sum % 2 == 1)
        return false;
    else if(canSum(arr, 0, size, sum / 2))
        return true;
    return false;

}

int main() {

    int arr[] = {15, 5, 20, 10, 35, 15, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << canSplit(arr, size);

}