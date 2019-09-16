#include <iostream>
using namespace std;

int findIndex(int arr[], int num, int start, int end, int &index) {

    if(start == end)
        return false;

    else {
        int mid = (start + end) / 2;
        if(arr[mid] == num) {
            index = mid;
            return true;
        }
        else if(arr[mid] > num) {
            if(arr[start] > num)
                return findIndex(arr, num, mid, end, index);
            else
                return findIndex(arr, num, start, mid, index);
        }
        else {
            if(arr[start] > num)
                return findIndex(arr, num, mid, end, index);
            else 
                return findIndex(arr, num, start, mid, index);
        }
    }

}

int main() {

    int arr[] = {13, 18, 25, 2, 8, 10};
    int start = 0, end = 5;
    int index;
    if(findIndex(arr, 8, start, end, index))
        cout << index << endl;
    else 
        cout << "no solution" << endl;

}

/*bool findIndex(int arr[], int size, int num, int &index) {

    int i = 0;

    if(arr[i] > num) {
        i = size - 1;
        while(i > 1) {
            if(arr[i] > num)
                i --;
            else if(arr[i] == num) {
                index = i;
                return true;
            }
            else 
                return false;
        }
        return false;
    }

    else if(arr[i] == num) {
        index = i;
        return true;
    }

    else {
        i = 1;
        while(i < size) {
            if(arr[i] < num)
                i ++;
            else if(arr[i] == num) {
                index = i;
                return true;
            }
            else 
                return false;
    
        return false;
    }

}

int main() {

    int arr[] = {13, 18, 25, 2, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int index;
    if(findIndex(arr, size, 8, index))
        cout << index << endl;
    else 
        cout << "no solution" << endl;

}*/