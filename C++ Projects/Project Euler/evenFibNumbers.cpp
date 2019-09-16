#include <iostream>
using namespace std;

int main() {

    unsigned int fib1 = 1, fib2 = 1, suspect = 0, sum = 0;
    while(suspect < 4000000) {

        suspect = fib1 + fib2;
        fib1 = fib2;
        fib2 = suspect;

        if(suspect % 2 == 0)
            sum += suspect;

    }

    cout << sum;

}