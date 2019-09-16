#include <iostream>
#include <cmath>
using namespace std;

int nextPrime(int prime) {

    bool isPrime = false;
    while(!isPrime) {

        isPrime = true;
        prime++;
        for(int i = 2; i <= pow(prime, 0.5); i++) {
            if(prime % i == 0)
                isPrime = false;
        }

    }

    return prime;

}

int main() {

    long long num = 600851475143;
    long long number = num;
    long prime = 2;
    while(num != 1) {

        if(num % prime != 0)
            prime = nextPrime(prime);

        else
            num /= prime;

    }

    cout << "The largest prime factor of " << number << " is " << prime << ".\n";

}