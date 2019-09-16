#include <iostream>
using namespace std;

const int numBishops = 4;

int numAttacks(int coords[numBishops][2]) {

    int num = 0;
    for(int i = 0; i < numBishops; i++) {

        for(int j = i + 1; j < numBishops; j++) {

            if(abs(coords[i][0] - coords[j][0]) == abs(coords[i][1] - coords[j][1]))
                num ++;

        }

    }

    return num;

}

int main() {

    int bishops[numBishops][2] = {{0, 0}, {1, 2}, {2, 2,}, {4, 0}};
    cout << numAttacks(bishops);

}