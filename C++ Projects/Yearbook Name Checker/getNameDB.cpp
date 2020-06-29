#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {

    vector<vector<string>> nameDB = {
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {}
    };
    fstream inFile; //opens the text file with all the names
    inFile.open("C:\\Users\\13107\\Desktop\\Meaningful Stuff\\Vex and Code\\Other-Code\\C++ Projects\\Yearbook Name Checker\\theFile.txt");
    if(inFile) //checks if the file is available
        cout << "Get Ready For Greatness" << endl;
    else
        cout << "Okay go look at the path again" << endl;

    string currentName;
    while(getline(inFile, currentName)) { //sorts every name into their respective first letter
        int firstLetter = (int)(currentName.at(0));
        if(firstLetter < 97)
            firstLetter -= 65;
        else
            firstLetter -= 97;
        nameDB[firstLetter].push_back(currentName);
    }

    //prints out the 2D vector that can be used for the name checker!
    cout << "vector<vector<string>> nameDB = {" << endl;
    for(int i = 0; i < 26; i++) {

        cout << "    {";
        for(int j = 0; j < nameDB[i].size(); j++) {
            cout << "\"" + nameDB[i][j] + "\"";
            if(j != nameDB[i].size() - 1)
                cout << ", ";
        }
        cout << "}";
        if(i != 25)
            cout << ",";
        cout << endl;

    }
    cout << "};" << endl;

}