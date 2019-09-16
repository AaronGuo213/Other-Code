#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPandigital(long long num) {//works if the number has all of the digits from 1-9 used once

    int digits = 0;
    int copy;
    while(num > 0) {
        copy = digits;
        digits = digits | 1 << (int)(num % 10) - 1;
        
        if(digits == copy)
            return false;
        
        num /= 10;
    }

    return (digits == (1 << 9) - 1);

}

long long combine(long long a, long long b) {

    long long c = b;
    do{
        c /= 10;
        a *= 10;
    }while(c > 0);

    return a + b;

}

int main() {

    vector<int> products;
    int product;
    long sum = 0;
    for(int i = 1; i < 100; i++) {
        for(int j = 100; i * j < 100000; j++) {
            product = i * j;
            if(isPandigital(combine(i, combine(j, product))) && find(products.begin(), products.end(), product) == products.end()) {
                sum += product;
                products.push_back(product);
                cout << i << " | " << j << " | " << product << endl;
            }
        }
    }

    cout << "The sum of all of the numbers whose multiplicand, multiplier, and product digits are pandigital (1-9 used exactly once) is " << sum << ".\n";

}