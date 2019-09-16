#include <iostream>
#include <string>
using namespace std;

void readN(int n, string str) {

    for(int i = 0; i < n && i < str.length(); i++) { //reads the first n characters of a string
        cout << str.at(i);
    }

    cout << endl; //creates a new line

}

int main() {

    string str = "Hello World!";
    readN(4, str);

}