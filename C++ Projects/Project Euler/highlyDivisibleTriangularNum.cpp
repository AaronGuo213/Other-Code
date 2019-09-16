#include <iostream>
using namespace std;

int numFactors(int num) {

    /*int factors = 1;
    int var[100000];
    for(int i = 0; i < 100000; i++) {
        var[i] = 0;
    }

    int suspect = 2;
    while(num > 1) {

        if(num % suspect != 0)
            suspect ++;

        else {
            num /= suspect;
            var[suspect] ++;
        }

    }

    for(int i = 0; i < 100000; i++)
        factors *= (var[i] + 1);

    return factors;*/

    int factors = 0, i;
    for(i = 1; i * i < num; i++) {

        if(num % i == 0)
            factors ++;

    }
    factors *= 2;
    if(num % i == 0)
        factors ++;
        
    return factors;

}

int main() {

    int factors = 0, triNum;
    for(int i = 1; factors <= 500; i++) {
        triNum = i * (i + 1) / 2;
        factors = numFactors(triNum);
    }
    cout << "The first triangular number with over 500 factors is " << triNum << ".\n";

}