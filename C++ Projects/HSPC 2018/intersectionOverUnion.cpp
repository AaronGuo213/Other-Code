/*Find the intersection and the union of the two rectangles in a 2D plane.
Each rectangle is defined by its bottom left corner and top right corner as
shown in the figure.
The intersection is the overlapping area of the 2 rectangles.
The Union is the total covered area of the 2 rectangles.*/

#include <iostream>

using namespace std;

int main() {

    int a, b, c, d, e, f, g, h;
    int shared, total;
    int A, B, C, D;

    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> e;
    cin >> f;
    cin >> g;
    cin >> h;

    if(e > c || f > d || g < a || h < b)
        shared = 0;

    if(e <= a)
        A = a;

    else
        A = e;

    if(f <= b)
        B = b;

    else
        B = f;

    if(g >= c)
        C = c;

    else
        C = g;

    if(h >= d)
        D = d;

    else
        D = h;

    shared = abs((C - A) * (D - B));
    total = abs((c - a) * (d - b) + (g - e) * (h - f) - shared);

    cout << shared << endl << total;

}