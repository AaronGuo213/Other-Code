#include <iostream>
using namespace std;

const int N = 3, M = 3;

int removeColumns(char grid[N][M]) {

    int count = 0;
    for(int i = 0; i < M; i++) {

        int prevVal = 0;
        for(int j = 0; j < N; j++) {

            if(prevVal > int(grid[j][i])) {
                count ++;
                break;
            }

            prevVal = int(grid[j][i]);

        }

    }

    return count;

}

int main() {

    char grid[N][M] = {{'c', 'b', 'a'},
                    {'d', 'a', 'f'},
                    {'g', 'h', 'i'}};

    cout << removeColumns(grid);

}