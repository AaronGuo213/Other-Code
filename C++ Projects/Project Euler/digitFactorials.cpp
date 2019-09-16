#include <iostream>
using namespace std;

int factorial(int num) {//you could also make an array caching the factorials, since you only need digits 0-9

    if(num <= 1)
        return 1;

    else
        return num * factorial(num - 1);

}

int main() {

    int digit, copy, totalSum = 0;
    for(int i = 3; i < 2500000; i++) {

        int factSum = 0;
        copy = i;
        while(copy > 0) {
            digit = copy % 10;
            copy /= 10;
            factSum += factorial(digit);
        }

        if(factSum == i)
            totalSum += i;

    }

    cout << totalSum;

}