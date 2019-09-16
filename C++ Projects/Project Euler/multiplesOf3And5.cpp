#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int limit = 1000, sum = 0;
    
    for(int i = 1; i < limit; i++) {

        if(i % 3 == 0)
            sum += i;

        else if(i % 5 == 0)
            sum += i;

    }

    cout << sum;

}