#include <iostream>
using namespace std;

int memo[1000000];

int collatz(unsigned long num) {

    int result = 0;

    if(num == 1)
        return 1;

    else if(num < 1000000 && memo[num - 1] != 0)
        result = memo[num - 1];

    else if(num % 2 == 0) {
        result = 1 + collatz(num / 2);
    }

    else if(num % 2 == 1) {
        result = 1 + collatz((3 * num) + 1);
    }

    if(num < 1000000)
        memo[num - 1] = result;

    return result;

}

int main() {

    for(int i = 0; i < 1000000; i++)
        memo[i] = 0;

    unsigned long longestChain = 0;
    int winner = 0;
    for(int i = 1; i < 1000000; i++) {
        if(collatz(i) > longestChain) {
            longestChain = collatz(i);
            winner = i;
        }
    }
    cout << "The number below 1,000,000 with the longest collatz series is " << winner << " with " << longestChain << " steps!\n";

    return 0;

}