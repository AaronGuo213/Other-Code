/*A palindrome is a word, phrase, or sequence that reads the
same backward as forward. For example, "madam" is the same
forward and backward. Given a string with characters, if we can construct a palindrome
using any permutation of all the characters in the string, return 1
as true, otherwise return 0 as false.*/

#include <iostream>
#include <string>

using namespace std;

int main() {

    bool answer = true;
    string suspect;
    cin >> suspect;
    for(int i = 0; i < suspect.length(); i++) {

        if(suspect.at(i) != suspect.at(suspect.length() - i - 1))
            answer = false;

    }

    cout << answer;

}