/*Given an arbitrary ransom note string and another string containing
magazine letters, write a function that will return true if the ransom note
can be constructed from the magazine letters; otherwise, return false.
Each letter in the magazine string can only be used once in your ransom
note. Ignore all punctuation.*/

#include <iostream>
#include <string>

using namespace std;

int main() {

    int letter[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    string input, output;
    bool answer = true;

    getline(cin, output);
    getline(cin, input);

    for(int i = 0; i < output.length(); i++) {

        if(int(output.at(i)) > 96 && int(output.at(i)) < 123) {
            letter[int(output.at(i)) - 97] --;
        }

    }

    for(int i = 0; i < input.length(); i++) {

        if(int(input.at(i)) > 96 && int(input.at(i)) < 123) {
            letter[int(input.at(i)) - 97] ++;
        }

    }

    for(int i = 0; i < 26; i++) {
        if(letter[i] < 0)
            answer = false;
    }

    cout << answer << "\n";

}