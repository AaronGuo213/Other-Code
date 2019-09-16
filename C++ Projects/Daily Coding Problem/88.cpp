#include <iostream>
using namespace std;

int divisionButBad(int dividend, int divisor) { //divides without multiplication, division, or modulus

    int quotient = 0;
    for(int sum = divisor; sum <= dividend; quotient++) { //repeats adding until the sum is greater than dividend
        sum += divisor;
    }

    return quotient;

}

int main() {

    cout << divisionButBad(6, 6);

}