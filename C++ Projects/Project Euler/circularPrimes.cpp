#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getPrimes(int limit) {

    vector<int> primes = {2};
    bool isPrime;
    for(int i = 3; i < limit; i++) {
        isPrime = true;
        for(int j = 0; primes[j] * primes[j] <= i; j++) {
            if(i % primes[j] == 0)
                isPrime = false;
        }
        if(isPrime == true)
            primes.push_back(i);
    }

    return primes;

}

int rotate(int num, int digits) {

    int ones = num % 10;
    num /= 10;
    while(digits > 1) {
        ones *= 10;
        digits --;
    }

    return ones + num;

}

bool has2or5(int num) {

    if(num == 2 || num == 5)
        return false;

    while(num > 0) {
        if(num % 10 == 2 || num % 10 == 5)
            return true;
        else
            num /= 10;
    }

    return false;

}

int main() {//THIS IS MEGA SLOW

    vector<int> prime = getPrimes(1000000);
    int count = 0;
    for(int i = 0; i < prime.size(); i++) {
        
        if(!has2or5(prime[i])) {
            int copy = prime[i];
            int digits = 0;
            while(copy > 0) {
                digits ++;
                copy /= 10;
            }

            bool isCircularPrime = true;
            int suspect = prime[i];
            for(int j = 0; j < digits - 1; j++) {
                suspect = rotate(suspect, digits);
                if(find(prime.begin(), prime.end(), suspect) == prime.end()) {
                    isCircularPrime = false;
                    break;
                }
            }
            if(isCircularPrime)
                count ++;
        }

    }

    cout << "The number of primes that are circular primes is " << count << "\n";

}