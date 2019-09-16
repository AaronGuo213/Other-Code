#include <iostream>
using namespace std;

int prime[10001];
int primes = 2;

bool isPrime(int num) {

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
    prime[1] = 3;
    int num = 4, n = 10001;
    while(primes <= n) {
        if(isPrime(num)) {
            prime[primes] = num;
            primes ++;
        }
        num++;
    }
    cout << "The " << n << "th prime is " << prime[n - 1] << ".\n";

    return 0;

}