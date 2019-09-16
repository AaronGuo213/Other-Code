#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int sum = 0;
    for(int i = 2; i < 400000; i++) { //400000 is greater than 6 * 9^5;

        int num = i, sumOfPowers = 0, digit;
        while(num > 0) {

            digit = num % 10;
            sumOfPowers += pow(digit, 5);
            num /= 10;

        }
        if(sumOfPowers == i)
            sum += i;

    }
    cout << "The sum of all of the numbers whose fifth power of their digits sum to itself is " << sum << ".\n";
    
    return 1;

}