#include <iostream>
using namespace std;

int primes = 1;
long prime[2000000];

bool isPrime(long num) {

    if(num <= 1)
        return 0;

    else {
        for(int i = 0; prime[i] * prime[i] <= num; i++) {
            if(num % prime[i] == 0)
                return 0;
        }
    }

    return 1;

}

int main() {

    prime[0] = 2;
    long sum = 2;
    for(int i = 3; i < 2000000; i += 2) {
        if(isPrime(i)) {
            sum += i;
            prime[primes] = i;
            primes ++;
        }
    }
    cout << "The sum of all of the primes less than 2000000 is " << sum << ".\n";
    
    return 0;

}