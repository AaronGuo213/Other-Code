#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int num) {

    if(num <= 1)
        return 0;

    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0)
            return 0;
    }

    return 1;

}

int consecutivePrimes(int a, int b) {

    bool compositeFound = false;
    int output, primes = 0;
    for(int x = 0; !compositeFound; x++) {
        output = x * x + a * x + b;
        if(!isPrime(output))
            compositeFound = true;
        else
            primes ++;
    }

    return primes;

}

vector<int> findPrimes(int limit) {

    vector<int> prime = {2};
    bool composite = false;
    for(int i = 3; i < limit; i++) {

        composite = false;
        for(int j = 0; prime[j] * prime[j] <= i; j++) {
            if(i % prime[j] == 0)
                composite = true;
        }
        if(!composite)
            prime.push_back(i);

    }

    return prime;

}

int main() {

    vector<int> prime = findPrimes(1000);
    int mostPrimes = 0, aID, bID, suspectPrimes;
    int separator = 0; //the function can factor to x(x + a) + b, so if x + a = b, that is where the primes must
    //end by, so we can add a separator to make sure a and b are never closer than the most primes so far
    for(int b = 0; b < prime.size(); b++) {

        for(int a = -999; a <= 1000; a+=2) {

            if(abs(prime[b] - a) <= separator)
                a += 2;
            suspectPrimes = consecutivePrimes(a, prime[b]);
            if(suspectPrimes > mostPrimes) {
                aID = a;
                bID = prime[b];
                separator = mostPrimes = suspectPrimes;
            }

        }

    }

    cout << aID << " | " << bID << " | " << mostPrimes;

}