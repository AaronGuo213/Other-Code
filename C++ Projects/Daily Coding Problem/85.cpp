#include <iostream>
#include <string>
#include <vector>
using namespace std;
//ITS A WORK IN PROGRESS
int findVector(vector<char> vec, char goal) { //finds a certain char in a vector, or returns -1

    for(int i = 0; i < vec.size(); i++) {

        if(goal == vec[i])
            return i;

    }

    return -1;

}

vector<char> shiftRight(vector<char> map, char replacing, int position) { //shifts everything in a vector right

    char holder;
    char replacer = replacing;
    for(int i = position; i < map.size(); i++) { //starts at the position of the leftmost item being shifted

        holder = map[i];
        map[i] = replacer;
        replacer = holder;

    }
    map.push_back(replacer); //adds an extra space in the vector

    return map;

}

bool doesValidate(string directions[], int numDir) {

    vector<char> mapVert;
    for(int i = 0; i < numDir; i++) {

        if(findVector(mapVert, directions[i].at(0)) != -1)

    }

    vector<char> mapHoriz;
    for(int i = 0; i < numDir; i++) {



    }

    return true;

}

int main() {

    string directions[] = {"A N B", "B NE C", "C N A"};

}