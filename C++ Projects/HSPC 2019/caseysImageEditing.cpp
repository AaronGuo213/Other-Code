/*Casey has a square image made up of black and white pixels
represented as 0 and 1 respectively. As part of an image analysis
process, Casey needs to determine the size of the largest square area
of white pixels. Given a 2-dimensional square matrix that represents
the image, write a function to determine the length of a side of the
largest square area made up of white pixels.*/

#include <iostream>

using namespace std;

int main() {

    int n, m, answer = 0;
    cin >> n;
    cin >> m;
    bool unit[n][n];
    bool valid = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> unit[i][j];
    }

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n - i + 1; j++) {

            for(int k = 0; k < n - i + 1; k++) {

                for(int l = 0; l < i; l++) {

                    for(int m = 0; m < i; m++) {

                        if(!unit[j + l][k + m])
                            valid = false;

                    }

                }

                if(valid)
                    answer = i;

                valid = true;

            }

        }

    }

    cout << answer;

}