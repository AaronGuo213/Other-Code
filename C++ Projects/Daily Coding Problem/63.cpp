#include <iostream>
#include <string>
using namespace std;

const int m = 4, n = 4;

bool checkWord(char grid[m][n], string goal, int i, int j) {

    bool rtn = true;

    if(goal.at(1) == grid[i + 1][j]) {

        for(int a = 2; a < goal.length(); a++) {

            if(goal.at(a) != grid[i + a][j])
                rtn = false;

        }
                    
    }

    if(rtn)
        return rtn;

    if(goal.at(1) == grid[i][j + 1]) {

        for(int a = 2; a < goal.length(); a++) {

            if(goal.at(a) != grid[i][j + a])
                rtn = false;

        }
                    
    }

    return rtn;
    
}

bool wordSearch(char grid[m][n], string goal) {

    if(goal.length() < n && goal.length() < m)
        return false;

    if(goal.length() == 0)
        return true;

    for(int i = 0; i < m - goal.length() + 2; i++) {

        for(int j = 0; j < n - goal.length() + 2; j++) {

            if(goal.at(0) == grid[i][j]) {

                if(goal.length() == 1)
                    return true;

                else if(checkWord(grid, goal, i, j))
                    return true;

            }

        }

    }

    return false;

}

int main() {

    char grid[n][m] = {{'F', 'A', 'C', 'I'},
                      {'O', 'B', 'Q', 'P'},
                      {'A', 'N', 'O', 'B'},
                      {'N', 'A', 'S', 'S'}};
    string goal = "FOAM";
    cout << wordSearch(grid, goal);

}