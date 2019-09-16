#include <iostream>
using namespace std;

bool isPandigital(long num) {

    int digit;
    int helper = 0, copy;
    while(num > 0) {
        digit = int(num % 10);
        copy = helper;
        helper |= 1 << (digit - 1);
        if(copy == helper)
            return false;
        num /= 10;
    }

    return helper == 511;

}

int numDigits(int num) {

    int digits = 0;
    while(num > 0) {
        digits ++;
        num /= 10;
    }

    return digits;

}

long combine(int a, int b) {

    int c = b;
    while(c > 0) {
        a *= 10;
        c /= 10;
    }

    return a + b;

}

int main() {

    long longestPandigital = 0;
    for(int i = 1; i < 10000; i++) {
        int digits = numDigits(i);
        long combinedProducts = i;
        for(int j = 2; j <= 9 / digits; j++) {
            combinedProducts = combine(combinedProducts, i * j);
        }
        if(isPandigital(combinedProducts) && combinedProducts > longestPandigital)
            longestPandigital = combinedProducts;
    }
    cout << "The greatest 1-9 pandigital number made from combining a number and its multiples is " << longestPandigital << ".\n";

}