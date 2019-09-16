/*You are an engineer at NASA. Given a 2 Dimensional map on the
elevation of the planet XC-0827A, and the size and the shape of a
spaceship, you have to find the best landing spot for the space ship!
In order to land the ship, you must find the lowest contiguous group of
tiles, that is, the group of tiles (at the same height and touching) that
collectively have the lowest elevation and can contain the spaceship.
You are provided with schematics of the ship, in form of an array of 0's
and 1's. (0's are empty spaces, and 1's are occupied).*/

#include <iostream>

using namespace std;

int main() {

    int rows, columns, width, height, altitude, optimal = 100;
    int coordinates[2] =  {0, 0};
    bool heightFound = false, valid = true;
    cin >> height;
    cin >> width;
    int ship[height][width];
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++)
            cin >> ship[i][j];
    }

    cin >> rows;
    cin >> columns;
    int terrain[rows][columns];
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++)
            cin >> terrain[i][j];
    }

    for(int i = 0; i < rows - height + 1; i++) {

        for(int j = 0; j < columns - width + 1; j++) {

            for(int k = 0; k < height; k++) {

                for(int l = 0; l < width; l++) {

                    if(ship[k][l] == 1) {

                        if(!heightFound) {
                            heightFound = true;
                            altitude = terrain[k + i][l + j];
                        }

                        else if(!terrain[k + i][l + j] == altitude)
                            valid = false;

                    }

                }

            }

            if(valid && altitude < optimal) {
                coordinates[0] = j;
                coordinates[1] = i;
                optimal = altitude;
            }

            heightFound = false;
            valid = true;

        }

    }

    cout << "{" << coordinates[0] << ", " << coordinates[1] << "}";

}