#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int findSpaceIndex(string fullName) {

    int length = fullName.length();
    for(int i = length-1; i >= 0; i--) {
        if(fullName.at(i) == '\t' || fullName.at(i) == ' ') {
            return i;
        }
    }
    return 0;

}

string separate(string fullName) {

    int index = findSpaceIndex(fullName);
    string rtn = fullName.substr(0, index) + "\n" + fullName.substr(index+1, fullName.length());
    return rtn;

}

string format(string str) {
    string temp = str.substr(3);
    return separate(temp);
}

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
    inFile.open("C:\\Users\\13107\\Desktop\\Meaningful_Stuff\\Vex_and_Code\\Other_Code\\C++ Projects\\Yearbook\\Name Checker\\namesAndGrades.txt");
    if(inFile) //checks if the file is available
        cout << "Get Ready For Greatness" << endl;
    else
        cout << "Okay go look at the path again" << endl;

    string currentName;
    while(getline(inFile, currentName)) { //sorts every name into their respective first letter
        if(currentName.substr(0, 2) == "12") {
            cout << format(currentName) << endl;
        }
    }

    /*string txt = "";
    txt += "vector<vector<string>> nameDB = {\n";
    for(int i = 0; i < 26; i++) {

        txt += "\t{";
        for(int j = 0; j < nameDB[i].size(); j++) {
            txt += "\"" + nameDB[i][j] + "\"";
            if(j != nameDB[i].size() - 1)
                txt +=", ";
        }
        txt += "}";
        if(i != 25)
            txt += ",";
        txt += "\n";

    }
    txt += "};\n";
    //cout << txt;
    cout << "aaron\nguo";
    ofstream outFile;
    outFile.open("C:\\Users\\13107\\Desktop\\Meaningful_Stuff\\Vex_and_Code\\Other_Code\\C++ Projects\\Yearbook Name Checker\\nameDB.txt");
    outFile << txt;
    outFile.close();*/

}