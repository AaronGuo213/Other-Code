#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int numWays[1000];
    for(int i = 0; i < 1000; i++)
        numWays[i] = 0;

    for(int i = 1; i < 1000; i++) {
        for(int j = i + 1; i + j < 1000; j++) {
            float hypotenuse = sqrt(i * i + j * j);
            if(abs(int(hypotenuse) - hypotenuse) == 0 && i + j + int(hypotenuse) < 1000)
                numWays[i + j + int(hypotenuse) - 1] ++;
        }
    }

    int bigNum = 0;
    int sumID;

    for(int i = 0; i < 1000; i++) {
        if(numWays[i] > bigNum) {
            bigNum = numWays[i];
            sumID = i + 1;
        }
    }
    cout << "The number less than or equal to 1000 that has the most integer right triangle perimeters is " << sumID << ".\n";

}