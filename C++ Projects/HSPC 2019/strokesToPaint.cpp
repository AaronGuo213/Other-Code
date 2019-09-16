/*Complete the function strokesRequired in the editor below. The
function must return an integer, the minimum number of strokes
required to paint the canvas.*/

#include <iostream>
#include <string>

using namespace std;

int main() {

    bool newStroke = true;
    int h, w, strokes = 0;
    cin >> h;
    string line[h];
    for(int i = 0; i < h; i++) 
        cin >> line[i];
    w = line[0].length();
    char unit[h + 2][w + 2], used[h + 2][w + 2];
    char suspect;

    for(int i = 0; i < h + 2; i++) {

        for(int j = 0; j < w + 2; j++) {

            unit[i][j] = 0;
            used[i][j] = 0;

        }

    }

    for(int i = 0; i < h; i++) {

        for(int j = 0; j < w; j++) {

            unit[i + 1][j + 1] = line[i].at(j);

        }

    }

    for(int i = 0; i < h; i++) {

        for(int j = 0; j < w; j++) {

            newStroke = true;
            used[i + 1][j + 1] = true;

            if(unit[i + 1][j + 1] == unit[i][j + 1] && !used[i][j + 1])
                newStroke = false;
            if(unit[i + 1][j + 1] == unit[i + 2][j + 1] && !used[i + 2][j + 1])
                newStroke = false;
            if(unit[i + 1][j + 1] == unit[i + 1][j + 2] && !used[i + 1][j + 2])
                newStroke = false;
            if(unit[i + 1][j + 1] == unit[i + 1][j] && !used[i + 1][j])
                newStroke = false;
            if(unit[i + 1][j + 1] == unit[i + 1][j] && unit[i + 1][j + 1] == unit[i + 2][j])
                newStroke = false;

            if(newStroke) {
                strokes++;
            }

        }

    }

    cout << strokes;

}