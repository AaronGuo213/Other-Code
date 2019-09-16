/*Given a list of points described by their (x,y) coordinates on a two
dimensional plane, construct a square surrounding at least a given
number of points within the area enclosed. That area should be
minimal and the square must meet the following conditions:
The x-coordinates and y-coordinates of the points should be
integers.
The sides of the square should be parallel to coordinate axes.
At least k of the given n points should lie strictly inside the square
drawn. Strictly inside means that they cannot lie on a side of the
square.*/

#include <iostream>

using namespace std;

int main() {

    int n, k;
    cin >> n;
    int x[n], y[n];
    for(int i = 0; i < n; i++)
        cin >>x[i];
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >>y[i];
    cin >> k;
    k = n - k;

    int yLow = y[0], yHigh = y[0], yDiff;
    int xLow = x[0], xHigh = x[0], xDiff;
    int top = 0, left = 0, right = 0, bottom = 0;
    int area;

    for(int i = 1; i < n; i++) {

        if(y[i] > yHigh)
            yHigh = y[i];
        if(y[i] < yLow)
            yLow = y[i];

        if(x[i] > xHigh)
            xHigh = x[i];
        if(x[i] < xLow)
            xLow = x[i];

    }

    yDiff = yHigh - yLow;
    xDiff = xHigh - xLow;

    int l = k, m = k;

    if(k > 0) {

        for(int i = 0; i < n; i++) {

            if(x[i] == xLow)
                k--;
            else if(y[i] == yLow)
                k--;

        }

        for(int i = 0; i < n; i++) {

            if(x[i] == xHigh)
                l--;
            else if(y[i] == yHigh)
                l--;

        }

        if(l + k >= m) {
            yDiff -= 2;
            xDiff -= 2;
        }

        else if(l > 0 || k > 0) {
            yDiff --;
            xDiff --;
        }

    }

    area = yDiff > xDiff ? (yDiff + 2) * (yDiff + 2) : (xDiff + 2) * (xDiff + 2);

    cout << area;

}