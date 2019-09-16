/*Given an array of integers, find the combination of integers that
give the maximum sum.*/

#include <iostream>

using namespace std;

int main() {

    int n, victim, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {

        cin >> victim;
        if(victim > 0)
            sum += victim;

    }

    cout << sum;

}