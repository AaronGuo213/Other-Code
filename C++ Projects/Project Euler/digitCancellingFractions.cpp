#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int numerator = 1, denominator = 1;
    float i1, i10, j1, j10;
    for(float i = 10; i < 100; i++) {
        for(float j = i + 1; j < 100; j++) {

            i1 = int(i) % 10;
            i10 = int(i / 10);
            j1 = int(j) % 10;
            j10 = int(j / 10);

            if(i1 == j10 && j1 != 0 && i10 / j1 == i / j) {
                numerator *= i10;
                denominator *= j1;
            }
            else if(i10 == j1 && j10 != 0 && i1 / j10 == i / j) {
                numerator *= i1;
                denominator *= j10;
            }

        }
    }
    denominator /= __gcd(denominator, numerator);
    cout << "When all of the fractions made up of two digit numbers that can cancel digits to give a simpified fraction are multiplied and reduced, the denominator is " << denominator << ".\n";

    return 0;

}