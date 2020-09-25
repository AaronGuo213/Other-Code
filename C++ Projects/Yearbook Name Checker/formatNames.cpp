#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool isLineValid(string line) {

    if(line == "" || line.at(0) == '7' || line.at(0) == '8' || line.at(0) == '9' || line.at(0) == '1')
        return true;
    return false;

}

bool isALetter(char character) {

    if((int)character >= 65 && (int)character <= 90)
        return true;

    if((int)character >= 97 && (int)character <= 122)
        return true;

    if((int)character == 45 || (int)character == 39 || (int)character == 46)
        return true;

    return false;

}

string formatName(string name) {

    /*string firstName = "";
    string lastName = "";
    bool onFirstName = false;
    bool onLastName = false;
    int i;
    for(i = 0; i < name.length(); i++) {
        if(!onFirstName && isALetter(name.at(i))) {
            onFirstName = true;
        }
        if(onFirstName) {
            if(isALetter(name.at(i))) {
                firstName += name.at(i);
            }
            else {
                break;
            }
        }
    }
    for(; i < name.length(); i++) {
        if(!onLastName && isALetter(name.at(i))) {
            onLastName = true;
        }
        if(onLastName) {
            if(name.at(i) == ' ' && name.at(i-1) == ' ') {
                ;
            }
            else {
                lastName += name.at(i);
            }
        }
    }
    return firstName + " " + lastName;*/

    string rtn = "";
    bool onName = false;
    int i;
    for(i = 0; i < name.length(); i++) {
        if(!onName && isALetter(name.at(i))) {
            onName = true;
        }
        if(onName) {
            if(name.at(i) == '\t') {
                rtn += ' ';
            }
            else {
                rtn += name.at(i);
            }
        }
    }
    return rtn;

}

int main() {

    fstream inFile; //opens the text file with all the names
    inFile.open("C:\\Users\\13107\\Desktop\\Meaningful_Stuff\\Vex_and_Code\\Other_Code\\C++ Projects\\Yearbook Name Checker\\namesAndGrades.txt");
    if(inFile) //checks if the file is available
        cout << "File Found" << endl;
    else
        cout << "File Not Found" << endl;

    string allNames = "";
    string currentName;
    while(getline(inFile, currentName)) { //sorts every name into their respective first letter
        if(isLineValid(currentName)) {
            allNames += formatName(currentName) + "\n";
        }
    }
    ofstream outFile;
    outFile.open("C:\\Users\\13107\\Desktop\\Meaningful_Stuff\\Vex_and_Code\\Other_Code\\C++ Projects\\Yearbook Name Checker\\names.txt");
    outFile << allNames;
    outFile.close();

}