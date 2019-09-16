/*Given an N by N 2-D array filled with 1's and 0's that are
representative of a map. 1's represent land and 0's represent
water.
Count the number of islands on the map, where islands are
described as groups of 1's adjacently connected (No diagonals)*/

#include <iostream>

using namespace std;

int main() {

    int n, m, islands = 0;
    bool newIsland = true;
    cin >> n;
    cin >> m;
    bool land[n][m], used[n + 2][m + 2];

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < m; j++) {

            cin >> land[i][j];

        }

    }

    
    for(int i = 0; i < n + 2; i++) {

        for(int j = 0; j < m + 2; j++) {

            used[i][j] = false;

        }

    }

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < m; j++) {

            if(land[i][j]) {

                newIsland = true;
                used[i + 1][j + 1] = true;
                if(used[i + 1][j + 2])
                    newIsland = false;
                if(used[i + 1][j])
                    newIsland = false;
                if(used[i + 2][j + 1])
                    newIsland = false;
                if(used[i][j + 1])
                    newIsland = false;
                if(newIsland)
                    islands++;

            }

        }

    }

    std::cout << islands;

}