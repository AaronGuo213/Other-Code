#include <iostream>
#include <cmath>
using namespace std;

int sumOfSquares(int num) {

    return num * (num + 1) * (2 * num + 1) / 6;

}

int squareOfSum(int num) {

    return num * (num + 1) / 2 * num * (num + 1) / 2;

}

int main() {

    int num = 100;
    cout << "The sum square difference from 1 to " << num << " is " << squareOfSum(num) - sumOfSquares(num) << ".\n";
    return 0;

}