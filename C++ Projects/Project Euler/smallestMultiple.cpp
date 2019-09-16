#include <iostream>
using namespace std;

int gcf(int small, int big) {

    if(big % small == 0)
        return small;

    else {
        int factor = 0;
        for(int i = 1; i <= small / 2; i++) {
            if(big % i == 0 && small % i == 0 && i > factor)
                factor = i;
        }
        return factor;
    }

}

int main() {

    int limit = 20;
    int answer = 1;
    for(int i = 1; i <= limit; i++) { 
        answer *= i / gcf(i, answer);
    }
    cout << "The smallest integer that is a multiple of every integer from 1 to " << limit << " is " << answer << ".\n";

}