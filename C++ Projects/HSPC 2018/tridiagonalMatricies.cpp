/*A matrix is Tridiagonal if only the diagonal, subdiagonal and
superdiagonal have non-zero elements. That is the diagonals can have
any element, but the off-diagonals can only be 0.
The diagonal refers to the elements along the diagonal line that travels
from top left to bottom right. The subdiagonal refers to the line of
elements directly under the diagonal in the same direction, while the
superdiagonal refers to the line of elements directly above the diagonal in
the same direction.
Now given an n x n matrix, return True if and only if the matrix
is Tridiagonal.*/

#include <iostream>

using namespace std;

int main() {

    bool answer = false;
    int rows, columns;
    cin >> rows;
    cin >> columns;
    int matrix[rows][columns];

    for(int i = 0; i < rows; i++) {

        for(int j = 0; j < columns; j++) {

            cin >> matrix[i][j];

        }

    }

    for(int i = 0; i < 2; i++) {

        for(int j = 0, k = i; j < rows && k < columns; j++, k++) {

            if(!matrix[j][k] == 0)
                answer = true;

        }

    }

    for(int j = 1, k = 0; j < rows && k < columns; j++, k++) {

        if(!matrix[j][k] == 0)
            answer = true;

    }

    for(int i = 2; i < columns; i++) {

        for(int j = 0, k = i; j < rows && k < columns; j++, k++) {

            if(!matrix[j][k] == 0)
                answer = false;

        }

    }

    for(int i = 2; i < rows; i++) {

        for(int j = i, k = 0; j < rows && k < columns; j++, k++) {

            if(!matrix[j][k] == 0)
                answer = false;

        }

    }

    cout << answer;

}