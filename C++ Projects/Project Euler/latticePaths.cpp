#include <iostream>
using namespace std;

long long memo[21][21];

long long numPaths(int row, int column) {

    long long paths = 0;

    if(memo[row][column] != 0)
        paths = memo[row][column];

    else if(row == 20 && column == 20)
        paths = 0;

    else {

        if(row < 20) {
            paths += numPaths(row + 1, column);
        }

        if(column < 20) {
            paths += numPaths(row, column + 1);
        }

        if(column == 20 || row == 20)
            paths = 1;

        memo[row][column] = paths;

    }

    return paths;

}

int main() {

    for(int i = 0; i < 21; i++) {
        for(int j = 0; j < 21; j++) {
            memo[i][j] = 0;
        }
    }

    cout << "The number of ways to move down and right in a 20x20 grid is " << numPaths(0, 0) << ".\n";

    return 0;

}