#include <iostream>

using namespace std;

int main() {

    int n, pairs, numWays;
    cin >> n;
    cin >> pairs;
    int a[pairs], b[pairs], diff[pairs];
    for(int i = 0; i < pairs; i++)
        cin >> a[i];
    cin >> pairs;
    for(int i = 0; i < pairs; i++)
        cin >> b[i];

    for(int j = 0; j < pairs; j++)
        diff[j] = abs(b[j] - a[j]);

    numWays = (n * (n + 1)) / 2;

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            if(i - diff[j] + 1 > 0) {

                numWays -= i - diff[j] + 1;

            }

        }

    }

}

int lower(int x, int y) {

    if(x < y)
        return x;

    else if(y < x)
        return y;

    else
        return 0;

}

int higher(int x, int y) {

    if(x < y)
        return y;

    else if(y < x)
        return x;

    else
        return 0;

}