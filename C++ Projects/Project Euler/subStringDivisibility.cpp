#include <iostream>
#include <cmath>
using namespace std;

int get3DigitNum(long number, int mostSigDigit, int digits) {

    int ones = mostSigDigit + 2;
    for(int i = 0; i < digits - ones; i++)
        number /= 10;
    return number % 1000;

}

bool hasProperty(long num) {

    int primes[9] = {0, 0, 2, 3, 5, 7, 11, 13, 17};
    for(int i = 2; i <= 8; i++) {
        if(get3DigitNum(num, i, 10) % primes[i])
            return false;
    }
    return true;

}

int perm[10] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
void swap(int a, int b) {

    int c = perm[a];
    perm[a] = perm[b];
    perm[b] = c;

}

int main() {

    long sum = 0;
    int count = 3265920;
    while(count > 1) {
        int N = 10;
        int i = N - 1;  
        while (perm[i - 1] >= perm[i])
            i --;
        int j = N;
        while (perm[j - 1] <= perm[i - 1])
            j --;
        swap(i - 1, j - 1);
        i++;
        j = N;
        while (i < j) {
            swap(i - 1, j - 1);
            i++;
            j--;
        }
        long num = 0;
        if(!(perm[4] % 2) && (perm[6] == 5 || perm[6] == 0)) {
            if(hasProperty(num))
                sum += num;
        }
    }
    cout << sum;

}