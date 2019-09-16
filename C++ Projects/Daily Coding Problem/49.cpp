#include <iostream>
using namespace std;

int main() {

    int arr[] = {34, -50, 42, 14, -5, 86};
    int currentMax = arr[0], totalMax = arr[0];
    for(int i = 1; i < sizeof(arr) / sizeof(arr[0]); i++) {
        currentMax = arr[i] > arr[i] + currentMax ? arr[i] : arr[i] + currentMax;
        totalMax = currentMax > totalMax ? currentMax : totalMax;
    }
    if(totalMax < 0)
        totalMax = 0;
    cout << totalMax;

}