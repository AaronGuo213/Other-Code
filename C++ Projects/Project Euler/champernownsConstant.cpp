#include <iostream>
using namespace std;

int powerOfTen(int n) {

    int num = 1;
    for(int i = 0; i < n; i++)
        num *= 10;

    return num;

}

int findDigit(int num, int digits, int place) { //digit 1 is the most significant digit

    place = digits - place;
    for(int i = 0; i < place; i++) {
        num /= 10;
    }
    return num % 10;

}

int d(int num) {

    int i, j;
    for(i = 0; num >= 9 * powerOfTen(i) * (i + 1); i++) {
        num -= 9 * powerOfTen(i) * (i + 1);
    }

    for(j = 0; num > (i + 1); j++) {
        num -= (i + 1);
    }

    return findDigit(powerOfTen(i) + j, i + 1, num);

}

int main() {

    int answer = d(1) * d(10) * d(100) * d(1000) * d(10000) * d(100000) * d(1000000);
    cout << "The product of d(1) * d(10) * d(100) * d(1000) * d(10000) * d(100000) * d(1000000) is equal to " << answer << ".\n";

}