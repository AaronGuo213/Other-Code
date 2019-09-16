#include <iostream>
#include <cmath>
using namespace std;

int perfectNum(int n) { //works for n < 100

    int adder = 0;
    for(int i = 1; i <= n; i++) {

        if(i / 10 + i % 10 > 10)
            adder ++;

    }
    n += adder;

    while(n / 10 + n % 10 > 10)
        n ++;

    return n * 10 + (10 - (n / 10 + n % 10));

}

int main() {

    cout << perfectNum(80);

}