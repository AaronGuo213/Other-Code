#include <stdio.h>

int main() {

    //int primes[100000];
    //primes[0] = 2;
    int numPrimes = 1;
    int limit = 100000000;
    
    for(int i = 3; i < limit; i+=2) {
        int isPrime = 1;
        /*for(int j = 0; primes[j] * primes[j] <= i; j++) {
            if(i % primes[j] == 0) {
                isPrime = 0;
                break;
            }
        }
        if(isPrime) {
            primes[numPrimes] = i;
            numPrimes ++;
        }*/
        for(int j = 3; j * j <= i; j++) {
            if(i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if(isPrime)
            numPrimes ++;
    }

    printf("The are %d primes below %d.\n", numPrimes, limit);

}