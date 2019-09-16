#include <iostream>
using namespace std;

int main() {

    int prices[6] = {9, 11, 8, 5, 7, 10};
    int last = sizeof(prices) / sizeof(prices[0]);
    int low = prices[last - 2], high = prices[last - 1];
    int diff = high - low;
    for(int i = last - 2; i >= 0; i--) {

        if(prices[i] > high) {
            high = prices[i];
            low = high;
        }

        else if(prices[i] < low) {
            low = prices[i];
            if(diff < high - low)
                diff = high - low;
        }

    }

    cout << diff << endl;
    return 0;

}