#include <iostream>
using namespace std;

int numWays(int stepSize[], int numOptions, int numSteps) {

    int ways[numSteps + 1];
    ways[0] = 1;
    for(int i = 1; i <= numSteps; i++) {
        ways[i] = 0;
        for(int j = 0; j < numOptions; j++) {
            if(i - stepSize[j] >= 0)
                ways[i] += ways[i - stepSize[j]];
        }
    }

    return ways[numSteps];

}

int main() {

    int stepSize[] = {1, 3, 5};
    int stepsToCover = 4;
    int size = sizeof(stepSize) / sizeof(stepSize[0]);
    int possibilities = numWays(stepSize, size, stepsToCover);
    cout << "Using steps of length ";
    for(int i = 0; i < size; i++) {
        if(size - i == 1)
            cout << " and ";
        if(size - i == 2)
            cout << stepSize[i];
        else
            cout << stepSize[i] << ", ";
    }
    cout << "the number of ways to climb " << stepsToCover << " steps is " << possibilities << ".\n";

}