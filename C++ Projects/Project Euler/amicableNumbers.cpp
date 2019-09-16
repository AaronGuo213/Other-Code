#include <iostream>
#include <cmath>
using namespace std;

int d(int num) { //sum of factors less than the inputed number

    int sum = 1, i;
    for(i = 2; i * i <= num; i++) {
        if(num % i == 0) {
            sum += i + num / i;
        }
        if(i * i == num)
            sum -= i;
    }

    return sum;

}

int main() {

    int sum = 0;
    for(int i = 1; i < 10000; i++) {
        if(d(d(i)) == i && d(i) != i)
            sum += i; 
    }

    cout << "The sum of all the amicable numbers below 10,000 is " << sum << ".\n";

}