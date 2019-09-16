#include <iostream>
using namespace std;

const int n = 9; //sodoku board is 9 by 9

/*bool usedInColumn(int board[n][n], int column, int num) {

    for(int i = 0; i < n; i++) {
        if(board[i][column] == num)
            return true;
    }
    return false;

}

bool usedInRow(int board[n][n], int row, int num) {

    for(int i = 0; i < n; i++) {
        if(board[row][i] == num)
            return true;
    }
    return false;

}*/

bool isSafe(int board[n][n], int row, int column, int num) {

    int i, j;
    for(i = 0; i < n; i++) {
        if(board[i][column] == num) //checks if the column does not have the number
            return false;
    }
    for(i = 0; i < n; i++) {
        if(board[row][i] == num) //checks if the row does not have the number
            return false;
    }
    int boxStartRow = row - row % 3;
    int boxStartCol = column - column % 3;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if(board[boxStartRow + i][boxStartCol + j] == num) //checks if the local 3x3 box does not have the number
                return false;
        }
    }
    if(board[row][column] == 0) //makes sure the spot is empty
        return true;

    return false;

}

bool findEmpty(int board[n][n], int &row, int &column) {

    for(row = 0; row < n; row++) {
        for(column = 0; column < n; column++) {
            if(board[row][column] == 0) //searches through every column of every row to find a 0, or empty slot
                return true;
        }
    }
    return false; //board is filled

}

bool sodokuSolver(int board[n][n]) {

    int row = 0, column = 0;
    if(!findEmpty(board, row, column))
        return true; //board completed

    for(int num = 1; num <= 9; num++) {

        if(isSafe(board, row, column, num)) {

            board[row][column] = num;

            if(sodokuSolver(board)) { //continues with the tentative solution attempt for the next empty slot
                return true;
            }

            board[row][column] = 0; //if the sodoku board does not work with the number, the slot is wiped clean for another number attempt

        }
    
    }
    return false;

}

void showBoard(int board[n][n]) {

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

}

void createBoard(int board[n][n]) {

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j]; //takes an input for every slot in the soduku board, 0s represent empty spots
        }
    }

}

int main() {

    int board[n][n];
    createBoard(board);

    if(sodokuSolver(board))
        showBoard(board);
    else
        cout << "No solution" << endl;

    return 0;

}