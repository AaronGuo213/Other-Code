#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {

    if(num <= 1)
        return false;
    if(num == 2)
        return true;

    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0)
            return false;
    }

    return true;

}

bool isTruncatableLeft(int num) {

    if(num < 10)
        return isPrime(num);

    return isPrime(num) && isTruncatableLeft(num / 10);

}

bool isTruncatableRight(int num, int digits) {

    if(digits == 1)
        return isPrime(num);

    digits --;
    int powTen = 1;
    for(int i = digits; i > 0; i--)
        powTen *= 10;
    return isPrime(num) && isTruncatableRight(num % powTen, digits);

}

int main() {

    int count = 0;
    int sum = 0;
    int prime = 7;
    while(count < 11) {
        for(int i = prime + 2; true; i+=2) {
            if(isPrime(i)) {
                prime = i;
                break;
            }
        }
        int digits = 0, copy = prime;
        while(copy > 0) {
            digits ++;
            copy /= 10;
        }
        if(isTruncatableLeft(prime) && isTruncatableRight(prime, digits)) {
            count ++;
            sum += prime;
        }
    }
    cout << "The sum of all of the truncatable primes is " << sum << ".\n";

}