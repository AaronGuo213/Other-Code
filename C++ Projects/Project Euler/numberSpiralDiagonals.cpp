#include <iostream>
using namespace std;

int main() {

    long long increment = 2, incCount = 4;
    long long sum = 0;
    long long corner = 1;
    while(corner <= 1001 * 1001) {

        if(incCount == 0) {
            incCount = 4;
            increment += 2;
        }
        incCount --;

        sum += corner;
        corner += increment;

    }

    cout << "The sum of the diagonals in a 1001 by 1001 spiral is " << sum << ".\n";

}