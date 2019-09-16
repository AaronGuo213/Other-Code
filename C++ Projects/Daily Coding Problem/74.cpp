#include <iostream>
#include <math.h>
using namespace std;

int numInMultTable(int n, int x) {

    int limit = sqrt(x);
    int count = 0;
    if(sqrt(x) == int(sqrt(x)))
        count --;

    for(int i = 1; i <= limit; i++) {
        if(x % i == 0 && x / i <= n)
            count += 2;
    }

    return count;

}

int main() {

    int n = 8, x = 16;
    cout << numInMultTable(n, x);

}