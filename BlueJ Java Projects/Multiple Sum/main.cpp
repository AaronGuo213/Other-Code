#include <iostream>

using namespace std;

int main()
{
    double factor1;
    int x;
    double sumF1;
    double factor2;
    int y;
    double sumF2;
    double limit;
    double extraFactor;
    int z;
    double sumE;
    double sum;

    cout << "What is the first factor?" << endl;
    cin >> factor1;
    cout << "What is the second factor?" << endl;
    cin >> factor2;
    cout << "What is the limit of the numbers?" << endl;
    cin >> limit;

    extraFactor = factor1 * factor2;
    x = limit / factor1;
    y = limit / factor2;
    z = limit / extraFactor;

    sumF1 = ((factor1 * x) + factor1) * (x) / 2;
    sumF2 = ((factor2 * y) + factor2) * (y) / 2;
    sumE = ((extraFactor * z) + extraFactor) * (z) / 2;

    sum = sumF1 + sumF2 - sumE;

    cout << "Your sum is " << sum << "." << endl;
}

