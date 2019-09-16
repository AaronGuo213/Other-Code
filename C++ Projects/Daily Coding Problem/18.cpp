#include <iostream>
#include <deque>
using namespace std;

//Basically, we have this thing called a deque which is a vector that can push and pop front.
//A number in a window is only useful if all the numbers to the right of it are less than it.
//So we first create a queue of which places in the array are useful.
//We then slide across, removing all of the passed queues and removing queues which the new input is greater than.
//We continuously cout the leftmost value because it is the greatest.
//YAYAYAYAYAYAYAY!!!!!!!!!!!!!!!!!!!!!
void printSlidingMax(int arr[], int n, int k) {

    deque<int> queue;
    int i;
    for(i = 0; i < k; i++) {
        while(!queue.empty() && arr[i] >= arr[queue.back()])
            queue.pop_back();
        queue.push_back(i);
    }
    cout << "{";

    for(; i < n; i++) {

        cout << arr[queue.front()] << ", ";
        if(!queue.empty() && queue.front() <= i - k)
            queue.pop_front();

        while(!queue.empty() && arr[queue.back()] <= arr[i])
            queue.pop_back();

        queue.push_back(i);

    }

    cout << arr[queue.front()] << "}\n";

}

int main() {

    int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printSlidingMax(arr, n, k);

}