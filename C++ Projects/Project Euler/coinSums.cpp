#include <iostream>
using namespace std;

int main() {

    int values[] = {1, 2, 5, 10, 20, 50, 100, 200};
    int target = 200;
    int numWays[target + 1];
    for(int i = 0; i < target + 1; i++)
        numWays[i] = 0;
    numWays[0] = 1;

    for(int i = 0; i < 8; i++) {
        for(int j = values[i]; j <= target; j++) {
            numWays[j] += numWays[j - values[i]];
        }
    }

    cout << "The number of ways to make " << target << " is " << numWays[target] << ".\n";

}