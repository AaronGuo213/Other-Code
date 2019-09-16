#include <stdio.h>
#include <math.h>

int isPrime(int num) {

    if(num <= 1)
        return 0;

    for(int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0)
            return 0;
    }

    return 1;

}

int main() {

    int limit = 100000, primes = 0;
    for(int i = 1; i <= limit; i+=2) {
        if(isPrime(i)) {
            primes ++;
            printf("%d is prime.\n", i);
        }
        else
            printf("%d is not prime.\n", i);
    }

    printf("There are %d primes less than or equal to %d.\n", primes, limit);

}