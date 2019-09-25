#include <iostream>
using namespace std;

void findPrintSet(int arr[], int size, int K) {

    int sum, i, j;
    for(i = 0; i < size; i++) {

        sum = 0;
        for(j = i; sum < K; j++) {

            sum += arr[j];

        }

        if(sum == K)
            break;

    }

    for(int a = i; a < j; a++)
        cout << arr[a] << endl;

}

int main() {

    int arr[] = {1, 2, 2, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int K = 9;
    findPrintSet(arr, size, K);

}