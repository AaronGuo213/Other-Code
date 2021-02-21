#include <iostream>
#include <vector>
using namespace std;

int findSpaceIndex(string fullName) {

    int length = fullName.length();
    for(int i = length-1; i >= 0; i--) {
        if(fullName.at(i) == ' ') {
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

int main() {

    vector<string> names = {};
    string input;
    getline(cin, input);
    while(input != "1") {
        names.push_back(input);
        getline(cin, input);
    }

    for(int i = 0; i < names.size(); i++) {
        names.at(i) = separate(names.at(i));
    }

    cout << "\n\n\n\n\n";
    for(int i = 0; i < names.size(); i++) {
        cout << names.at(i) << endl;
    }

}