#include <iostream>
#include <string>
using namespace std;

string addLine(string output, string s, int start, int end) {

    for(int i = 0; i < end - start; i++) {
        output += s.at(start + i);
    }
    output += "\n";
    return output;

}

int main() {

    string s = "the quick brown fox jumps over the lazy dog";
    string output = "";
    int k = 10;
    int p = 0, n;
    while(p + k < s.length()) {

        n = p + k;
        while(n > p) {
            if(s.at(n) == ' ') {
                break;
            }
            else
                n --;
        }
        if(n == p) {
            cout << "null" << endl;
            return 0;
        }
        else
            output = addLine(output, s, p, n);
        p = n + 1;

    }
    output = addLine(output, s, p, s.length());
    cout << output;

}